#include "tokens.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "expr.h"
#include "stmt.h"
#include "type.h"
#include "decl.h"
#include "scope.h"
#include "resolve.h"
#include "typecheck.h"
#include "codegen.h"

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyleng;

extern struct decl* root;
struct scope* scope_stack = NULL;

extern int resolve_error;
extern int typecheck_error;

typedef enum yytokentype token_t;

int scan(char* fName);
int parse(char* fName);
void print_token(token_t t);
char* parse_escape_codes();
int print(char* fName);
int resolve(char* fName);
int typecheck(char* fName);
int codegen(char* fName, char* fOut);

int main(int argc, char** argv) {

    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (!strcmp(argv[i], "-scan")) {
            return scan(argv[i+1]); 
        } else if (!strcmp(argv[i], "-parse")) {
            return parse(argv[i+1]);
        } else if (!strcmp(argv[i], "-print")) {
            return print(argv[i+1]);
        } else if (!strcmp(argv[i], "-resolve")) {
            return resolve(argv[i+1]);
        } else if (!strcmp(argv[i], "-typecheck")) {
            return typecheck(argv[i+1]);
        } else if (!strcmp(argv[i], "-codegen")) {
            return codegen(argv[i+1], argv[i+2]);
        }

    }

    return 0;
}

int open_file(char* fName) {
    if (!fName) {
        printf("Need a file to parse!\n");
        return 0;
    }

	yyin = fopen(fName,"r");
	if (!yyin) {
		printf("could not open %s!\n", fName);
		return 0;
	}

    return 1;
}

int codegen(char* fName, char* fOut) {
    if (!fOut) {
        printf("Need an output file!\n");
        return 1;
    }

    if (typecheck(fName) == 1) {
        return 1;
    }

    freopen(fOut, "w", stdout);
    decl_codegen(root, -1);

    return 0;
}

int typecheck(char* fName) {
    if (resolve(fName) == 1) {
        return 1;
    }

    decl_typecheck(root);

    return typecheck_error;
}

int resolve(char* fName) {
    if (!open_file(fName))
        return 1;

    if (yyparse() != 0) {
        printf("Parse failed: %s\n", yytext);
        return 1;
    }

    // enter the global scope
    scope_enter();
    decl_resolve(root);
    // leave global scope
    scope_exit();

    return resolve_error;
}

int print(char* fName) {
    if (!fName) {
        printf("Need a file to parse!\n");
        return 1;
    }

	yyin = fopen(fName,"r");
	if (!yyin) {
		printf("could not open %s!\n", fName);
		return 1;
	}

    if (yyparse() != 0) {
        printf("Parse failed: %s\n", yytext);
        return 1;
    }

    decl_print_list(root);

    return 0;
}

int parse(char* fName) {
    if (!fName) {
        printf("Need a file to parse!\n");
        return 1;
    }

	yyin = fopen(fName,"r");
	if (!yyin) {
		printf("could not open %s!\n", fName);
		return 1;
	}

    if (yyparse() == 0) {
        printf("Parse successful\n");
        return 0;
    } 

    printf("Parse failed: %s\n", yytext);
    return 1;
}

int scan(char* fName) {
    if (!fName) {
        printf("Need a file to scan!\n");
        return 1;
    }

	yyin = fopen(fName,"r");
	if (!yyin) {
		printf("could not open %s!\n", fName);
		return 1;
	}
	while (1) {
		token_t t = yylex();
        switch(t) {
            case TOKEN_EOF:
                return 0;
            case TOKEN_ERROR:
                printf("scan error: %s is not a valid token\n", yytext);
                return 1;
            case STRING_LITERAL:
                if (strlen(yytext) > 255) {
                    printf("scan error: %s is over max string length of 255 (%d)\n", yytext, strlen(yytext));
                    return 1;
                }
                break;
        }

        print_token(t);
	}

    return 0;
}

char* parse_escape_codes() {
    char* curr = yytext + 1;
    char* buf = malloc(sizeof(char) * yyleng);
    int i = 0;
    while (curr < (yytext + yyleng - 1)) {
        if (*curr == '\\') {
            char* next = curr + 1;
            if (*next == 'n') {
                buf[i] = '\n';
            } else if (*next == '0') {
                buf[i] = '\0';
            } else if (*next == 't') {
                buf[i] = '\t';
            } else {
                buf[i] = *next;
            }
            curr += 2;
        } else {
            buf[i] = *curr;
            curr++;
        }
        i++;
    }

    return buf;
}

