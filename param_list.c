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
