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
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER)
                printf("Type error on addition\n");
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;
        case EXPR_SUB:
            if (lt->kind != TYPE_INTEGER || rt->kind != TYPE_INTEGER)
                printf("Type error on subtraction\n");
            result = type_create(TYPE_INTEGER, NULL, NULL);
            break;

    }

    return result;
}

void decl_typecheck(struct decl *d) {
    if (!d) return;

    if (d->value && !type_equals(d->type, expr_typecheck(d->value)))
        printf("Type error on declaration\n");

    decl_typecheck(d->next);
}
