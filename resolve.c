#include "resolve.h"
#include "scope.h"
#include "symbol.h"

void decl_resolve(struct decl* d) {
    if (!d) return;

    symbol_t kind = scope_level() > 0 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;

    d->symbol = symbol_create(kind, d->type, d->name);

    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);

    if (d->code) {
        scope_enter();
        param_list_resolve(d->type->params);
        scope_enter();
        stmt_resolve(d->code);
        scope_exit();
        scope_exit();
    }

    decl_resolve(d->next);
}

void param_list_resolve(struct param_list* p) {
    struct param_list* curr = p;
    while (curr) {
        p->symbol = symbol_create(SYMBOL_PARAM, p->type, p->name);
        scope_bind(p->name, p->symbol);
        curr = curr->next;
    }
}

void expr_resolve(struct expr* e) {
    if (!e) return;

    if (e->kind == EXPR_IDENT) {
        e->symbol = scope_lookup(e->name);
    } else {
        expr_resolve(e->left);
        expr_resolve(e->middle);
        expr_resolve(e->right);
        expr_resolve(e->next);
    }
}

void stmt_resolve(struct stmt* s) {
    if (!s) return;

    switch (s->kind) {
        case STMT_DECL:
            decl_resolve(s->decl);
            break;
        case STMT_EXPR:
            expr_resolve(s->expr);
            break;
        case STMT_IF_ELSE:
            expr_resolve(s->expr);
            stmt_resolve(s->body);
            stmt_resolve(s->else_body);
            break;
        case STMT_FOR:
            expr_resolve(s->init_expr);
            expr_resolve(s->expr);
            expr_resolve(s->next_expr);
            stmt_resolve(s->body);
            break;
        case STMT_PRINT:
            expr_resolve(s->expr);
            break;
        case STMT_RETURN:
            expr_resolve(s->expr);
            break;
        case STMT_BLOCK:
            scope_enter();
            stmt_resolve(s->body);
            scope_exit();
        case STMT_LIST:
            break; // skip this because we look at the next one anyways
    }
    // printf
    stmt_resolve(s->next);
}
