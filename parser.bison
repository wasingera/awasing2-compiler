%{
#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "stmt.h"

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

struct expr* root;

%}

%token TOKEN_EOF
%token ARRAY
%token AUTO
%token BOOLEAN
%token CHAR
%token ELSE
%token FALSE
%token FOR
%token FUNCTION
%token IF
%token INTEGER
%token PRINT
%token RETURN
%token STRING
%token TRUE
%token VOID
%token WHILE
%token INTEGER_LITERAL
%token BOOLEAN_LITERAL
%token CHAR_LITERAL
%token STRING_LITERAL
%token IDENTIFIER
%token TOKEN_ERROR
%token COMMENT
%token SEMICOLON
%token COLON
%token QUESTION
%token EQUALS
%token GT
%token GE
%token LT
%token LE
%token EE
%token NE
%token AND
%token OR
%token INCREMENT
%token DECREMENT
%token OPEN_PAREN
%token CLOSE_PAREN
%token OPEN_SQUARE
%token CLOSE_SQUARE
%token OPEN_CURLY
%token CLOSE_CURLY
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token REMAINDER
%token EXP
%token NOT
%token COMMA

%union {
    struct decl *decl;
    struct stmt *stmt;
    struct expr *expr;
}

/* %type <decl> decl_list decl_var decl_func */

%type <expr> expr_10 expr_9 expr_8 expr_7 expr_6 expr_5 expr_4 expr_3 expr_2 expr_1 atomic expr_list expr_list_e func_call ident_name condition expr_or_e array_subscript bracket_set

%type <stmt> stmt other_stmt if_stmt matched_if_stmt open_if_stmt stmt_list stmt_list_e

%%

program: expr_10 { root = $1; }
       | /* e */
       ;

decl_list: decl_var decl_list
         | decl_func decl_list
         | decl_var
         | decl_func
         ;

decl_var: IDENTIFIER COLON type_var SEMICOLON
        | IDENTIFIER COLON type_var EQUALS expr_10 SEMICOLON
        ;

decl_func: IDENTIFIER COLON FUNCTION type_func OPEN_PAREN param_list_e CLOSE_PAREN EQUALS OPEN_CURLY stmt_list CLOSE_CURLY
         | IDENTIFIER COLON FUNCTION type_func OPEN_PAREN param_list_e CLOSE_PAREN SEMICOLON
         ;

type_func: INTEGER
         | BOOLEAN
         | CHAR
         | STRING
         | VOID
         | AUTO
         | FUNCTION type_func
         ;

param_list_e: param_list
          | /* e */
          ;

param_list: IDENTIFIER COLON type_param COMMA param_list
          | IDENTIFIER COLON type_param
          ;

type_param: INTEGER
          | BOOLEAN
          | CHAR
          | STRING
          | AUTO
          | FUNCTION
          | ARRAY OPEN_SQUARE expr_10 CLOSE_SQUARE type_param
          | ARRAY OPEN_SQUARE  CLOSE_SQUARE type_param
          ;

type_var: INTEGER
        | BOOLEAN
        | CHAR
        | STRING
        | AUTO
        | ARRAY OPEN_SQUARE expr_10 CLOSE_SQUARE type_var
        | ARRAY OPEN_SQUARE CLOSE_SQUARE type_var
        ;

stmt: if_stmt { $$ = $1; }
    ;

other_stmt: RETURN expr_or_e SEMICOLON { $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL); }
    | PRINT expr_list_e SEMICOLON
    | OPEN_CURLY stmt_list_e CLOSE_CURLY
    | expr_10 SEMICOLON
    | decl_var
    ;

condition: OPEN_PAREN expr_10 CLOSE_PAREN { $$ = $2; }
         ;

if_stmt: matched_if_stmt
       | open_if_stmt
       ;

matched_if_stmt: IF condition matched_if_stmt ELSE matched_if_stmt
               | FOR OPEN_PAREN expr_or_e SEMICOLON expr_or_e SEMICOLON expr_or_e CLOSE_PAREN matched_if_stmt
               | other_stmt
               ;

open_if_stmt: IF condition if_stmt
            | IF condition matched_if_stmt ELSE open_if_stmt
            | FOR OPEN_PAREN expr_or_e SEMICOLON expr_or_e SEMICOLON expr_or_e CLOSE_PAREN open_if_stmt
            ;

expr_or_e: expr_10
         | /* e */
         ;

stmt_list_e: stmt_list
           | /* e */
           ;

