#include <stdlib.h>
#include <stdio.h>
#include "../lib/fila.h"


struct Laco{
    cadastro info;
    struct Laco *prox;
};

struct fila {
    No_fila *ini, *fim;
};

void cria_fila(Fila **f) {
    *f = malloc(sizeof(Fila));
    (*f)->ini = NULL;
    (*f)->fim = NULL;
    return;
}

void esvazia_fila(Fila **f) {
    No_fila *aux;
    while ((*f)->ini != NULL) {
        aux = (*f)->ini;
        (*f)->ini = (*f)->ini->prox;
        free(aux);
    }
    free(*f);
    *f = NULL;
    return;
}

void adiciona_fila(Fila *f, cadastro x) {
    No_fila *aux;
    aux = malloc(sizeof(No_fila));
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
    No_fila *aux = f->ini;
    int contagem = 0;
    while (aux != NULL) {
        contagem++;
        aux = aux->prox;
    }
    return contagem;
}

int remove_fila(Fila *f, cadastro *x) {
    No_fila *aux;
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
