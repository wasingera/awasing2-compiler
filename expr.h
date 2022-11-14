#ifndef EXPR_H
#define EXPR_H

#include "symbol.h"

typedef enum {
    EXPR_ASSIGN,
    EXPR_TERNARY,
    EXPR_OR,
    EXPR_AND,
    EXPR_LT,
    EXPR_LE,
    EXPR_EE,
    EXPR_GE,
    EXPR_GT,
    EXPR_NE,
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
    EXPR_MOD,
    EXPR_EXP,
    EXPR_NEG,
    EXPR_NOT,
    EXPR_INCR,
    EXPR_DECR,
    EXPR_IDENT,
    EXPR_INT_LITERAL,
    EXPR_STRING_LITERAL,
    EXPR_CHAR_LITERAL,
    EXPR_BOOL_LITERAL,
    EXPR_ARRAY_LITERAL,
    EXPR_FUNC_CALL,
    EXPR_ARG,
    EXPR_LIST,
    EXPR_INDEX,
    EXPR_ARRAY_SUBSCRIPT,

	/* many more kinds of exprs to add here */
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
    struct expr *middle;
	struct expr *right;

	/* used by various leaf exprs */
	const char *name;
	int literal_value;
	const char * string_literal;
	struct symbol *symbol;

    /* for an expr list */
    struct expr* next;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
struct expr* expr_create_list(struct expr* curr, struct expr* next);
struct expr * expr_create_ternary(struct expr* left, struct expr* middle, struct expr* right);

struct expr * expr_create_name( const char *n );
struct expr * expr_create_integer_literal( int c );
struct expr * expr_create_boolean_literal( char* c );
struct expr * expr_create_char_literal( char c );
struct expr * expr_create_string_literal( const char *str );
struct expr* expr_create_array_literal(struct expr* next);
struct expr * expr_create_func_call(struct expr*  name, struct expr* args);
struct expr* expr_create_func_args(struct expr* curr, struct expr* next);
struct expr * expr_create_array_subscript(struct expr* name, struct expr* bracket_set);
struct expr* expr_create_index_list(struct expr* curr, struct expr* next);

int get_expr_rank(struct expr* e);
void expr_print_val(struct expr* e);

char* parse_string(const char* str);
char parse_char(const char* str);
char* expand_char(const char c);
char* expand_string(const char* str);

void expr_print_array_literal(struct expr* e);
void expr_print_list(struct expr* e);
void expr_print( struct expr *e, struct expr* p);

#endif
