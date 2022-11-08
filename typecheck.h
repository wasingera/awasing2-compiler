#ifndef TYPECHECK_H
#define TYPECHECK_H

#include "expr.h"
#include "decl.h"

struct type* expr_typecheck(struct expr* e);
void decl_typecheck(struct decl* d);

#endif
