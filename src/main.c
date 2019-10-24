#include <stdio.h>
#include <stdlib.h>
#include "../lib/fila.h"
#include "../lib/pilha.h"
#include "../lib/cadastro.h"


void remove_expirados(Pilha *p, Fila *f, int in){
    if(!fila_vazia(f)){
        while((get_primeiro_fila((f)) <= in)){
            remove_fila(f);
        }
    }
    if(!pilha_vazia(p)){
        while((get_saida_primeiro(p) <= in)){
            tira_pilha(p);
        }
    }
    return;
}



int main(void){

    int plate, in, hours, out, desconto = 0;
    Fila **f = malloc(sizeof(Fila*));
    Pilha **p = malloc(sizeof(Pilha*));
    cria_fila(f);
    cria_pilha(p);
    int op, vector[3];

    do{
        printf("\t\t\tMENU DE OPCOES:\n");
        printf("1 - Registrar carro\t2 - Imprimir carros\t3 - Sair\n");
        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                for(int i=0; i<3; i++){
                    scanf("%d",&vector[i]);
                }
                plate = vector[0]; in = vector[1]; hours = vector[2];
                if( (in + hours) > 22 || (in <8) || (in>22) ){
                    printf("Fora do horario de funcionamento!\n");
                    break;
                }
                else if(encontra_elem_fila((*f),plate) || encontra_elem_pilha((*p),plate)){
                    printf("Este carro ja esta estacionado!\n");
                    break;
                }
                else if(fila_cheia((*f)) && pilha_cheia((*p))){
                    printf("Estacionamento lotado!\n");
                    break;
                }
                cadastro *carro = malloc(sizeof(carro));
                set_cadastro(carro, plate, in, hours, (in+hours), desconto);
                remove_expirados((*p), (*f), in);
                if( (pilha_vazia((*p)) && fila_vazia((*f))) || (pilha_vazia((*p)) && !fila_vazia((*f)))){
                    adiciona_pilha((*p),(*carro));
                }
                else if(!pilha_vazia((*p)) && fila_vazia((*f))){
                    adiciona_fila((*f),(*carro));
                }
                else if(!pilha_vazia((*p)) && !fila_vazia((*f))){
                    if(carro->saida <= get_saida_primeiro((*p))){
                        adiciona_pilha((*p),(*carro));
                    }
                    if(carro->saida >= get_ultimo_fila((*f))){
                        adiciona_fila((*f),(*carro));
                    }
                }
                break;
            case 2:
                printa_fila((*f),"FILA:\t\t\tCarro ", "Fila Vazia!\n");
                printa_pilha((*p),"PILHA:\t\t\tCarro ", "Pilha Vazia!\n");
                break;
            case 3:
                break;
            default:
                break;
        }
    }while(op != 3);
    esvazia_fila(f); destroi_pilha(p); free(f); free(p);
    return 0;
}
