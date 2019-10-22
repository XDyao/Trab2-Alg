#include <stdlib.h>
#include <stdio.h>
#include "../lib/fila.h"
#include "../lib/cadastro.h"

struct Laco{
    cadastro info;
    struct Laco *prox;
};

struct fila {
    No *ini, *fim;
};

void cria_fila(Fila **f) {
    *f = malloc(sizeof(Fila));
    (*f)->ini = NULL;
    (*f)->fim = NULL;
    return;
}

void esvazia_fila(Fila **f) {
    No *aux;
    while ((*f)->ini != NULL) {
        aux = (*f)->ini;
        (*f)->ini = (*f)->ini->prox;
        free(aux);
    }
    free(*f);
    *f = NULL;
    return;
}

void adiciona_fila(Fila *f, elem x) {
    No *aux;
    aux = malloc(sizeof(No));
    aux->info = x;
    aux->prox = NULL;
    if (!fila_vazia(f))
        f->fim->prox = aux;
    f->fim = aux;
    if (fila_vazia(f))
        f->ini = aux;
    return;
}

int tamanho_fila(Fila *f) {
    No *aux = f->ini;
    int contagem = 0;
    while (aux != NULL) {
        contagem++;
        aux = aux->prox;
    }
    return contagem;
}

int remove_fila(Fila *f, elem *x) {
    No *aux;
    if (fila_vazia(f))
        return 1;
    *x = f->ini->info;
    aux = f->ini;
    f->ini = f->ini->prox;
    free(aux);
    return 0;
}

int fila_vazia(Fila *f) {
    return (f->ini == NULL);
}
