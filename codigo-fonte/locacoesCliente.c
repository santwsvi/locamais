// locacoesCliente.c

#include "locacoesCliente.h"
#include "cliente.h"
#include <stdio.h>

void mostrarLocacoesCliente(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes) {
    int codigoCliente;
    int encontrou = 0;

    // Solicitar ao usuário o código ou nome do cliente
    printf("Digite o código do cliente: ");
    scanf("%d", &codigoCliente);

    // Procurar o cliente pelo código
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            encontrou = 1;
            printf("Locações para o cliente %s:\n", clientes[i].nome);

            // Exibir todas as locações associadas a esse cliente
            for (int j = 0; j < totalLocacoes; j++) {
                if (locacoes[j].codigo_cliente == clientes[i].codigo) {
                    printf("Código Locação: %d | Data Retirada: %s | Data Devolução: %s | Seguro: %s | Qtd Dias: %d | Código Veículo: %d\n",
                           locacoes[j].codigo, locacoes[j].data_retirada, locacoes[j].data_devolucao,
                           (locacoes[j].seguro == 1) ? "Sim" : "Não", locacoes[j].qtd_dias, locacoes[j].codigo_veiculo);
                }
            }

            break;  // Cliente encontrado, encerrar o loop
        }
    }

    if (!encontrou) {
        printf("Cliente não encontrado.\n");
    }
}
