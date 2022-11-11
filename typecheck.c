#include "typecheck.h"
#include "type.h"

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
        case EXPR_ARRAY_LITERAL:
            // TODO: update this to copy subtype of arrays -- will need to update array literal creation
            result = type_create(TYPE_ARRAY, NULL, NULL);
            break;
        case EXPR_IDENT:
            result = type_copy(e->symbol->type);
            break;
        case EXPR_ASSIGN:
            if (!type_equals(lt, rt)) {
                printf("type error: cannot assign a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")");
                printf(" to a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")\n");
            }
            result = type_copy(lt);
            break;
        case EXPR_TERNARY:
            if (lt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot use a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") in a ternary expression ");
                printf("(must be boolean)\n");
            }
            if (!type_equals(mt, rt)) {
                printf("type error: cannot return different types ");
                type_print(mt); printf(" ("); expr_print(e->middle, NULL); printf(") and ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") ");
                printf("in a ternary expression\n");
            }
            result = type_copy(mt);
            break;
        case EXPR_OR:
            if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot OR a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must both be boolean)\n");
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_AND:
            if (lt->kind != TYPE_BOOLEAN || rt->kind != TYPE_BOOLEAN) {
                printf("type error: cannot AND a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must both be boolean)\n");
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
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_EE:
        case EXPR_NE:
            if (lt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY) {
                printf("type error: cannot use a ");
                type_print(lt); printf("("); expr_print(e->left, NULL); printf(")"); printf("in an equality test\n");
            }
            if (rt->kind == TYPE_VOID || lt->kind == TYPE_FUNCTION || lt->kind == TYPE_ARRAY) {
                printf("type error: cannot use a ");
                type_print(rt); printf("("); expr_print(e->right, NULL); printf(")"); printf("in an equality test\n");
            }
            if (!type_equals(lt, rt)) {
                printf("type error: cannot compare a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" to a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be same type)\n");
            }
            result = type_create(TYPE_BOOLEAN, NULL, NULL);
            break;
        case EXPR_ADD:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot add a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" to a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_SUB:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot subtract a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" from a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_MUL:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot multiply a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DIV:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot divide a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_MOD:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot mod a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_EXP:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER) {
                printf("type error: cannot exponentiate a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(")");
                printf(" and a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(")\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NEG:
            if (rt->kind != TYPE_INTEGER) {
                printf("type error: cannot negate a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be integer)\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_NOT:
            if (rt->kind != TYPE_INTEGER) {
                printf("type error: cannot negate a ");
                type_print(rt); printf(" ("); expr_print(e->right, NULL); printf(") (must be boolean)\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_INCR:
            if (lt->kind != TYPE_INTEGER) {
                printf("type error: cannot increment a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") (must be integer)\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_DECR:
            if (lt->kind != TYPE_INTEGER) {
                printf("type error: cannot decrement a ");
                type_print(lt); printf(" ("); expr_print(e->left, NULL); printf(") (must be integer)\n");
            }
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_FUNC_CALL: {
            struct param_list* params = e->left->symbol->type->params;
            struct expr* args = e->middle;
            param_list_typecheck(e->left->name, params, args);
            break;
         }
    }

    return result;
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
        }

        curr_p = curr_p->next;
        curr_a = curr_a->middle;
    }

    if (curr_p && !curr_a) {
        printf("type error: passed too few arguments to %s\n", f_name);
    } else if (!curr_p && curr_a) {
        printf("type error: passed too many arguments to %s\n", f_name);
    }
}

void decl_typecheck(struct decl *d)  {
    if (!d) return;

    if (d->value) {
        struct type* e_t = expr_typecheck(d->value);
        if (!type_equals(d->type, e_t)) {
            printf("type error: cannot assign a ");
            type_print(e_t); printf(" ("); expr_print(d->value, NULL); printf(") ");
            printf("to a "); type_print(d->type); printf("\n");
        }
    }

    if (d->code)
        stmt_typecheck(d->code, d->type);

    decl_typecheck(d->next);
}

void stmt_typecheck(struct stmt* s, struct type* f_type) {
    if (!s) return;

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
            }
            stmt_typecheck(s->body, f_type);
            stmt_typecheck(s->else_body, f_type);
            break;
        case STMT_FOR:
            expr_typecheck(s->init_expr);
            expr_typecheck(s->expr);
            expr_typecheck(s->next_expr);
            break;
        case STMT_RETURN:
            t = expr_typecheck(s->expr);
            if (!type_equals(f_type->subtype, t)) {
                printf("type error: cannot return a "); type_print(t);
                printf(" ("); expr_print(s->expr, NULL); printf(") in a function that returns ");
                type_print(f_type->subtype); printf("\n");
            }
            break;
        case STMT_BLOCK:
            stmt_typecheck(s->body, f_type);
            break;
        case STMT_PRINT:
            if (s->expr && s->expr->next) {
                struct expr* curr = s->expr->next;
                while (curr) {
                    expr_typecheck(curr);
                    curr = curr->next;
                }
            }
            break;
    }

    stmt_typecheck(s->next, f_type);
}
