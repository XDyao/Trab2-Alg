#include <stdio.h>
#include "../lib/fila.h"
#include "../lib/pilha.h"
#include "../lib/cadastro.h"

in main(void){

    int plate, in, hours, out;
    
    Fila **f;

    Pilha **p;

    cria_fila(f);

    cria pilha(p;);

    int op;

    do{
        printf("MENU DE OPCOES:\n");
        printf("Digite 1 para registrar carro, 2 para imprimir carros, 3 para sair\n");
        scanf("%d",&op);

        switch(op):
            case 1:
                scanf("%d %d %d %d", &plate, &in, &hours, &out);
                cadastro *carro = malloc(sizeof(carro));
                set_cadastro(carro, plate, in, hours, out);

                break;
            case 2:
                break;
            default:
                break;
    }while(op != 3);
    





}
