#include "../lib/cadastro.h"

typedef struct Laco No_fila;

typedef struct fila Fila;

void cria_fila(Fila **f);
void esvazia_fila(Fila **f);
void adiciona_fila(Fila *f, cadastro x);
int tamanho_fila(Fila *f);
int remove_fila(Fila *f, cadastro *x);
int fila_vazia(Fila *f);
int encontra_elem_fila(Fila *f, int placa);
int fila_cheia(Fila *f);
int get_ultimo_fila(Fila *f);
void printa_fila(Fila *f, char sucesso[], char fracasso[]);