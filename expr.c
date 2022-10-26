#include "expr.h"
#include <stdlib.h>
#include <string.h>

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ) {
    struct expr* e = calloc(1, sizeof(struct expr));

    e->kind = kind;
    e->left = left;
    e->right = right;

    /* if (e->left) */
    /*     printf("%s\n", e->left->name); */

    return e;
}

struct expr * expr_create_ternary(struct expr* left, struct expr* middle, struct expr* right) {
    struct expr* e = expr_create(EXPR_TERNARY, left, right);
    
    e->middle = middle;

    return e;
}

struct expr* expr_create_array_literal(struct expr* next) {
    struct expr* e = expr_create(EXPR_ARRAY_LITERAL, NULL, NULL);
    struct expr* list = expr_create(EXPR_LIST, NULL, NULL);
    list->next = next;
    e->next = list;

    return e;
}

struct expr* expr_create_list(struct expr* curr, struct expr* next) {
    curr->next = next;

    return curr;
}

struct expr * expr_create_name( const char *n ) {
    struct expr* e = expr_create(EXPR_IDENT, NULL, NULL);
    char* s = malloc(strlen(n) * sizeof(char));
    strcpy(s, n);

    e->name = s;

    return e;
}

struct expr * expr_create_integer_literal( int c ) {
    struct expr* e = expr_create(EXPR_INT_LITERAL, NULL, NULL);

    e->literal_value = c;

    return e;
}

struct expr * expr_create_boolean_literal( char* c ) {
    struct expr* e = expr_create(EXPR_BOOL_LITERAL, NULL, NULL);

    if (strcmp(c, "true") == 0) {
        e->literal_value = 1;
    } else {
        e->literal_value = 0;
    }

    return e;
}

struct expr * expr_create_char_literal( char c ) {
    struct expr* e = expr_create(EXPR_CHAR_LITERAL, NULL, NULL);
    e->literal_value = c;

    return e;

}

struct expr * expr_create_string_literal( const char *str ) {
    struct expr* e = expr_create(EXPR_STRING_LITERAL, NULL, NULL);

    e->string_literal = str;

    return e;

}

struct expr * expr_create_func_call(struct expr*  name, struct expr* args) {
    struct expr* list = expr_create(EXPR_LIST, NULL, NULL);
    list->next = args;

    struct expr* e = expr_create(EXPR_FUNC_CALL, name, NULL);
    e->next = list;

    return e;
}

struct expr * expr_create_array_subscript(struct expr* name, struct expr* bracket_set) {
    struct expr* e = expr_create(EXPR_ARRAY_SUBSCRIPT, name, NULL);
    struct expr* list = expr_create(EXPR_LIST, NULL, NULL);
    list->next = bracket_set;

    e->next = list;
}

char parse_char(const char* str) {
    char buf;

    str++;
    const char* next = str + 1;

    if (*str == '\\')
        if (*next == 'n')
            buf = '\n';
        else if (*next == '0')
            buf = '\0';
        else
            buf = *next;
    else
        buf = *str;

    return buf;
}

