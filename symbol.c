#include "symbol.h"
#include <stdlib.h>

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name ) {
    struct symbol* s = malloc(sizeof(struct symbol));
    s->kind = kind;
    s->type = type;
    s->name = name;
    s->prototype = 0;
    s->which_local = 0;
    s->which_param = 0;
    return s;
}
