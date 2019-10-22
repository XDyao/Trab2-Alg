#include "../lib/cadastro.h"

void set_cadastro(cadastro *carro, int plate, int in, int hours, int out, int boolean){
    carro->placa = plate;
    carro->entrada = in;
    carro->n_horas = hours;
    carro->saida = out;
    carro->desconto = boolean;
    return;
}
