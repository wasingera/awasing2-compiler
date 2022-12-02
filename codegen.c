#include "codegen.h"
#include "expr.h"
#include "typecheck.h"
#include <stdlib.h>

int num_args = 0;

void decl_codegen(struct decl* d, int segment) {
    if (!d) return;

    if (d->symbol->kind == SYMBOL_GLOBAL) {
        if (d->code) {
            num_args = d->param_count;
            if (segment != 0) {
                segment = 0;
                printf("\n.text\n");
            }
            printf(".global %s\n", d->name);
            printf("%s: \n", d->name);
            function_preamble_codegen(d);
            printf("\n");
            stmt_codegen(d->code, d);
            function_epilogue_codegen(d);

        } else {
            if (segment != 1) {
                segment = 1;
                printf("\n.data\n");
            }

            switch (d->type->kind) {
                case TYPE_INTEGER:
                case TYPE_BOOLEAN:
                case TYPE_CHAR:
                    if (d->value)
                        printf("%s: .quad %d\n", d->name, d->value->literal_value);
                    else
                        printf("%s: .quad 0\n", d->name);
                    break;
                case TYPE_STRING:
                    printf("%s: .string \"%s\"\n", d->name, expand_string(d->value->string_literal));
                    break;
                case TYPE_ARRAY:
                    printf("%s: ", d->name);
                    if (d->type->subtype->kind == TYPE_STRING) {
                        printf(".string "); expr_print(d->value->middle, NULL); printf("\n");
                    } else {
                        printf(".quad ");
                        struct expr* curr = d->value->middle;
                        while (curr && curr->middle) {
                            printf("%d, ", curr->left->literal_value);
                            curr = curr->middle;
                        }
                        if (curr) printf("%d", curr->left->literal_value);
                        printf("\n");
                    }
                    break;
            }
        }
    } else if (d->symbol->kind == SYMBOL_LOCAL) {
        if (!d->value)
            d->value = expr_create_integer_literal(0);
        expr_codegen(d->value);
        printf("MOVQ %s, %s\n", scratch_name(d->value->reg), symbol_codegen(d->symbol));
        scratch_free(d->value->reg);
    }

    decl_codegen(d->next, segment);
}

void function_preamble_codegen(struct decl* d) {
    printf("PUSHQ %%rbp\n"); // save base pointer
    printf("MOVQ %%rsp, %%rbp\n\n"); // set new base pointer

    // push function args onto stack
    char* arg_regs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
    for (int i = 0; i < d->param_count && i < 6; i++) {
        printf("PUSHQ %s\n", arg_regs[i]);
    }
    printf("\n");

    // allocate space for local variables
    printf("SUBQ $%d, %%rsp\n\n", 8*d->local_count);

    // callee saved registers
    printf("PUSHQ %%rbx\n");
    printf("PUSHQ %%r12\n");
    printf("PUSHQ %%r13\n");
    printf("PUSHQ %%r14\n");
    printf("PUSHQ %%r15\n");
}

void function_epilogue_codegen(struct decl* d) {
    printf("\n.%s_epilogue:\n", d->name);

    // restore stack
    printf("POPQ %%r15\n");
    printf("POPQ %%r14\n");
    printf("POPQ %%r13\n");
    printf("POPQ %%r12\n");
    printf("POPQ %%rbx\n");

    // restore base and stack pointers
    printf("MOVQ %%rbp, %%rsp\n");
    printf("POPQ %%rbp\n");

    // return to caller
    printf("RET\n\n");
}

void stmt_codegen(struct stmt* s, struct decl* func) {
    if (!s) return;

    switch (s->kind) {
        case STMT_RETURN:
            expr_codegen(s->expr);
            printf("MOVQ %s, %%rax\n", scratch_name(s->expr->reg));
            printf("JMP .%s_epilogue\n", func->name);
            scratch_free(s->expr->reg);
            break;
        case STMT_BLOCK:
            stmt_codegen(s->body, func);
            break;
        case STMT_EXPR:
            expr_codegen(s->expr);
            scratch_free(s->expr->reg);
            break;
        case STMT_DECL:
            decl_codegen(s->decl, 0);
            break;
        case STMT_PRINT:
            print_codegen(s);
            break;
        case STMT_IF_ELSE:
            if_else_codegen(s, func);
            break;
        case STMT_FOR:
            for_loop_codegen(s, func);
            break;
    }
    stmt_codegen(s->next, func);
}

