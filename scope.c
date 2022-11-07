#include "scope.h"
#include <stdlib.h>

void scope_enter() {
    struct scope* new = malloc(sizeof(struct scope));

    // push onto stack
    new->which = 0;
    new->table = hash_table_create(0,0);
    new->next = scope_stack;

    // now make stack point to top
    scope_stack = new;
}

void scope_exit() {
    struct scope* remove = scope_stack;

    scope_stack = scope_stack->next;

    free(remove);
}

int scope_level() {
    if (scope_stack->next) return 1;
    else return 0;
}

void scope_bind(const char* name, struct symbol* s) {
    s->which = scope_stack->which;
    if (hash_table_insert(scope_stack->table, name, s) != 1) 
        printf("resolve error: %s is already defined in this scope\n", s->name);
    scope_stack->which += 1;
}

struct symbol* scope_lookup(const char* name) {
    struct scope* curr = scope_stack;

    while (curr) {
        struct symbol* s = hash_table_lookup(curr->table, name);
        if (s) {
            if (s->kind == SYMBOL_GLOBAL) {
                printf("%s resolves to global %s\n", name, s->name);
            } else if (s->kind == SYMBOL_LOCAL) {
                printf("%s resolves to local %d\n", name, s->which);
            } else if (s->kind == SYMBOL_PARAM) {
                printf("%s resolves to param %d\n", name, s->which);
            }

            return s;
        }
        curr = curr->next;
    }
    printf("resolve error: %s is not defined\n", name);

    return NULL;
}

struct symbol* scope_lookup_current(const char* name) {
    return hash_table_lookup(scope_stack->table, name);
}
