#include "cadastro.h"

void set_cadastro(cadastro *carro, int plate, int in, int hours, int out, int boolean){
    cadastro.placa = plate;
    cadastro.entrada = in;
    cadastro.n_horas = hours;
    cadastro.saida = out;
    cadastro.desconto = boolean;
    return;
}
