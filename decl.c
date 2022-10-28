#include "decl.h"
#include <stdlib.h>

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ) {
    struct decl* d = calloc(1, sizeof(struct decl));

    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;

    return d;
}

struct decl * decl_create_list(struct decl* curr, struct decl* next) {
    curr->next = next;
    return curr;
}

struct decl * decl_create_func_body(char* name, struct type* type, struct stmt* code) {
    struct stmt* list = stmt_create(STMT_LIST, NULL, NULL, NULL, NULL, code, NULL, NULL);
    struct decl* d = decl_create(name, type, NULL, list, NULL);

    return d;
}

void decl_print_list(struct decl* d) {
    while (d->next) {
        decl_print(d, 0);
        d = d->next;
        printf("\n\n");
    }
    decl_print(d, 0);
}

void decl_print(struct decl* d, int indent) {
    if (!d) return;

    if (d->type->kind != TYPE_FUNCTION) {
        printf("%s: ", d->name);
        type_print(d->type);

        if (!d->value) {
            printf(";\n");
            return;
        }

        printf(" = ");
        expr_print(d->value, NULL);
        printf(";");
    } else {
        printf("%s: ", d->name);
        type_print(d->type);

        param_list_print(d->type->params);

        if (!d->code) {
            printf(";");
            return;
        }


        printf(" = {\n");
        stmt_print(d->code, 1);
        printf("\n}");
    }
}
