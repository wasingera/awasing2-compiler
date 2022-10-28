
#ifndef STMT_H
#define STMT_H

#include "decl.h"

typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK,
    STMT_LIST,
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next );
struct stmt * stmt_create_print(struct expr* expr);
struct stmt * stmt_create_block(struct stmt* s);
struct stmt * stmt_create_list(struct stmt* curr, struct stmt* next);
struct stmt * stmt_create_if(struct expr* condition, struct stmt* if_block, struct stmt* else_block);
struct stmt * stmt_create_for(struct expr* init, struct expr* condition, struct expr* next, struct stmt* body);

void stmt_print( struct stmt *s, int indent );
void stmt_print_val(struct stmt* s, int indent);
void stmt_print_list(struct stmt* s, int indent);
char* get_indent_string(int indent);
int get_indent_body(struct stmt* s);


#endif
