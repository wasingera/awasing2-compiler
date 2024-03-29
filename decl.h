
#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
	char *name;
	struct type *type;
	struct expr *value;
	struct stmt *code;
	struct symbol *symbol;
	struct decl *next;
    int param_count;
    int local_count;
};

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next );
struct decl * decl_create_list(struct decl* curr, struct decl* next);
struct decl * decl_create_func_body(char* name, struct type* type, struct stmt* s);
void decl_print( struct decl *d, int indent );
void decl_print_list(struct decl* d);

#endif


