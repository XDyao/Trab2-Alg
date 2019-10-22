typedef struct no No;

typedef struct pilha Pilha;

void cria_pilha(Pilha **p);
void destroi_pilha(Pilha **p);
int pilha_vazia(Pilha *p);
void adiciona_pilha(Pilha *p, elem x);
int tira_pilha(Pilha *p, elem *x);
