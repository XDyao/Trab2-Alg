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
    (*f) = malloc(sizeof(Fila));
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

int encontra_elem_fila(Fila *f, int placa){
    if (fila_vazia(f)){
        return 0;
    }
    No_fila *aux;
    aux = f->ini;
    int i = 1;
    while(aux != NULL){
        if(aux->info.placa == placa){
            return 1;
        }
        i++;
    }
    return 0;
}


void printa_fila(Fila *f, char sucesso[], char fracasso[]){
    No_fila *aux;
    if (fila_vazia(f)){
        printf("%s",fracasso);
        return;
    }
    aux = f->ini;
    int i = 1;
    while(aux != NULL){
        printf("%s%d:\n",sucesso,i);
        printa_cadastro(&(aux->info));
        i++;
    }
    return;
}