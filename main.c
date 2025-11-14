#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "ListaCliente.h"

int main(void)
{
    ListaCliente *lista = list_cria();
    int op;
    do
    {
        system("clear");
        printf("*------------------------------------------------------------*\n");
        printf("*                    Menu - Lista de Clientes                *\n");
        printf("*------------------------------------------------------------*\n");
        printf("1 - Inserir Cliente\n2 - Remover Cliente\n3 - Listar Clientes\n4 - Remover Repetições\n5 - Listar por ordem de data de nascimento\n0 - Sair\n");
        printf("\nSua opção: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
        {
            int num;
            char nome[50], telefone[10];
            Data d;
            system("clear");
            printf("Nome: ");scanf(" %s", nome);getchar();
            printf("Número: ");scanf(" %d", &num); getchar();
            printf("Telefone: ");scanf(" %s", telefone); getchar();
            printf("Data de nascimento (dd mm aaaa): ");scanf("%d %d %d", &d.dia, &d.mes, &d.ano);getchar();

            Cliente* c = cli_cria(num, nome, telefone, d);
            lista = cli_insere(lista, c);

            printf("\nCliente inserido com sucesso!\n");
            printf("Pressione ENTER para continuar.");
            getchar();
            
            break;
        }
        case 2:
            {
            int num;
            system("clear");
            printf("Digite o número do cliente a remover: "); scanf("%d", &num);getchar();
            lista = cli_remove(lista, num);
            printf("Cliente removido com sucesso!\n");
            printf("\nPressione ENTER para continuar.");
            getchar();
            break;
            }
        case 3:
            system("clear");
            cli_listar(lista);
            printf("\nPressione ENTER para continuar.");
            getchar();
            break;
        case 4:
            system("clear");
            lista = cli_remove_repetidos(lista);
            printf("Repetições removidas com sucesso.\n");
            printf("Pressione ENTER para continuar!");
            getchar();
            break;
        case 5:
            system("clear");
            cli_listar_por_data(lista);
            printf("Pressione ENTER para continuar...");
            getchar();
            break;
        case 0:
            printf("Encerrando...");
            exit(1);
            break;
        default:
            printf("Erro: opção inválida.\nTente uma opção entre [0,5]");
            break;
        }
    } while (op != 0);

    list_libera(lista);

    return 0;
}