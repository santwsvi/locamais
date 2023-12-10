// fidelidade.c

#include "fidelidade.h"
#include "locacao.h"
#include "cliente.h"
#include <stdio.h>

#define PONTOS_POR_DIA 10
#define PONTOS_PARA_PREMIO 500

void calcularPontosFidelidade(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes) {
    for (int i = 0; i < totalClientes; i++) {
        int pontos = 0;

        for (int j = 0; j < totalLocacoes; j++) {
            if (locacoes[j].codigo_cliente == clientes[i].codigo) {
                // Aqui, você deve usar o nome correto do membro na struct Locacao
                // Vamos supor que o nome do membro seja 'pontos_locacao'
                pontos += locacoes[j].pontosGanhos;
            }
        }

        // Aqui, você deve usar o nome correto do membro na struct Cliente
        // Vamos supor que o nome do membro seja 'pontos_fidelidade'
        clientes[i].pontosFidelidade = pontos;
    }
}


void premiarClientes(Cliente clientes[], int totalClientes) {
    printf("\nClientes premiados:\n");

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].pontosFidelidade >= PONTOS_PARA_PREMIO) {
            printf("Cliente %s atingiu %d pontos e será premiado com um kit da LocaMais!\n", clientes[i].nome, clientes[i].pontosFidelidade);
            // Lógica para entregar o kit ao cliente, se necessário.
            // ...
        }
    }
}

int verificarPontosCliente(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes, int codigoCliente) {
    int pontos = 0;

    for (int i = 0; i < totalLocacoes; i++) {
        if (locacoes[i].codigo_cliente == codigoCliente) {
            // Atualize os pontos com base nas locações do cliente
            pontos += locacoes[i].pontosGanhos;
        }
    }

    return pontos;
}

void menuPontosFidelidade(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes) {
    int opcao;

    do {
        printf("\n=== MENU FIDELIDADE ===\n");
        printf("1 - Visualizar pontos de um cliente\n");
        printf("2 - Visualizar clientes com 500 pontos para o kit\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    int codigoCliente;
                    printf("Digite o código do cliente: ");
                    scanf("%d", &codigoCliente);

                    int pontos = verificarPontosCliente(locacoes, totalLocacoes, clientes, totalClientes, codigoCliente);
                    printf("O cliente de código %d tem %d pontos no programa de fidelidade.\n", codigoCliente, pontos);
                }
                break;

            case 2:
                // Lógica para visualizar clientes com 500 pontos para o kit
                printf("Lista de clientes com 500 pontos para o kit:\n");
                for (int i = 0; i < totalClientes; i++) {
                    int pontos = verificarPontosCliente(locacoes, totalLocacoes, clientes, totalClientes, clientes[i].codigo);
                    if (pontos >= 500) {
                        printf("Código do cliente: %d\n", clientes[i].codigo);
                    }
                }
                break;

            case 3:
                printf("Voltando ao menu principal.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 3);
}