void for_loop_codegen(struct stmt* s, struct decl* func) {
    if (s->init_expr) {
        expr_codegen(s->init_expr);
        scratch_free(s->init_expr->reg);
    }
    int top_label = label_create();
    int done_label = label_create();

    if (!s->expr) s->expr = expr_create_boolean_literal("true");

    printf("%s:\n", label_name(top_label));
    expr_codegen(s->expr);
    printf("CMP $0, %s\n", scratch_name(s->expr->reg));
    printf("JE %s\n", label_name(done_label));
    scratch_free(s->expr->reg);

    stmt_codegen(s->body, func);

    if (s->next_expr) {
        expr_codegen(s->next_expr);
        scratch_free(s->next_expr->reg);
    }

    printf("JMP %s\n", label_name(top_label));

    printf("%s:\n", label_name(done_label));
}

void if_else_codegen(struct stmt* s, struct decl* func) {
    struct expr* condition = s->expr;
    expr_codegen(condition);

    int false_label = label_create();
    int end_label = label_create();
    printf("CMP $0, %s\n", scratch_name(condition->reg));
    printf("JE %s\n", label_name(false_label));
    stmt_codegen(s->body, func);
    printf("JMP %s\n", label_name(end_label));
    printf("%s:\n", label_name(false_label));
    if (s->else_body) stmt_codegen(s->else_body, func);
    printf("%s:\n", label_name(end_label));

    scratch_free(condition->reg);
}

void print_codegen(struct stmt* s) {
    if (!s) return;

    struct expr* curr = s->expr;
    while (curr) {
        struct type* t = expr_typecheck(curr->left);
        type_t type = t->kind;

        struct expr* call;
        if (type == TYPE_INTEGER) {
            call = expr_create_func_call(expr_create_name("print_integer"), expr_create_func_args(curr->left, NULL));
        } else if (type == TYPE_STRING) {
            call = expr_create_func_call(expr_create_name("print_string"), expr_create_func_args(curr->left, NULL));
        } else if (type == TYPE_CHAR) {
            call = expr_create_func_call(expr_create_name("print_character"), expr_create_func_args(curr->left, NULL));
        } else if (type == TYPE_BOOLEAN) {
            call = expr_create_func_call(expr_create_name("print_boolean"), expr_create_func_args(curr->left, NULL));
        }
        expr_codegen(call);
        scratch_free(call->reg);
        curr = curr->middle;
    }
}

int label_counter = 0;
int label_create() {
    return label_counter++;
}

char* label_name(int l) {
    char* label = malloc(sizeof(char) * 6);
    sprintf(label, ".L%d", l);
    return label;
}

