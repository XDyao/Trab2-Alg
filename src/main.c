#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/pilha.h"
#include "../lib/cadastro.h"

int main(void){

    int plate, in, hours, out, desconto = 0;
    Fila **f;
    Pilha **p;
    cria_fila(f);
    printf("DEU MERDA AQUI?\n");
    cria_pilha(p);
    int op;

    do{
        printf("MENU DE OPCOES:\n");
        printf("Digite 1 para registrar carro, 2 para imprimir carros, 3 para sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                scanf("%d %d %d %d", &plate, &in, &hours, &out);
                cadastro *carro = malloc(sizeof(carro));
                set_cadastro(carro, plate, in, hours, out, desconto);

                break;
            case 2:
                break;
            default:
                break;
        }
    }while(op != 3);
    





}
