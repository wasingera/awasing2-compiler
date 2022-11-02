/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "stmt.h"
#include "decl.h"

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );

/* struct stmt* root; */
/* struct expr* root; */
struct decl* root;


#line 83 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
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
#line 71 "parser.bison" /* yacc.c:355  */

    struct decl *decl;
    struct type *type;
    struct stmt *stmt;
    struct expr *expr;
    struct param_list *param_list;
    char* str;

#line 187 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    98,    99,   100,   101,   104,   105,
     106,   109,   110,   113,   114,   115,   116,   117,   118,   119,
     122,   123,   126,   127,   130,   131,   132,   133,   134,   135,
     137,   140,   141,   142,   143,   144,   145,   149,   150,   151,
     152,   153,   154,   155,   160,   162,   163,   164,   165,   166,
     169,   172,   173,   176,   177,   178,   181,   182,   183,   186,
     187,   190,   191,   194,   195,   198,   199,   200,   203,   204,
     207,   208,   211,   212,   213,   214,   215,   216,   217,   220,
     221,   222,   225,   226,   227,   228,   231,   232,   235,   236,
     237,   240,   241,   242,   245,   246,   247,   248,   251,   254,
     256,   259,   260,   263,   264,   267,   268,   271,   272,   273,
     274,   275,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_EOF", "ARRAY", "AUTO", "BOOLEAN",
  "CHAR", "ELSE", "FALSE", "FOR", "FUNCTION", "IF", "INTEGER", "PRINT",
  "RETURN", "STRING", "TRUE", "VOID", "WHILE", "INTEGER_LITERAL",
  "BOOLEAN_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "TOKEN_ERROR", "COMMENT", "SEMICOLON", "COLON", "QUESTION", "EQUALS",
  "GT", "GE", "LT", "LE", "EE", "NE", "AND", "OR", "INCREMENT",
  "DECREMENT", "OPEN_PAREN", "CLOSE_PAREN", "OPEN_SQUARE", "CLOSE_SQUARE",
  "OPEN_CURLY", "CLOSE_CURLY", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "REMAINDER", "EXP", "NOT", "COMMA", "$accept", "program", "decl_list",
  "decl_var", "decl_func", "type_func", "param_list_e", "param_list",
  "type_param", "type_var", "type_var_undefined_array", "stmt",
  "other_stmt", "condition", "if_stmt", "matched_if_stmt", "open_if_stmt",
  "expr_or_e", "stmt_list_e", "stmt_list", "expr_10", "expr_9", "expr_8",
  "expr_7", "expr_6", "expr_5", "expr_4", "expr_3", "expr_2", "expr_1",
  "func_call", "ident_name", "array_subscript", "bracket_set",
  "expr_list_e", "expr_list", "atomic", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   -10,    38,  -160,   -21,   -21,    89,  -160,  -160,  -160,
      15,  -160,  -160,  -160,    65,  -160,  -160,    19,    33,     7,
      28,    28,    28,    65,    28,    28,    28,    47,  -160,    44,
      44,  -160,  -160,  -160,  -160,  -160,    44,   118,    44,    44,
      44,    29,    69,    51,   114,    56,    63,  -160,    23,    97,
    -160,  -160,     1,  -160,  -160,    11,  -160,  -160,  -160,    28,
    -160,  -160,  -160,  -160,    39,    74,    79,    88,    73,  -160,
    -160,  -160,  -160,  -160,  -160,   103,    87,  -160,  -160,   122,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,  -160,  -160,    44,    44,
    -160,   138,  -160,   100,  -160,    -8,  -160,  -160,  -160,     7,
      44,  -160,  -160,  -160,   139,  -160,    51,   114,    56,    56,
      56,    56,    56,    56,    63,    63,  -160,  -160,  -160,  -160,
     126,  -160,   127,   104,  -160,   128,   131,    44,    44,   145,
      -8,  -160,    -8,  -160,  -160,  -160,  -160,   129,   147,   132,
    -160,    44,  -160,   135,   137,  -160,  -160,  -160,  -160,  -160,
    -160,   130,    44,    44,    -8,   152,   154,  -160,   122,   140,
    -160,   -18,  -160,  -160,  -160,   118,  -160,  -160,   141,   158,
     156,   146,  -160,   179,  -160,  -160,  -160,   104,  -160,    44,
    -160,    -8,  -160,   162,  -160,  -160,    44,   148,    -8,  -160,
    -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     6,     7,     0,     1,     4,     5,
       0,    35,    32,    33,     0,    31,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,   107,   108,   109,   110,    99,     0,     0,     0,     0,
       0,     0,    67,    69,    71,    78,    81,    85,    87,    90,
      93,    95,   111,    96,    97,     0,    18,    14,    15,     0,
      13,    16,    17,    11,     0,     0,     0,     0,     0,    41,
      38,    39,    37,    40,    43,   106,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,   104,     0,
     100,     0,    21,     0,    19,     0,     9,    10,    94,     0,
       0,   112,    36,    42,     0,    65,    68,    70,    76,    75,
      72,    73,    74,    77,    79,    80,    82,    83,    84,    86,
       0,   103,     0,     0,    20,     0,     0,   104,    60,    99,
      62,    49,    64,    55,    44,    51,    52,     0,     0,     0,
     105,     0,    98,   102,     0,    28,    25,    26,    29,    24,
      27,    23,    60,     0,     0,     0,     0,    59,     0,     0,
      61,   106,    63,    12,    48,     0,    66,   101,     0,     0,
       0,     0,    56,    51,    46,    45,    47,     0,    22,    60,
      50,     0,    30,     0,    53,    57,    60,     0,     0,    54,
      58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,   136,    82,  -160,   168,     0,    13,     6,   115,
     -36,  -160,  -160,  -160,    31,  -159,  -157,  -139,  -160,   -86,
     -19,  -160,   116,   113,    67,    72,    66,   125,  -160,  -160,
    -160,  -160,  -160,    46,    60,   -90,  -160
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   141,     5,    27,    56,   103,   161,    17,
      18,   142,   143,   164,   144,   145,   146,   166,   169,   147,
     148,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   100,   130,    76,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    74,   135,     1,   136,   183,   137,   138,   131,   174,
      65,    66,    31,    32,    33,    34,   139,    67,     6,    75,
     150,    57,    58,   180,    60,    61,    62,    31,    32,    33,
      34,    35,   194,    36,   195,   101,   110,   140,     7,   199,
      39,   200,    98,   113,    99,    40,    28,   131,    36,    29,
     193,    37,    38,   102,   170,    39,   172,   197,    19,   104,
      40,   114,   115,    30,    31,    32,    33,    34,    35,    55,
      20,    21,    22,    79,    63,    95,    23,    64,    24,    75,
     132,    25,     4,    26,   105,    36,     4,     4,    83,    38,
     149,    75,    39,    10,    11,    12,    13,    40,    80,    81,
      14,   106,    15,    90,    91,    16,   107,    82,   154,   155,
     156,   157,    92,    93,    94,   158,   109,   159,    75,   167,
     160,   171,    68,    69,    70,    71,    10,    11,    12,    13,
     108,    72,   176,   111,    73,    15,    96,    97,    16,   113,
       8,     9,   134,   167,   181,    84,    85,    86,    87,    88,
      89,   118,   119,   120,   121,   122,   123,   110,   126,   127,
     128,   129,   124,   125,    77,    78,   133,   151,   152,   162,
     167,   153,   163,   168,   174,   173,   175,   167,    99,   184,
     178,   185,   101,   189,   179,   187,   186,   191,   190,   196,
     198,    59,   188,   192,   112,   182,   117,   165,   116,   177
};