void expr_codegen(struct expr* e) {
    if (!e) return;

    switch (e->kind) {
        case EXPR_INT_LITERAL:
        case EXPR_BOOL_LITERAL:
        case EXPR_CHAR_LITERAL:
            e->reg = scratch_alloc();
            printf("MOVQ $%d, %s\n", e->literal_value, scratch_name(e->reg));
            break;
        case EXPR_STRING_LITERAL: {
            e->reg = scratch_alloc();
            int string_label = label_create();
            printf("\n.data\n%s: .string \"%s\"\n\n.text\n", label_name(string_label), expand_string(e->string_literal));
            printf("LEA %s, %s\n", label_name(string_label), scratch_name(e->reg));
            break;
          }
        case EXPR_IDENT:
            e->reg = scratch_alloc();
            if (e->symbol->kind == SYMBOL_GLOBAL && 
                    (e->symbol->type->kind == TYPE_ARRAY || e->symbol->type->kind ==TYPE_STRING)) {
                printf("LEA %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg));
            } else
                printf("MOVQ %s, %s\n", symbol_codegen(e->symbol), scratch_name(e->reg));
            break;
        case EXPR_ARRAY_SUBSCRIPT:
            array_subscript_codegen(e);
            break;
        case EXPR_ASSIGN: 
            assigment_codegen(e);
            break;
        case EXPR_TERNARY: {
            expr_codegen(e->left);
            expr_codegen(e->middle);
            expr_codegen(e->right);

            printf("CMP $0, %s\n", scratch_name(e->left->reg));
            int label_false = label_create();
            int label_end = label_create();
            printf("JE %s\n", label_name(label_false));
            printf("MOVQ %s, %s\n", scratch_name(e->middle->reg), scratch_name(e->left->reg));
            printf("JMP %s\n", label_name(label_end));
            printf("%s:\nMOVQ %s, %s\n", label_name(label_false), scratch_name(e->right->reg), scratch_name(e->left->reg));

            printf("%s:\n", label_name(label_end));

            scratch_free(e->middle->reg);
            scratch_free(e->right->reg);
            e->reg = e->left->reg;
            break;
           }
        case EXPR_OR:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ORQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_AND:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("ANDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_LT:
            comparison_codegen(e, "JL");
            break;
        case EXPR_LE:
            comparison_codegen(e, "JLE");
            break;
        case EXPR_EE:
            if (expr_typecheck(e->left)->kind != TYPE_STRING)
                comparison_codegen(e, "JE");
            else {
                struct expr* call = expr_create_func_call(expr_create_name("string_equals"),
                        expr_create_func_args(e->left, expr_create(EXPR_ARG, e->right, NULL)));
                expr_codegen(call);
                e->reg = call->reg;
            }

            break;
        case EXPR_GE:
            comparison_codegen(e, "JGE");
            break;
        case EXPR_GT:
            comparison_codegen(e, "JG");
            break;
        case EXPR_NE:
            comparison_codegen(e, "JNE");
            break;
        case EXPR_ADD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            e->reg = e->right->reg;
            printf("ADDQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->right->reg));
            scratch_free(e->left->reg);
            break;
        case EXPR_SUB:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("SUBQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));
            e->reg = e->left->reg;
            scratch_free(e->right->reg);
            break;
        case EXPR_MUL:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("IMULQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_DIV:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("CQO\n");
            printf("IDIVQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_MOD:
            expr_codegen(e->left);
            expr_codegen(e->right);
            printf("MOVQ %s, %%rax\n", scratch_name(e->left->reg));
            printf("CQO\n");
            printf("IDIVQ %s\n", scratch_name(e->right->reg));
            printf("MOVQ %%rdx, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            scratch_free(e->left->reg);
            break;
        case EXPR_EXP: {
            struct expr* call = expr_create_func_call(expr_create_name("integer_power"),
                    expr_create_func_args(e->left, expr_create(EXPR_ARG, e->right, NULL)));
            expr_codegen(call);
            e->reg = call->reg;
            break;
           }
        case EXPR_NEG:
            expr_codegen(e->right);
            printf("NEGQ %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            break;
        case EXPR_NOT:
            printf("MOVQ $0, %%rax\n");
            expr_codegen(e->right);
            printf("CMP $0, %s\n", scratch_name(e->right->reg));
            printf("SETZ %%al\n");
            printf("MOVQ %%rax, %s\n", scratch_name(e->right->reg));
            e->reg = e->right->reg;
            break;
        case EXPR_INCR:
            expr_codegen(e->left);
            e->reg = scratch_alloc();
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->reg));
            printf("INCQ %s\n", scratch_name(e->left->reg));
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol));
            scratch_free(e->left->reg);
            break;
        case EXPR_DECR:
            expr_codegen(e->left);
            e->reg = scratch_alloc();
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), scratch_name(e->reg));
            printf("DECQ %s\n", scratch_name(e->left->reg));
            printf("MOVQ %s, %s\n", scratch_name(e->left->reg), symbol_codegen(e->left->symbol));
            scratch_free(e->left->reg);
            break;
        case EXPR_FUNC_CALL:
            func_call_codegen(e);
            break;
    }
}

void assigment_codegen(struct expr* e) {
    e->reg = scratch_alloc();

    expr_codegen(e->right);
    if (e->left->kind == EXPR_ARRAY_SUBSCRIPT) {
        array_subscript_address_codegen(e->left);

        printf("MOVQ %s, (%s)\n", scratch_name(e->right->reg), scratch_name(e->left->reg));
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->reg));
    } else {
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), symbol_codegen(e->left->symbol));
        printf("MOVQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->reg));
    }
    scratch_free(e->left->reg);
    scratch_free(e->right->reg);
}

