#include "../lib/cadastro.h"

typedef struct no No_pilha;
typedef struct pilha Pilha;

void cria_pilha(Pilha **p);
void destroi_pilha(Pilha **p);
int pilha_vazia(Pilha *p);
void adiciona_pilha(Pilha *p, cadastro x);
int tira_pilha(Pilha *p,  cadastro *x);