static const yytype_uint8 yycheck[] =
{
      19,    37,    10,    24,    12,   164,    14,    15,    98,    27,
      29,    30,    20,    21,    22,    23,    24,    36,    28,    38,
     110,    21,    22,   162,    24,    25,    26,    20,    21,    22,
      23,    24,   191,    41,   191,    24,    54,    45,     0,   198,
      48,   198,    41,    79,    43,    53,    27,   137,    41,    30,
     189,    44,    45,    42,   140,    48,   142,   196,    43,    59,
      53,    80,    81,    30,    20,    21,    22,    23,    24,    41,
       5,     6,     7,    44,    27,    52,    11,    30,    13,    98,
      99,    16,     0,    18,    45,    41,     4,     5,    37,    45,
     109,   110,    48,     4,     5,     6,     7,    53,    29,    30,
      11,    27,    13,    47,    48,    16,    27,    38,     4,     5,
       6,     7,    49,    50,    51,    11,    43,    13,   137,   138,
      16,   140,     4,     5,     6,     7,     4,     5,     6,     7,
      42,    13,   151,    46,    16,    13,    39,    40,    16,   175,
       4,     5,    42,   162,   163,    31,    32,    33,    34,    35,
      36,    84,    85,    86,    87,    88,    89,    54,    92,    93,
      94,    95,    90,    91,    39,    40,    28,    28,    42,    41,
     189,    44,    41,    28,    27,    46,    44,   196,    43,    27,
      43,    27,    24,    27,    54,    44,    46,     8,    42,    27,
      42,    23,   179,   187,    79,   164,    83,   137,    82,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    56,    57,    58,    59,    28,     0,    57,    57,
       4,     5,     6,     7,    11,    13,    16,    64,    65,    43,
       5,     6,     7,    11,    13,    16,    18,    60,    27,    30,
      30,    20,    21,    22,    23,    24,    41,    44,    45,    48,
      53,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    91,    41,    61,    61,    61,    60,
      61,    61,    61,    27,    30,    75,    75,    75,     4,     5,
       6,     7,    13,    16,    65,    75,    90,    82,    82,    44,
      29,    30,    38,    37,    31,    32,    33,    34,    35,    36,
      47,    48,    49,    50,    51,    52,    39,    40,    41,    43,
      88,    24,    42,    62,    61,    45,    27,    27,    42,    43,
      54,    46,    64,    65,    75,    75,    77,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    81,    81,
      89,    90,    75,    28,    42,    10,    12,    14,    15,    24,
      45,    58,    66,    67,    69,    70,    71,    74,    75,    75,
      90,    28,    42,    44,     4,     5,     6,     7,    11,    13,
      16,    63,    41,    41,    68,    89,    72,    75,    28,    73,
      74,    75,    74,    46,    27,    44,    75,    88,    43,    54,
      72,    75,    69,    70,    27,    27,    46,    44,    62,    27,
      42,     8,    63,    72,    70,    71,    27,    72,    42,    70,
      71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    66,    67,    67,    67,    67,    67,
      68,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    83,    84,    84,    84,    84,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     4,     6,
       6,     5,     8,     2,     2,     2,     2,     2,     2,     3,
       3,     2,     5,     3,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     5,     1,     1,     1,
       1,     1,     5,     4,     1,     3,     3,     3,     2,     1,
       3,     1,     1,     5,     9,     1,     3,     5,     9,     1,
       0,     1,     0,     2,     1,     3,     5,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     3,     1,     2,     2,
       1,     2,     2,     1,     3,     1,     1,     1,     4,     1,
       2,     4,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 94 "parser.bison" /* yacc.c:1646  */
    { root = (yyvsp[0].decl); }
#line 1430 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "parser.bison" /* yacc.c:1646  */
    { root = NULL; }
#line 1436 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_list((yyvsp[-1].decl), (yyvsp[0].decl)); }
#line 1442 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_list((yyvsp[-1].decl), (yyvsp[0].decl)); }
#line 1448 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1454 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1460 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-3].str), (yyvsp[-1].type), NULL, NULL, NULL); }
#line 1466 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].str), (yyvsp[-3].type), (yyvsp[-1].expr), NULL, NULL); }
#line 1472 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].str), (yyvsp[-3].type), (yyvsp[-1].expr), NULL, NULL); }
#line 1478 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-4].str), (yyvsp[-1].type), NULL, NULL, NULL); }
#line 1484 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_func_body((yyvsp[-7].str), (yyvsp[-4].type), (yyvsp[-1].stmt)); }
#line 1490 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_INTEGER, (yyvsp[0].param_list)); }
#line 1496 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_BOOLEAN, (yyvsp[0].param_list)); }
#line 1502 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_CHAR, (yyvsp[0].param_list)); }
#line 1508 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_STRING, (yyvsp[0].param_list)); }
#line 1514 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 117 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_VOID, (yyvsp[0].param_list)); }
#line 1520 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_function(TYPE_AUTO, (yyvsp[0].param_list)); }
#line 1526 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-1].type), (yyvsp[0].param_list)); }
#line 1532 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 122 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[-1].param_list); }
#line 1538 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 123 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = NULL; }
#line 1544 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-4].str), (yyvsp[-2].type), (yyvsp[0].param_list)); }
#line 1550 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 127 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-2].str), (yyvsp[0].type), NULL); }
#line 1556 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 130 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1562 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 131 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1568 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 132 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHAR, NULL, NULL); }
#line 1574 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 134 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1586 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 135 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, NULL, NULL); }
#line 1592 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 137 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL); }
#line 1598 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1604 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 141 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1610 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 142 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHAR, NULL, NULL); }
#line 1616 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 143 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1622 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 144 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1628 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_array((yyvsp[-2].expr), (yyvsp[0].type)); }
#line 1634 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 149 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1640 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 150 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1646 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 151 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHAR, NULL, NULL); }
#line 1652 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 152 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1658 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1664 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 154 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_array((yyvsp[-2].expr), (yyvsp[0].type)); }
#line 1670 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 155 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_array(NULL, (yyvsp[0].type)); }
#line 1676 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1688 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_print((yyvsp[-1].expr)); }
#line 1694 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_block((yyvsp[-1].stmt)); }
#line 1700 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1706 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 166 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL, NULL, NULL, NULL); }
#line 1712 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1718 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 172 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1724 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 173 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1730 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 176 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_if((yyvsp[-3].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1736 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 177 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_for((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 1742 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 178 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1748 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 181 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_if((yyvsp[-1].expr), (yyvsp[0].stmt), NULL); }
#line 1754 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 182 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_if((yyvsp[-3].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1760 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 183 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_for((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 1766 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 186 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1772 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 187 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 1778 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 190 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1784 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 191 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = NULL; }
#line 1790 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 194 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_list((yyvsp[-1].stmt), (yyvsp[0].stmt)); }
#line 1796 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 195 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1802 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 198 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1808 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 199 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_ternary((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1814 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 200 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1820 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 203 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1826 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 204 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1832 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 207 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1838 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 208 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1844 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1850 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1856 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 213 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1862 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1868 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 215 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1874 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 216 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1880 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 217 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1886 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 220 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1892 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 221 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1898 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 222 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1904 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 225 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1910 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 226 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1916 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1922 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 228 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1928 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 231 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1934 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1940 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 235 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEG, NULL, (yyvsp[0].expr)); }
#line 1946 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 236 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT, NULL, (yyvsp[0].expr)); }
#line 1952 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 237 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1958 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 240 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_INCR, (yyvsp[-1].expr), NULL); }
#line 1964 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 241 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DECR, (yyvsp[-1].expr), NULL); }
#line 1970 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 242 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1976 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 245 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1982 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 246 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1988 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 247 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1994 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 248 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2000 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 251 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_func_call((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2006 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 254 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name((yyvsp[0].str)); }
#line 2012 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 256 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_array_subscript((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2018 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 259 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2024 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 260 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2030 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 263 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2036 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 264 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2042 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 267 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2048 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 268 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2054 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 271 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi((yyvsp[0].str))); }
#line 2060 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 272 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal((yyvsp[0].str)); }
#line 2066 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 273 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_char_literal(parse_char((yyvsp[0].str))); }
#line 2072 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 274 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(parse_string((yyvsp[0].str))); }
#line 2078 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 275 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2084 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 276 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_array_literal((yyvsp[-1].expr)); }
#line 2090 "parser.c" /* yacc.c:1646  */
    break;


#line 2094 "parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 279 "parser.bison" /* yacc.c:1906  */


int yyerror (char *s) {
    fprintf (stdout, "parse error: %s\n", s);
}
