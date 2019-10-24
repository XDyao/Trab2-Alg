#include <stdio.h>
#include "../lib/cadastro.h"

void set_cadastro(cadastro *carro, int plate, int in, int hours, int out, int boolean){
    carro->placa = plate;
    carro->entrada = in;
    carro->n_horas = hours;
    carro->saida = out;
    carro->desconto = boolean;
    return;
}

void printa_cadastro(cadastro *c){
    printf("Placa:%d ; Horario Entrada:%d ; Horas de permanencia:%d ; Horario Saida:%d\n",c->placa,c->entrada,c->n_horas,c->saida);
    return;
}

int get_saida(cadastro *c){
    return c->saida;
}