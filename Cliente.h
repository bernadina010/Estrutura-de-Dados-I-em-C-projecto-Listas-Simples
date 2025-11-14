#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct cliente Cliente;

Cliente* cli_cria(int num, const char nome[], const char tel[], Data data_nasc);
void cli_mostra(const Cliente *c);
void cli_libera(Cliente *c);
int cli_numero(const Cliente* c);

// Compara a data de nascimento de dois clientes
// Retorna:
//   <0 se c1 for mais velho que c2
//    0 se tiverem a mesma data
//   >0 se c1 for mais novo que c2
int cli_compara_data(const Cliente *c1, const Cliente *c2);
#endif
