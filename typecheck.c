#include "typecheck.h"
#include "type.h"

int typecheck_error = 0;

struct type* expr_typecheck(struct expr* e) {
    if (!e) return NULL;

    struct type* lt = expr_typecheck(e->left);
    struct type* mt = expr_typecheck(e->middle);
    struct type* rt = expr_typecheck(e->right);

    struct type* result;
    switch (e->kind) {
        case EXPR_INT_LITERAL:
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_STRING_LITERAL:
            result = type_create(TYPE_STRING, NULL, NULL);
            break;
        case EXPR_BOOL_LITERAL:
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_CHAR_LITERAL:
            result = type_create(TYPE_CHAR, NULL, NULL);
            break;
        case EXPR_ARRAY_LITERAL: {
            struct expr* curr = e->middle;
            struct type* array_type = expr_typecheck(curr->left);
            while (curr) {
                struct type* curr_type = expr_typecheck(curr->left);
                if (!type_equals(curr_type, array_type)) {
                    printf("type error: cannot have a ");
                    type_print(curr_type); printf(" ("); expr_print(curr->left, NULL); printf(") ");
                    printf("in an array of type "); type_print(array_type); printf("\n");
                    typecheck_error = 1;
                }
                curr = curr->middle;
            }

            int array_length = 0;
            curr = e->middle;
            while (curr) {
                array_length++;
                curr = curr->middle;
            }

            result = type_create(TYPE_ARRAY, type_copy(array_type), NULL);
            result->expr = expr_create_integer_literal(array_length);
            break;
         }
        case EXPR_IDENT:
            result = type_copy(e->symbol->type);
            break;
        case EXPR_ASSIGN:
            if (e->left->kind != EXPR_IDENT && e->left->kind != EXPR_ARRAY_SUBSCRIPT) {
                printf("type error: cannot assign a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")");
                printf(" to a constant ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")\n");
                typecheck_error = 1;
            }

            if (!type_equals(lt, rt)) {
                printf("type error: cannot assign a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")");
                printf(" to a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_copy(lt);
            break;
        case EXPR_TERNARY:
            if (lt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot use a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") in a ternary expression ");
                printf("(must be boolean)\n");
                typecheck_error = 1;
            }
            if (!type_equals(mt, rt)) {
                printf("type error: cannot return different types ");
                type_print(mt); printf(" ("); expr_print(e->middle, NULL); printf(") and ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") ");
                printf("in a ternary expression\n");
                typecheck_error = 1;
            }
            result = type_copy(mt);
            break;
        case EXPR_OR:
            if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot OR a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must both be boolean)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_AND:
            if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot AND a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must both be boolean)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_GE:
        case EXPR_GT:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot compare a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" to a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must both be integer)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_EE:
        case EXPR_NE:
            if (lt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY) {
                printf("type error: cannot use a ");
                type_print(lt); printf("("); expr_print(e->left, NULL); printf(")"); printf("in an equality test\n");
                typecheck_error = 1;
            }
            if (rt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY) {
                printf("type error: cannot use a ");
                type_print(rt); printf("("); expr_print(e->right, NULL); printf(")"); printf("in an equality test\n");
                typecheck_error = 1;
            }
            if (!type_equals(lt, rt)) {
                printf("type error: cannot compare a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" to a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be same type)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_ADD:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot add a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" to a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_SUB:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot subtract a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" from a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_MUL:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot multiply a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DIV:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot divide a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_MOD:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot mod a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_EXP:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot exponentiate a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NEG:
            if (rt->kind != TYPE_INTEGER) {
                printf("type error: cannot negate a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be integer)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NOT:
            if (rt->kind != TYPE_INTEGER) {
                printf("type error: cannot negate a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be boolean)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_INCR:
            if (lt->kind != TYPE_INTEGER) {
                printf("type error: cannot increment a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") (must be integer)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DECR:
            if (lt->kind != TYPE_INTEGER) {
                printf("type error: cannot decrement a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") (must be integer)\n");
                typecheck_error = 1;
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_FUNC_CALL: {
            struct param_list* params = e->left->symbol->type->params;
            struct expr* args = e->middle;
            param_list_typecheck(e->left->name, params, args);
            result = type_copy(e->left->symbol->type->subtype);
            break;
         }
        case EXPR_ARRAY_SUBSCRIPT: {
            int baseline;
            if (lt->kind != TYPE_ARRAY) {
                printf("type error: can't subscript a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")\n");
                typecheck_error = 1;
            }
            result = array_subscript_typecheck(e->middle, lt->subtype);
            break;
       }
    }

    return result;
}

struct type* array_subscript_typecheck(struct expr* index_list, struct type* type) {
    struct expr* curr_index = index_list;
    struct type* curr_type = type;
    struct type* prev_type = NULL;

    while (curr_index && curr_type) {
        struct type* index_type = expr_typecheck(curr_index->left);
        if (index_type->kind != TYPE_INTEGER) {
            printf("type error: can't use a ");
            type_print(index_type); printf(" ()"); expr_print(curr_index->left, NULL); printf("() ");
            printf("as an array index (must be integer)\n");
            typecheck_error = 1;
        }

        curr_index = curr_index->middle;
        prev_type = curr_type;
        curr_type = curr_type->subtype;
    }

    if (!curr_type && curr_index) {
        printf("type error: cannot index a ");
        type_print(prev_type);
        printf("\n");
        typecheck_error = 1;
    }

    return prev_type;
}

void param_list_typecheck(const char* f_name, struct param_list* params, struct expr* args) {
    struct param_list* curr_p = params;
    struct expr* curr_a = args;

    while (curr_p && curr_a) {
        struct type* type_a = expr_typecheck(curr_a->left);
        struct type* type_p = curr_p->type;
        if (!type_equals(type_p, type_a)) {
            printf("type error: passing ");
            type_print(type_a); printf(" ("); expr_print(curr_a->left, NULL); printf("), ");
            printf("expected "); type_print(type_p); printf(" to %s\n", f_name);
            typecheck_error = 1;
        }

        curr_p = curr_p->next;
        curr_a = curr_a->middle;
    }

    if (curr_p && !curr_a) {
        printf("type error: passed too few arguments to %s\n", f_name);
        typecheck_error = 1;
    } else if (!curr_p && curr_a) {
        printf("type error: passed too many arguments to %s\n", f_name);
        typecheck_error = 1;
    }
}

void decl_typecheck(struct decl *d)  {
    if (!d) return;

    // TODO: check array lengths
    if (d->value) {
        struct type* e_t = expr_typecheck(d->value);
        if (!type_equals(d->type, e_t) && d->type->kind != TYPE_AUTO) {
            printf("type error: cannot assign a ");
            type_print(e_t); printf(" ("); expr_print(d->value, NULL); printf(") ");
            printf("to a "); type_print(d->type); printf("\n");
            typecheck_error = 1;
        }

        if (d->type->kind == TYPE_AUTO) {
            d->type = type_copy(e_t);
            d->symbol->type = type_copy(e_t);
        }

        if (d->type->kind == TYPE_ARRAY) {
            struct type* curr = d->type;
            while (curr->kind == TYPE_ARRAY) {
                if (curr->expr->kind != EXPR_INT_LITERAL) {
                    printf("type error: must use integer literal in array size declaration, not ");
                    expr_print(curr->expr, NULL); printf("\n");
                    typecheck_error = 1;
                }
                curr = curr->subtype;
            }
        }
    }

    if (d->code)
        stmt_typecheck(d->code, d);

    decl_typecheck(d->next);
}

void stmt_typecheck(struct stmt* s, struct decl* func) {
    if (!s) return;
    struct type* f_type = func->symbol->type;

    struct type* t;
    switch (s->kind) {
        case STMT_DECL:
            decl_typecheck(s->decl);
            break;
        case STMT_EXPR:
            expr_typecheck(s->expr);
            break;
        case STMT_IF_ELSE:
            t = expr_typecheck(s->expr);
            if (t->kind != TYPE_BOOLEAN) {
                printf("type error: can't use "); type_print(t);
                printf(" ("); expr_print(s->expr, NULL); printf(") as a condition (need boolean)");
                typecheck_error = 1;
            }
            stmt_typecheck(s->body, func);
            stmt_typecheck(s->else_body, func);
            break;
        case STMT_FOR:
            expr_typecheck(s->init_expr);
            expr_typecheck(s->expr);
            expr_typecheck(s->next_expr);
            stmt_typecheck(s->body, func);
            break;
        case STMT_RETURN:
            t = expr_typecheck(s->expr);
            if (!t) t = type_create(TYPE_VOID, NULL, NULL);

            if (f_type->subtype->kind == TYPE_AUTO) {
                f_type->subtype = type_copy(t);
                func->type = type_copy(t);
            }

            if (!type_equals(f_type->subtype, t)) {
                printf("type error: cannot return a "); type_print(t);
                printf(" ("); expr_print(s->expr, NULL); printf(") in a function that returns ");
                type_print(f_type->subtype); printf("\n");
                typecheck_error = 1;
            }

            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, func);
            break;
        case STMT_PRINT:
            {
                struct expr* curr = s->expr;
                while (curr) {
                    expr_typecheck(curr->left);
                    curr = curr->middle;
                }
            }
            break;
    }

    stmt_typecheck(s->next, func);
}