void array_subscript_address_codegen(struct expr* e) {
    struct expr* name = e->left;
    struct expr* index = e->middle;

    // get array address
    expr_codegen(name);

    // calculate offset
    struct expr* offset = expr_create(EXPR_MUL, index->left, expr_create_integer_literal(8));
    expr_codegen(offset);

    // add offset to array address
    printf("ADDQ %s, %s\n", scratch_name(offset->reg), scratch_name(name->reg));
    scratch_free(offset->reg);

    e->reg = name->reg;
    scratch_free(name->reg);

}

void array_subscript_codegen(struct expr* e) {
    // calculate address
    array_subscript_address_codegen(e);

    // load value stored at address
    printf("MOVQ (%s), %s\n", scratch_name(e->reg), scratch_name(e->reg));
}

void func_call_codegen(struct expr* e) {
    struct expr* name = e->left;
    struct expr* args = e->middle;

    // create result register
    e->reg = scratch_alloc();

    // evaluate all arguments
    struct expr* curr = args;
    int count = 0;
    while (curr) {
        expr_codegen(curr->left);
        curr = curr->middle;
        count++;
    }

    // load arguments into arg registers
    char* arg_regs[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};
    int i = 0;
    curr = args;
    while (i < 6 && curr) {
        struct expr* arg = curr->left;
        printf("MOVQ %s, %s\n", scratch_name(arg->reg), arg_regs[i]);
        scratch_free(arg->reg);
        curr = curr->middle;
        i++;
    }

    // save caller saved registers
    printf("PUSHQ %%r10\n");
    printf("PUSHQ %%r11\n");

    // call function
    printf("CALL %s\n", name->name);

    // unload caller saved registers
    printf("POPQ %%r11\n");
    printf("POPQ %%r10\n");

    // save result into scratch register
    printf("MOVQ %%rax, %s\n", scratch_name(e->reg));
}

void comparison_codegen(struct expr* e, char* type) {
    expr_codegen(e->left);
    expr_codegen(e->right);
    printf("CMPQ %s, %s\n", scratch_name(e->right->reg), scratch_name(e->left->reg));
    int cmp_label_true = label_create();
    int cmp_label_end = label_create();
    printf("%s %s\n", type, label_name(cmp_label_true));
    printf("MOVQ $0, %s\n", scratch_name(e->right->reg));
    printf("JMP %s\n", label_name(cmp_label_end));
    printf("%s:\nMOVQ $1, %s\n", label_name(cmp_label_true), scratch_name(e->right->reg));
    printf("%s:\n", label_name(cmp_label_end));

    e->reg = e->right->reg;
    scratch_free(e->left->reg);
}

int scratch_list[7] = {0};
int scratch_alloc() {
    int i = 0;
    while (i < 6 && scratch_list[i] != 0) {
        i++;
    }

    if (i == 6){
        fprintf(stderr, "error: out of registers\n");
        return -1;
    }
    else {
        scratch_list[i] = 1;
        return i;
    }
}

void scratch_free(int reg) {
    scratch_list[reg] = 0;
}

char* scratch_name(int reg) {
    char* name = malloc(sizeof(char) * 6);
    if (reg == 6)
        sprintf(name, "%%rbx");
    else
        sprintf(name, "%%r1%d", reg);

    return name;
}

char* symbol_codegen(struct symbol* s) {
    char* str = malloc(sizeof(char) * 10);
    switch (s->kind) {
        case SYMBOL_GLOBAL:
            return s->name;
        case SYMBOL_LOCAL:
            sprintf(str, "%d(%%rbp)", -8*(s->which_local + 1 + num_args));
            return str;
        case SYMBOL_PARAM:
            sprintf(str, "%d(%%rbp)", -8*(s->which_param + 1));
            return str;
    }

    return NULL;
}
