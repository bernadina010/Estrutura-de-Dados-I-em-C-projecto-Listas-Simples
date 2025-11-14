#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cliente
{
    int numero;
    char nome[50];
    char telefone[10];
    Data data_nasc;
};

Cliente *cli_cria(int num, const char nome[], const char tel[], Data data_nasc){
    Cliente *c = malloc(sizeof(struct cliente));
    if (c == NULL)
    {
        printf("Erro: memória insuficiente");
        exit(1);
    }
    
    c->numero = num;
    strcpy(c->nome, nome);
    c->nome[sizeof(c->nome)-1] = '\0';
    strcpy(c->telefone, tel);
    c->telefone[sizeof(c->telefone)-1] = '\0';
    c->data_nasc = data_nasc;
    return c;
}

//Mostra informações do Cliente
void cli_mostra(const Cliente *c){
    if (!c) return;

    printf("----- Dados do Cliente -----\n");
    printf("Nome: %s\n", c->nome);
    printf("Número: %d\n", c->numero);
    printf("Telefone: %s\n", c->telefone);
    printf("Data de nascimento: %02d/%02d/%04d\n", c->data_nasc.dia, c->data_nasc.mes, c->data_nasc.ano);
    printf("---------------------------------------\n\n");
}

int cli_numero(const Cliente* c){
    return c->numero;
}
void cli_libera(Cliente *c){
    if (!c) return;
    free(c);
}

int cli_compara_data(const Cliente *c1, const Cliente *c2){
     if (c1->data_nasc.ano != c2->data_nasc.ano)
        return c1->data_nasc.ano - c2->data_nasc.ano;

    if (c1->data_nasc.mes != c2->data_nasc.mes)
        return c1->data_nasc.mes - c2->data_nasc.mes;

    return c1->data_nasc.dia - c2->data_nasc.dia;

}