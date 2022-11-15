#include "param_list.h"
#include <stdlib.h>

struct param_list * param_list_create( char *name, struct type *type, struct param_list *next ) {
    struct param_list* p = calloc(1, sizeof(struct param_list));

    p->name = name;
    p->type = type;
    p->next = next;

    return p;
}

void param_list_print(struct param_list* params) {
    if (!params) {
        printf(" ()");
        return;
    }

    printf(" (");
    while (params->next) {
        param_print(params);
        printf(", ");
        params = params->next;
    }
    param_print(params);
    printf(")");
}

void param_print(struct param_list* param) {
    printf("%s: ", param->name);
    type_print(param->type);
}

int param_list_equals(struct param_list* p1, struct param_list* p2) {
    struct param_list* curr1 = p1;
    struct param_list* curr2 = p2;

    while (curr1 && curr2) {
        if (!type_equals(curr1->type, curr2->type))
            return 0;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if ((curr1 && !curr2) || (!curr1 && curr2))
        return 0;

    return 1;
}

struct param_list* param_list_copy(struct param_list* p) {
    if (!p) return NULL;

    struct param_list* curr = p;
    struct param_list* new = param_list_create(curr->name, type_copy(curr->type), NULL);
    struct param_list* curr_new = new;
    curr = curr->next;

    while (curr) {
        curr_new->next = param_list_create(curr->name, type_copy(curr->type), NULL);
        curr_new = curr_new->next;
        curr = curr->next;
    }

    return new;
}
