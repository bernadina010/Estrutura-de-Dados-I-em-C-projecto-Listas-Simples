#include "ListaCliente.h"
#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    Cliente *dado;
    struct no* prox;
};

ListaCliente* list_cria(){
    return NULL;
}

ListaCliente* no_cria(Cliente *c){
    ListaCliente *novo = (ListaCliente*) malloc(sizeof(struct no));
    if (novo == NULL)
    {
        printf("Erro: memória insuficiente");
        exit(1);
    }
    novo->dado = c;
    novo->prox = NULL;

    return novo;
}

ListaCliente* cli_insere(ListaCliente* lista, Cliente* c){
    ListaCliente *novo = no_cria(c);
    novo->prox = lista;
    return novo;
}

ListaCliente* cli_remove(ListaCliente *lista, int num){
    ListaCliente *actual = lista;
    ListaCliente *anterior = NULL;

    while (actual!=NULL && cli_numero(actual->dado) != num)
    {
        anterior = actual;
        actual = actual->prox;
    }
    if (actual == NULL)
    {
        return lista;
    }
    if (anterior == NULL)
    {
        lista = actual->prox;
    }else
    {
        anterior->prox = actual->prox;
    }
    
    cli_libera(actual->dado);
    free(actual);

    return lista;
    
}
ListaCliente* cli_remove_repetidos(ListaCliente* lista){
    if (lista == NULL) return lista;

    ListaCliente *actual = lista;

    while (actual != NULL)
    {
        ListaCliente *anterior = actual;
        ListaCliente *corr = actual->prox;

        while (corr != NULL)
        {
            if (cli_numero(corr->dado) == cli_numero(actual->dado))
            {
                //remover corr
                anterior->prox = corr->prox;
                free(corr->dado);
                corr = anterior->prox;
            }else{
                anterior = corr;
                corr = corr->prox;

            }
            
        }
        actual = actual->prox;
    }
    return lista;
}

void cli_listar(ListaCliente* lista){
    ListaCliente* aux = lista;
    while (aux!=NULL)
    {
        cli_mostra(aux->dado);
        aux = aux->prox;
    }
    
}

void list_libera(ListaCliente* lista){
    ListaCliente* aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        cli_libera(aux->dado);
        free(aux);
    }
    
}

void cli_listar_por_data(ListaCliente* lista) {
    if (!lista) return;

    ListaCliente* ordenada = NULL; // lista temporária ordenada

    ListaCliente* aux = lista;
    while (aux != NULL) {
        Cliente* c = aux->dado;

        // Cria nó temporário para inserção
        ListaCliente* novo = (ListaCliente*) malloc(sizeof(struct no));
        if (!novo) {
            printf("Erro: memória insuficiente\n");
            exit(1);
        }
        novo->dado = c;
        novo->prox = NULL;

        // Insere em ordem na lista temporária
        if (!ordenada || cli_compara_data(c, ordenada->dado) < 0) {
            // Inserir no início
            novo->prox = ordenada;
            ordenada = novo;
        } else {
            ListaCliente* temp = ordenada;
            while (temp->prox && cli_compara_data(c, temp->prox->dado) < 0 == 0)
                temp = temp->prox;
            novo->prox = temp->prox;
            temp->prox = novo;
        }

        aux = aux->prox;
    }

    // Imprime a lista ordenada
    aux = ordenada;
    while (aux) {
        cli_mostra(aux->dado);
        aux = aux->prox;
    }

    // Libera nós temporários (não os clientes!)
    aux = ordenada;
    while (aux) {
        ListaCliente* temp = aux;
        aux = aux->prox;
        free(temp);
    }
}

