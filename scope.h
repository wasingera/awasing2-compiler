#ifndef SCOPE_H
#define SCOPE_H

#include "hash_table.h"
#include "symbol.h"

struct scope {
    int which;
    struct hash_table* table;
    struct scope* next;
};

extern struct scope* scope_stack;

void scope_enter();
void scope_exit();
void scope_bind(const char* name, struct symbol* s);
int scope_level();

struct symbol* scope_lookup(const char* name);
struct symbol* scope_lookup_current(const char* name);

#endif
