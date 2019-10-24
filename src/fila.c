#include <stdlib.h>
#include <stdio.h>
#include "../lib/fila.h"


struct Laco{
    cadastro info;
    struct Laco *prox;
};

struct fila {
    No_fila *ini, *fim;
    int tam;
};

void cria_fila(Fila **f) {
    (*f) = malloc(sizeof(Fila));
    (*f)->ini = NULL;
    (*f)->fim = NULL;
    (*f)->tam = 0;
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
    if(f->tam >= 10){
        return;
    }
    No_fila *aux;
    aux = malloc(sizeof(No_fila));
    aux->info = x;
    aux->prox = NULL;
    if (!fila_vazia(f))
        f->fim->prox = aux;
    f->fim = aux;
    if (fila_vazia(f))
        f->ini = aux;
    f->tam++;
    return;
}

int remove_fila(Fila *f) {
    No_fila *aux;
    if (fila_vazia(f))
        return 1;
    aux = f->ini;
    f->ini = f->ini->prox;
    free(aux);
    f->tam--;
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
        aux = aux->prox;
    }
    return 0;
}

int fila_cheia(Fila *f){
    if(f->tam >= 10){
        return 1;
    }
    return 0;
}

int get_ultimo_fila(Fila *f){
    return get_saida(&(f->fim->info));
}

int get_primeiro_fila(Fila *f){
    if(f->ini==NULL) return 26;
    return get_saida(&(f->ini->info));
}

No_fila *get_cadastro_primeiro_fila(Fila *f){
    return (f->ini);
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
        aux = aux->prox;
    }
    return;
}