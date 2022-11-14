#include "scope.h"
#include <stdlib.h>

int resolve_error = 0;

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

    hash_table_delete(remove->table);
    free(remove);
}

int scope_level() {
    if (scope_stack->next) return 1;
    else return 0;
}

void scope_bind(const char* name, struct symbol* s) {
    s->which = scope_stack->which;

    if (s->type->kind != TYPE_FUNCTION && hash_table_insert(scope_stack->table, name, s) != 1) {
        printf("resolve error: %s is already defined in this scope\n", s->name);
        resolve_error = 1;
    }

    if (s->type->kind == TYPE_FUNCTION) {
        struct symbol* exists = hash_table_lookup(scope_stack->table, name);

        if (exists && exists->prototype == 0) {
            printf("resolve error: %s is already defined in this scope\n", s->name);
            resolve_error = 1;
        } else if (exists && exists->prototype == 1 && s->prototype == 0) {
            if (!type_equals(exists->type, s->type)) {
                printf("resolve error: %s has inconsistent parameters\n", s->name);
                resolve_error = 1;
            }
            exists->prototype = 0;
        } else if (!exists) {
            hash_table_insert(scope_stack->table, name, s);
        }
    }

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
    resolve_error = 1;

    return NULL;
}

struct symbol* scope_lookup_current(const char* name) {
    return hash_table_lookup(scope_stack->table, name);
}
