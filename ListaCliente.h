#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H
#include "Cliente.h"

typedef struct no ListaCliente;

//Cria uma lista vazia
ListaCliente* list_cria();

//Cria um nó com um cliente
ListaCliente* no_cria(Cliente *c);

//Insere cliente no inicio da lsita
ListaCliente* cli_insere(ListaCliente* lista, Cliente *c);

//Remove cliente pelo num
ListaCliente* cli_remove(ListaCliente* lista, int num);

//Remove os clientes com mesmo ID (num)
ListaCliente* cli_remove_repetidos(ListaCliente *lista);

//Imprime os clientes com data de nascimento ordenada
void cli_listar_por_data(ListaCliente* lista);

//Lista todos os clientes
void cli_listar(ListaCliente* lista);

//Libera memória da lista
void list_libera(ListaCliente* lista);

#endif

