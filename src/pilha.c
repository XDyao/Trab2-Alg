#include <stdlib.h>
#include "../lib/pilha.h"

struct no{
    cadastro info;
    struct no *prox;
};

struct pilha{
    No_pilha *ini;
    int tam;
};

void cria_pilha(Pilha **p) {
    (*p)->tam = 0;
    *p = malloc(sizeof(Pilha));
    (*p)->ini = NULL;
    return;
}

void destroi_pilha(Pilha **p) {
    No_pilha *aux;

    while (!pilha_vazia(*p)) {
        aux = (*p)->ini;
        (*p)->ini = (*p)->ini->prox;
        free(aux);
    }

    free(*p);

    *p = NULL;
    return;
}

int pilha_vazia(Pilha *p) {
    return (p->ini == NULL);
}

void adiciona_pilha(Pilha *p, cadastro x) {
    No_pilha *aux = malloc(sizeof(No_pilha));
    aux->info = x;

    aux->prox = p->ini;
    p->ini = aux;
    p->tam++;
    return;
}

int tira_pilha(Pilha *p, cadastro *x) {
    No_pilha *aux;
    if (pilha_vazia(p))
        return 1;
    *x = p->ini->info;
    aux = p->ini;
    p->ini = p->ini->prox;
    free(aux);
    p->tam--;
    return 0;
}

int getTamPilha(Pilha *p){
    return (p->tam);
}