void print_token(token_t t) {
    switch(t) {
        case TOKEN_EOF:
            printf("TOKEN_EOF %s\n", yytext);
            break;
        case ARRAY:
            printf("ARRAY %s\n", yytext);
            break;
        case AUTO:
            printf("AUTO %s\n", yytext);
            break;
        case BOOLEAN:
            printf("BOOLEAN %s\n", yytext);
            break;
        case CHAR:
            printf("CHAR %s\n", yytext);
            break;
        case ELSE:
            printf("ELSE %s\n", yytext);
            break;
        case FALSE:
            printf("FALSE %s\n", yytext);
            break;
        case FOR:
            printf("FOR %s\n", yytext);
            break;
        case FUNCTION:
            printf("FUNCTION %s\n", yytext);
            break;
        case IF:
            printf("IF %s\n", yytext);
            break;
        case INTEGER:
            printf("INTEGER %s\n", yytext);
            break;
        case PRINT:
            printf("PRINT %s\n", yytext);
            break;
        case RETURN:
            printf("RETURN %s\n", yytext);
            break;
        case STRING:
            printf("STRING %s\n", yytext);
            break;
        case TRUE:
            printf("TRUE %s\n", yytext);
            break;
        case VOID:
            printf("VOID %s\n", yytext);
            break;
        case WHILE:
            printf("WHILE %s\n", yytext);
            break;
        case INTEGER_LITERAL:
            printf("INTEGER_LITERAL %s\n", yytext);
            break;
        case BOOLEAN_LITERAL:
            printf("BOOLEAN_LITERAL %s\n", yytext);
            break;
        case CHAR_LITERAL: {
            char* s = parse_escape_codes();
            printf("CHAR_LITERAL %s\n", s);
            break;
        }
        case STRING_LITERAL: {
            char* c = parse_escape_codes();
            printf("STRING_LITERAL %s\n", c);
            free(c);
            break;
         }
        case IDENTIFIER:
            printf("IDENTIFIER %s\n", yytext);
            break;
        case TOKEN_ERROR:
            printf("TOKEN_ERROR %s\n", yytext);
            break;
        case COMMENT:
            printf("COMMENT %s\n", yytext);
            break;
        case SEMICOLON:
            printf("SEMICOLON %s\n", yytext);
            break;
        case COLON:
            printf("COLON %s\n", yytext);
            break;
        case QUESTION:
            printf("QUESTION %s\n", yytext);
            break;
        case EQUALS:
            printf("EQUALS %s\n", yytext);
            break;
        case GT:
            printf("GT %s\n", yytext);
            break;
        case GE:
            printf("GE %s\n", yytext);
            break;
        case LT:
            printf("LT %s\n", yytext);
            break;
        case LE:
            printf("LE %s\n", yytext);
            break;
        case EE:
            printf("EE %s\n", yytext);
            break;
        case NE:
            printf("NE %s\n", yytext);
            break;
        case AND:
            printf("AND %s\n", yytext);
            break;
        case OR:
            printf("OR %s\n", yytext);
            break;
        case INCREMENT:
            printf("INCREMENT %s\n", yytext);
            break;
        case DECREMENT:
            printf("DECREMENT %s\n", yytext);
            break;
        case OPEN_PAREN:
            printf("OPEN_PAREN %s\n", yytext);
            break;
        case CLOSE_PAREN:
            printf("CLOSE_PAREN %s\n", yytext);
            break;
        case OPEN_SQUARE:
            printf("OPEN_SQUARE %s\n", yytext);
            break;
        case CLOSE_SQUARE:
            printf("CLOSE_SQUARE %s\n", yytext);
            break;
        case OPEN_CURLY:
            printf("OPEN_CURLY %s\n", yytext);
            break;
        case CLOSE_CURLY:
            printf("CLOSE_CURLY %s\n", yytext);
            break;
        case PLUS:
            printf("PLUS %s\n", yytext);
            break;
        case MINUS:
            printf("MINUS %s\n", yytext);
            break;
        case MULTIPLY:
            printf("MULTIPLY %s\n", yytext);
            break;
        case DIVIDE:
            printf("DIVIDE %s\n", yytext);
            break;
        case REMAINDER:
            printf("REMAINDER %s\n", yytext);
            break;
        case EXP:
            printf("EXP %s\n", yytext);
            break;
        case NOT:
            printf("NOT %s\n", yytext);
            break;
        case COMMA:
            printf("NOT %s\n", yytext);
            break;
    }
}
