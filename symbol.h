
#ifndef SYMBOL_H
#define SYMBOL_H

#include "type.h"

typedef enum {
	SYMBOL_LOCAL,
	SYMBOL_PARAM,
	SYMBOL_GLOBAL
} symbol_t;

struct symbol {
	symbol_t kind;
	struct type *type;
	char *name;
    int prototype;
	int which;
    int which_param;
    int which_local;
};

struct symbol * symbol_create( symbol_t kind, struct type *type, char *name );

#endif