char* parse_string(const char* str) {
    int len = strlen(str);
    char* buf = malloc(sizeof(char) * len);

    int i = 0;
    const char* curr = str + 1;
    while (curr < str + len - 1) {
        if (*curr == '\\') {
            const char* next = curr + 1;
            if (*next == 'n') {
                buf[i] = '\n';
            } else if (*next == '0') {
                buf[i] = '\0';
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

char* expand_char(const char c) {
    char* buf = malloc(sizeof(char) * 3);

    int i = 0;
    if (c == '\n') {
        buf[i++] = '\\';
        buf[i++] = 'n';
    } else if (c == '\0') {
        buf[i++] = '\\';
        buf[i++] = '0';
    } else {

        buf[i++] = c;
    }

    buf[i] = '\0';

    return buf;
}

char* expand_string(const char* str) {
    int len = strlen(str);
    char* buf = malloc(sizeof(char) * len*2);

    int i = 0;
    const char* curr = str;

    while (curr < str + len) {
        if (*curr == '\n') {
            buf[i++] = '\\';
            buf[i++] = 'n';
        } else if (*curr == '\0') {
            buf[i++] = '\\';
            buf[i++] = '0';
        } else {
            buf[i++] = *curr;
        }
        curr++;
    }

    buf[i] = '\0';

    return buf;
}

char* expand_bool(int v) {
    if (v)
        return "true";
    else
        return "false";
}

int parens_needed(struct expr* e, struct expr* p) {
    int p_rank = get_expr_rank(p);
    int e_rank = get_expr_rank(e);

    if (p_rank > 0 && e_rank > 0 && e_rank < p_rank)
        return 1;

    return 0;
}

void expr_print_bracket_set(struct expr* e) {
    if (!e || !e->next) return;

    struct expr* curr = e->next;
    while (curr) {
        printf("[");
        expr_print(curr, e);
        printf("]");
        curr = curr->next;
    }
}

void expr_print_list(struct expr* e) {
    if (!e || !e->next) return;

    struct expr* curr = e->next;

    while (curr->next) {
        expr_print(curr, e);
        printf(", ");
        curr = curr->next;
    }

    expr_print(curr, e);

}

void expr_print_array_literal(struct expr* e) {
    printf("{");

    expr_print_list(e->next);

    printf("}");
}

int get_expr_rank(struct expr* e) {
    if (!e) return -1;

    switch (e->kind) {
        case EXPR_ASSIGN:
        case EXPR_TERNARY:
            return 0;
        case EXPR_OR:
            return 1;
        case EXPR_AND:
            return 2;
        case EXPR_LT:
        case EXPR_LE:
        case EXPR_EE:
        case EXPR_GE:
        case EXPR_GT:
        case EXPR_NE:
            return 3;
        case EXPR_ADD:
        case EXPR_SUB:
            return 4;
        case EXPR_MUL:
        case EXPR_DIV:
        case EXPR_MOD:
            return 5;
        case EXPR_EXP:
            return 6;
        case EXPR_NEG:
        case EXPR_NOT:
            return 7;
        case EXPR_INCR:
        case EXPR_DECR:
            return 8;
    }

    return 0;
}

void expr_print(struct expr* e, struct expr* p) {
    if (!e) return;

    int parens = 0;
    if (parens_needed(e, p))
        parens = 1;

    if (parens)
        printf("(");

    expr_print(e->left, e);
    expr_print_val(e);
    expr_print(e->right, e);

    if (parens)
        printf(")");
}

void expr_print_val(struct expr* e) {
    switch (e->kind) {
        case EXPR_TERNARY:
            printf(" ? ");
            expr_print(e->middle, e);
            printf(" : ");
            break;
        case EXPR_ASSIGN:
            printf(" = ");
            break;
        case EXPR_OR:
            printf(" || ");
            break;
        case EXPR_AND:
            printf(" && ");
            break;
        case EXPR_LT:
            printf(" < ");
        case EXPR_LE:
            printf(" <= ");
            break;
        case EXPR_EE:
            printf(" == ");
            break;
        case EXPR_GE:
            printf(" >= ");
            break;
        case EXPR_GT:
            printf(" > ");
            break;
        case EXPR_NE:
            printf(" != ");
            break;
        case EXPR_ADD:
            printf(" + ");
            break;
        case EXPR_SUB:
            printf(" - ");
            break;
        case EXPR_MUL:
            printf(" * ");
            break;
        case EXPR_DIV:
            printf(" / ");
            break;
        case EXPR_MOD:
            printf(" %% ");
            break;
        case EXPR_EXP:
            printf(" ^ ");
            break;
        case EXPR_NEG:
            printf("-");
            break;
        case EXPR_NOT:
            printf("!");
            break;
        case EXPR_INCR:
            printf("++");
            break;
        case EXPR_DECR:
            printf("--");
            break;
        case EXPR_INT_LITERAL:
            printf("%d", e->literal_value);
            break;
        case EXPR_IDENT:
            printf("%s", e->name);
            break;
        case EXPR_CHAR_LITERAL:
            printf("'%s'", expand_char(e->literal_value));
            break;
        case EXPR_STRING_LITERAL:
            printf("\"%s\"", expand_string(e->string_literal));
            break;
        case EXPR_BOOL_LITERAL:
            printf("%s", expand_bool(e->literal_value));
            break;
        case EXPR_ARRAY_LITERAL:
            expr_print_array_literal(e);
            break;
        case EXPR_FUNC_CALL:
            printf("(");
            expr_print_list(e->next);
            printf(")");
            break;
        case EXPR_LIST:
            expr_print_list(e);
        case EXPR_ARRAY_SUBSCRIPT:
            expr_print_bracket_set(e->next);
    }
}
