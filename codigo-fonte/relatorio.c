// relatorio.c

#include "relatorio.h"
#include "cliente.h"
#include "veiculo.h"
#include "locacao.h"
#include <stdio.h>

void gerarRelatorio(Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos, Locacao locacoes[], int totalLocacoes) {
    // Gerar relatório de clientes
    printf("Relatório de Clientes:\n");
    for (int i = 0; i < totalClientes; i++) {
        printf("Código: %d | Nome: %s | Endereço: %s | Telefone: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }

    // Gerar relatório de veículos
    printf("\nRelatório de Veículos:\n");
    for (int i = 0; i < totalVeiculos; i++) {
        printf("Código: %d | Descrição: %s | Modelo: %s | Cor: %s | Placa: %s | Valor Diária: %.2f | Ocupantes: %d | Status: %s\n", veiculos[i].codigo, veiculos[i].descricao, veiculos[i].modelo, veiculos[i].cor, veiculos[i].placa, veiculos[i].valor_diaria, veiculos[i].ocupantes, veiculos[i].status);
    }

    // Gerar relatório de locações
    printf("\nRelatório de Locações:\n");
    for (int i = 0; i < totalLocacoes; i++) {
        printf("Código: %d | Data Retirada: %s | Data Devolução: %s | Seguro: %s | Qtd Dias: %d | Código Cliente: %d | Código Veículo: %d\n", locacoes[i].codigo, locacoes[i].data_retirada, locacoes[i].data_devolucao, (locacoes[i].seguro == 1) ? "Sim" : "Não", locacoes[i].qtd_dias, locacoes[i].codigo_cliente, locacoes[i].codigo_veiculo);
    }
}

