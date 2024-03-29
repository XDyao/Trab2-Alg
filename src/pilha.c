#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    (*p) = malloc(sizeof(Pilha));
    (*p)->tam = 0;
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
    if(p->tam >= 5){
        return;
    }
    No_pilha *aux = malloc(sizeof(No_pilha));
    aux->info = x;
    aux->prox = p->ini;
    p->ini = aux;
    p->tam++;
    return;
}

int tira_pilha(Pilha *p) {
    No_pilha *aux;
    if (pilha_vazia(p))
        return 1;
    aux = p->ini;
    p->ini = p->ini->prox;
    free(aux);
    p->tam--;
    return 0;
}

int getTamPilha(Pilha *p){
    return (p->tam);
}

int encontra_elem_pilha(Pilha *p, int placa){
    if (pilha_vazia(p)){
        return 0;
    }
    No_pilha *aux;
    aux = p->ini;
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

int pilha_cheia(Pilha *p){
    if(p->tam >= 5){
        return 1;
    }
    return 0;
}

int get_saida_primeiro(Pilha *p){
    if(p->ini==NULL) return 26;
    return get_saida(&(p->ini->info));
    
}

void printa_pilha(Pilha *p, char sucesso[], char fracasso[]){
    No_pilha *aux;
    if (pilha_vazia(p)){
        printf("%s",fracasso);
        return;
    }
    aux = p->ini;
    int i = 1;
    while(aux != NULL){
        printf("%s%d:\n",sucesso,i);
        printa_cadastro(&(aux->info));
        i++;
        aux = aux->prox;
    }
    return;
}