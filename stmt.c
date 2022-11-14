#include "stmt.h"
#include "expr.h"
#include <stdlib.h>

struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ) {
    struct stmt* s = calloc(1, sizeof(struct stmt));

    s->kind      = kind;
    s->decl      = decl;
    s->init_expr = init_expr;
    s->expr      = expr;
    s->next_expr = next_expr;
    s->body      = body;
    s->else_body = else_body;
    s->next      = next;

    return s;
}

struct stmt * stmt_create_if(struct expr* condition, struct stmt* if_block, struct stmt* else_block) {
    struct stmt* s = stmt_create(STMT_IF_ELSE, NULL, NULL, condition, NULL, if_block, else_block, NULL);

    return s;
}

struct stmt * stmt_create_print(struct expr* list) {
    struct stmt* s = stmt_create(STMT_PRINT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    // struct expr* list = expr_create(EXPR_LIST, NULL, NULL);
    // list->next = expr;
    s->expr = list;

    return s;
}

struct stmt * stmt_create_list(struct stmt* curr, struct stmt* next) {
    curr->next = next;
    return curr;
}

struct stmt * stmt_create_block(struct stmt* list) {
    struct stmt* s = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, list, NULL, NULL);

    return s;
}

struct stmt * stmt_create_for(struct expr* init, struct expr* condition, struct expr* next, struct stmt* body) {
    struct stmt* s = stmt_create(STMT_FOR, NULL, init, condition, next, body, NULL, NULL);

    return s;
}

void stmt_print(struct stmt *s, int indent) {
    stmt_print_val(s, indent);
}

void stmt_print_list(struct stmt* s, int indent) {
    if (!s) return;

    struct stmt* curr = s;
    while (curr->next) {
        stmt_print(curr, indent);
        curr = curr->next;
    }
    stmt_print(curr, indent);
}

char* get_indent_string(int indent) {
    if (indent <= 0) return "";

    char* indent_string = malloc(sizeof(char) * indent*4);
    int i = 0;
    for (i = 0; i < indent*4; i++) {
        indent_string[i] = ' ';
    }
    indent_string[i] = '\0';

    return indent_string;
}

int get_indent_body(struct stmt* s) {
    if (s->kind == STMT_BLOCK) return 0;
    return 1;
}

void stmt_print_val(struct stmt* s, int indent) {
    char* indent_string = get_indent_string(indent);

    switch (s->kind) {
        case STMT_RETURN:
            printf("%sreturn ", indent_string);
            expr_print(s->expr, NULL);
            printf(";\n");
            break;
        case STMT_PRINT:
            printf("%sprint ", indent_string);
            expr_print(s->expr, NULL);
            printf(";\n");
            break;
        case STMT_EXPR:
            printf("%s", indent_string);
            expr_print(s->expr, NULL);
            printf(";\n");
            break;
        case STMT_BLOCK:
            printf("%s{\n", indent_string);
            stmt_print_list(s->body, indent+1);
            printf("%s}\n", indent_string);
            break;
        case STMT_IF_ELSE:
            printf("%s", indent_string);
            printf("if ("); expr_print(s->expr, NULL); printf(")\n");

            stmt_print(s->body, indent + get_indent_body(s->body));

            if (s->else_body) {
                printf("%selse\n", indent_string);
                stmt_print(s->else_body, indent + get_indent_body(s->else_body));
            }
            break;
        case STMT_FOR:
            printf("%s", indent_string);
            printf("for ("); expr_print(s->init_expr, NULL); printf("; ");
            expr_print(s->expr, NULL); printf("; "); expr_print(s->next_expr, NULL); printf(")\n");
            stmt_print(s->body, indent + get_indent_body(s->body));
            break;
        case STMT_DECL:
            printf("%s", indent_string);
            decl_print(s->decl, indent);
            printf("\n");
            break;
        case STMT_LIST:
            stmt_print_list(s->next, indent);
            break;
    }
}
