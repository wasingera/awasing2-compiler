/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_EOF = 258,
    ARRAY = 259,
    AUTO = 260,
    BOOLEAN = 261,
    CHAR = 262,
    ELSE = 263,
    FALSE = 264,
    FOR = 265,
    FUNCTION = 266,
    IF = 267,
    INTEGER = 268,
    PRINT = 269,
    RETURN = 270,
    STRING = 271,
    TRUE = 272,
    VOID = 273,
    WHILE = 274,
    INTEGER_LITERAL = 275,
    BOOLEAN_LITERAL = 276,
    CHAR_LITERAL = 277,
    STRING_LITERAL = 278,
    IDENTIFIER = 279,
    TOKEN_ERROR = 280,
    COMMENT = 281,
    SEMICOLON = 282,
    COLON = 283,
    QUESTION = 284,
    EQUALS = 285,
    GT = 286,
    GE = 287,
    LT = 288,
    LE = 289,
    EE = 290,
    NE = 291,
    AND = 292,
    OR = 293,
    INCREMENT = 294,
    DECREMENT = 295,
    OPEN_PAREN = 296,
    CLOSE_PAREN = 297,
    OPEN_SQUARE = 298,
    CLOSE_SQUARE = 299,
    OPEN_CURLY = 300,
    CLOSE_CURLY = 301,
    PLUS = 302,
    MINUS = 303,
    MULTIPLY = 304,
    DIVIDE = 305,
    REMAINDER = 306,
    EXP = 307,
    NOT = 308,
    COMMA = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "parser.bison" /* yacc.c:1909  */

    struct decl *decl;
    struct type *type;
    struct stmt *stmt;
    struct expr *expr;
    struct param_list *param_list;
    char* str;

#line 118 "tokens.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
