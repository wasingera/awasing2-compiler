#include "type.h"
#include "expr.h"
#include <stdlib.h>

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params ) {
    struct type* t = calloc(1, sizeof(struct type));

    t->kind = kind;
    t->subtype = subtype;
    t->params = params;

    return t;
}

struct type * type_create_function(type_t kind, struct param_list *params) {
    struct type* sub = type_create(kind, NULL, NULL);
    struct type* t = type_create(TYPE_FUNCTION, sub, params);

    return t;
}

struct type * type_create_array(struct expr* expr, struct type * subtype) {
    struct type* t = type_create(TYPE_ARRAY, subtype, NULL);
    t->expr = expr;

    return t;
}

void type_print(struct type* t) {
    if (!t) return;

    switch (t->kind) {
        case TYPE_VOID:
            printf("void");
            break;
        case TYPE_BOOLEAN:
            printf("boolean");
            break;
        case TYPE_CHAR:
            printf("char");
            break;
        case TYPE_INTEGER:
            printf("integer");
            break;
        case TYPE_STRING:
            printf("string");
            break;
        case TYPE_AUTO:
            printf("auto");
            break;
        case TYPE_FUNCTION:
            printf("function ");
            type_print(t->subtype);
            param_list_print(t->params);
            break;
        case TYPE_ARRAY:
            printf("array[");
            if (t->expr) expr_print(t->expr, NULL);
            printf("] ");
            type_print(t->subtype);
            break;
    }
}

int type_equals(struct type* a, struct type* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    if (a->kind == b->kind && type_equals(a->subtype, b->subtype)) {
        if (a->kind == TYPE_ARRAY && a->expr && b->expr && a->expr->literal_value != b->expr->literal_value
                && param_list_equals(a->params, b->params))
            return 0;
        return 1;
    }

    return 0;
}

struct type* type_copy(struct type* t) {
    if (!t) return NULL;

    struct type* new = type_create(t->kind, type_copy(t->subtype), param_list_copy(t->params));
    new->expr = t->expr;

    return new;
}

void type_delete(struct type* t) {
    if (!t) return;

    return;
}
