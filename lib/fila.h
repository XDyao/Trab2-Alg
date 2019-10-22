typedef struct Laco laco;

typedef struct fila Fila;

void cria_fila(Fila **f);
void esvazia_fila(Fila **f);
void adiciona_fila(Fila *f, elem x);
int tamanho_fila(Fila *f);
int remove_fila(Fila *f, elem *x);
int fila_vazia(Fila *f);
