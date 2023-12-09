// pesquisa.c

#include "pesquisa.h"
#include "veiculo.h"
#include "cliente.h"
#include <stdio.h>
#include <string.h>

void pesquisarCliente(Cliente clientes[], int totalClientes) {
    int opcao;
    printf("\n=== Pesquisa de Clientes ===\n");
    printf("1 - Pesquisar por código\n");
    printf("2 - Pesquisar por nome\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            {
                int codigo;
                printf("Digite o código do cliente: ");
                scanf("%d", &codigo);

                for (int i = 0; i < totalClientes; i++) {
                    if (clientes[i].codigo == codigo) {
                        exibirDetalhesCliente(clientes[i]);
                        return;
                    }
                }

                printf("Cliente não encontrado.\n");
            }
            break;

        case 2:
            {
                char nome[50];
                printf("Digite o nome do cliente: ");
                scanf("%s", nome);

                for (int i = 0; i < totalClientes; i++) {
                    if (strcmp(clientes[i].nome, nome) == 0) {
                        exibirDetalhesCliente(clientes[i]);
                        return;
                    }
                }

                printf("Cliente não encontrado.\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
    }
}

void pesquisarVeiculo(Veiculo veiculos[], int totalVeiculos) {
    int opcao;
    printf("\n=== Pesquisa de Veículos ===\n");
    printf("1 - Pesquisar por código\n");
    printf("2 - Pesquisar por placa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            {
                int codigo;
                printf("Digite o código do veículo: ");
                scanf("%d", &codigo);

                for (int i = 0; i < totalVeiculos; i++) {
                    if (veiculos[i].codigo == codigo) {
                        exibirDetalhesVeiculo(veiculos[i]);
                        return;
                    }
                }

                printf("Veículo não encontrado.\n");
            }
            break;

        case 2:
            {
                char placa[10];
                printf("Digite a placa do veículo: ");
                scanf("%s", placa);

                for (int i = 0; i < totalVeiculos; i++) {
                    if (strcmp(veiculos[i].placa, placa) == 0) {
                        exibirDetalhesVeiculo(veiculos[i]);
                        return;
                    }
                }

                printf("Veículo não encontrado.\n");
            }
            break;

        default:
            printf("Opção inválida.\n");
    }
}