stmt_list: stmt stmt_list
         | stmt
         ;

expr_10: expr_9 EQUALS expr_10 { $$ = expr_create(EXPR_ASSIGN, $1, $3); }
       | expr_9 QUESTION expr_10 COLON expr_10 { $$ = expr_create_ternary($1, $3, $5); }
       | expr_9 { $$ = $1; }
       ;

expr_9: expr_9 OR expr_8 { $$ = expr_create(EXPR_OR, $1, $3); }
      | expr_8 { $$ = $1; }
      ;

expr_8: expr_8 AND expr_7 { $$ = expr_create(EXPR_AND, $1, $3); }
      | expr_7
      ;

expr_7: expr_7 LT expr_6 { $$ = expr_create(EXPR_LT, $1, $3); }
      | expr_7 LE expr_6 { $$ = expr_create(EXPR_LE, $1, $3); }
      | expr_7 EE expr_6 { $$ = expr_create(EXPR_EE, $1, $3); }
      | expr_7 GE expr_6 { $$ = expr_create(EXPR_GE, $1, $3); }
      | expr_7 GT expr_6 { $$ = expr_create(EXPR_GT, $1, $3); }
      | expr_7 NE expr_6 { $$ = expr_create(EXPR_NE, $1, $3); }
      | expr_6 { $$ = $1; }
      ;

expr_6: expr_6 PLUS expr_5 { $$ = expr_create(EXPR_ADD, $1, $3); }
      | expr_6 MINUS expr_5 { $$ = expr_create(EXPR_SUB, $1, $3); }
      | expr_5 { $$ = $1; }
      ;

expr_5: expr_5 MULTIPLY expr_4 { $$ = expr_create(EXPR_MUL, $1, $3); }
      | expr_5 DIVIDE expr_4 { $$ = expr_create(EXPR_DIV, $1, $3); }
      | expr_5 REMAINDER expr_4 { $$ = expr_create(EXPR_MOD, $1, $3); }
      | expr_4 { $$ = $1; }
      ;

expr_4: expr_3 EXP expr_4 { $$ = expr_create(EXPR_EXP, $1, $3); }
      | expr_3 { $$ = $1; }
      ;

expr_3: MINUS expr_3 { $$ = expr_create(EXPR_NEG, NULL, $2); }
      | NOT expr_3 { $$ = expr_create(EXPR_NOT, NULL, $2); }
      | expr_2 { $$ = $1; }
      ;

expr_2: expr_2 INCREMENT { $$ = expr_create(EXPR_INCR, $1, NULL); }
      | expr_2 DECREMENT { $$ = expr_create(EXPR_DECR, $1, NULL); }
      | expr_1 { $$ = $1; }
      ;

expr_1: OPEN_PAREN expr_10 CLOSE_PAREN { $$ = $2; }
      | func_call { $$ = $1; }
      | array_subscript
      | atomic { $$ = $1; }
      ;

func_call: ident_name OPEN_PAREN expr_list_e CLOSE_PAREN { $$ = expr_create_func_call($1, $3); }
         ;

ident_name: IDENTIFIER { $$ = expr_create_name(yytext); }
         ;

array_subscript: ident_name bracket_set { $$ = expr_create_array_subscript($1, $2); }
               ;

bracket_set: OPEN_SQUARE expr_10 CLOSE_SQUARE bracket_set { $$ = expr_create_list($2, $4); }
           | OPEN_SQUARE expr_10 CLOSE_SQUARE { $$ = $2; }
           ;

expr_list_e: expr_list { $$ = $1; }
           | /* e */ { $$ = NULL; }
           ;

expr_list: expr_10 COMMA expr_list { $$ = expr_create_list($1, $3); printf("creating list\n"); }
         | expr_10 { $$ = $1; }
         ;

atomic: INTEGER_LITERAL { $$ = expr_create_integer_literal(atoi(yytext)); }
      | BOOLEAN_LITERAL { $$ = expr_create_boolean_literal(yytext); }
      | CHAR_LITERAL { $$ = expr_create_char_literal(parse_char(yytext)); }
      | STRING_LITERAL { $$ = expr_create_string_literal(parse_string(yytext)); }
      | ident_name { $$ = $1; }
      | OPEN_CURLY expr_list CLOSE_CURLY { $$ = expr_create_array_literal($2); }
      ;

%%

int yyerror (char *s) {
    fprintf (stdout, "parse error: %s\n", s);
}
