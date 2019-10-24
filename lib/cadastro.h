#ifndef CADASTRO
#define CADASTRO
//Updating

typedef struct elem{
    int placa;
    int entrada;
    int n_horas;
    int saida;
    int desconto;
}cadastro;

void set_cadastro(cadastro *carro, int plate, int in, int hours, int out, int boolean);
void printa_cadastro(cadastro *carro);
int get_saida(cadastro *carro);

#endif