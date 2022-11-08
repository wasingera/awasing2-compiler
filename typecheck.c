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
            result = type_create(TYPE_ARRAY, NULL, NULL);
            break;
        case EXPR_IDENT:
            result = type_copy(e->symbol->type);
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
    }

    return result;
}

void decl_typecheck(struct decl *d) {
    if (!d) return;

    if (d->value)
        expr_typecheck(d->value);

    // if (d->code)
    //     stmt_typecheck(d->code);

    decl_typecheck(d->next);
}
