#include "../lib/cadastro.h"

void set_cadastro(cadastro *carro, int plate, int in, int hours, int out){
    cadastro.placa = plate;
    cadastro.entrada = in;
    cadastro.n_horas = hours;
    cadastro.saida = out;
    return;
}
