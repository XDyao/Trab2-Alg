#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/pilha.h"
#include "../lib/cadastro.h"

int main(void){

    int plate, in, hours, out, desconto = 0;
    Fila **f = malloc(sizeof(Fila*));
    Pilha **p = malloc(sizeof(Pilha*));
    cria_fila(f);
    cria_pilha(p);
    int op;

    do{
        printf("\t\t\tMENU DE OPCOES:\n");
        printf("1 - Registrar carro\t2 - Imprimir carros\t3 - Sair\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                scanf("%d %d %d", &plate, &in, &hours);
                if((in + hours) > 22){
                    printf("Digite um horario valido!\n");
                    break;
                }
                cadastro *carro = malloc(sizeof(carro));
                set_cadastro(carro, plate, in, hours, (in+hours), desconto);
                break;
            case 2:
                printa_fila((*f));
                printa_pilha((*p));
                break;
            default:
                break;
        }
    }while(op != 3);
    esvazia_fila(f); destroi_pilha(p); free(f); free(p);
    return 0;
}
