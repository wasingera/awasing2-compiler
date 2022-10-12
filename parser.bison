%{
#include <stdio.h>

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
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

%%

program: decl_list
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
          | ARRAY OPEN_SQUARE expr_10 CLOSE_SQUARE type_param
          | ARRAY OPEN_SQUARE  CLOSE_SQUARE type_param
          ;

type_var: INTEGER
        | BOOLEAN
        | CHAR
        | STRING
        | AUTO
        | ARRAY OPEN_SQUARE expr_10 CLOSE_SQUARE type_var
        ;

stmt: if_stmt
    ;

other_stmt: RETURN expr_10 SEMICOLON
    | RETURN SEMICOLON
    | PRINT expr_list_e SEMICOLON
    | OPEN_CURLY stmt_list CLOSE_CURLY
    | expr_10 SEMICOLON
    | FOR OPEN_PAREN expr_or_e SEMICOLON expr_or_e SEMICOLON expr_or_e CLOSE_PAREN stmt
    | decl_var
    ;

/* condition: OPEN_PAREN expr_10 CLOSE_PAREN */
/*          ; */


if_stmt: matched_if_stmt
       | open_if_stmt
       ;

matched_if_stmt: IF OPEN_PAREN expr_10 CLOSE_PAREN matched_if_stmt ELSE matched_if_stmt
               | other_stmt
               ;

open_if_stmt: IF OPEN_PAREN expr_10 CLOSE_PAREN if_stmt
            | IF OPEN_PAREN expr_10 CLOSE_PAREN matched_if_stmt ELSE open_if_stmt
            ;

expr_or_e: expr_10
         | /* e */
         ;

stmt_list: stmt stmt_list
         | stmt
         ;

expr_10: expr_9 EQUALS expr_10
       | expr_9 QUESTION expr_10 COLON expr_10
       | expr_9
       ;

expr_9: expr_9 OR expr_8
      | expr_8
      ;

expr_8: expr_8 AND expr_7
      | expr_7
      ;

expr_7: expr_7 LT expr_6
      | expr_7 LE expr_6
      | expr_7 EE expr_6
      | expr_7 GE expr_6
      | expr_7 GT expr_6
      | expr_7 NE expr_6
      | expr_6
      ;

expr_6: expr_6 PLUS expr_5
      | expr_6 MINUS expr_5
      | expr_5
      ;

expr_5: expr_5 MULTIPLY expr_4
      | expr_5 DIVIDE expr_4
      | expr_5 REMAINDER expr_4
      | expr_4
      ;

expr_4: expr_3 EXP expr_4
      | expr_3
      ;

expr_3: MINUS expr_3
      | NOT expr_3
      | expr_2
      ;

expr_2: expr_2 INCREMENT
      | expr_2 DECREMENT
      | expr_1
      ;

expr_1: OPEN_PAREN expr_10 CLOSE_PAREN
      | func_call
      | array_subscript
      | atomic
      ;

func_call: IDENTIFIER OPEN_PAREN expr_list_e CLOSE_PAREN
         ;

array_subscript: IDENTIFIER bracket_set
               ;

bracket_set: OPEN_SQUARE expr_10 CLOSE_SQUARE bracket_set
           | OPEN_SQUARE expr_10 CLOSE_SQUARE
           ;

expr_list_e: expr_list
           | /* e */
           ;

expr_list: expr_10 COMMA expr_list
         | expr_10
         ;

atomic: INTEGER_LITERAL
      | BOOLEAN_LITERAL
      | CHAR_LITERAL
      | STRING_LITERAL
      | IDENTIFIER
      | OPEN_CURLY expr_list CLOSE_CURLY
      ;

%%

int yyerror (char *s) {
    fprintf (stdout, "parse error: %s\n", s);
}
