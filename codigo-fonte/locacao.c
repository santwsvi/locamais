// locacao.c

#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOCACOES 100
#define ARQUIVO_LOCACOES "locacoes.dat"
#define LOCACOES_TXT "locacoes.txt"
#define HORARIO_COMERCIAL_INICIO 8
#define HORARIO_COMERCIAL_FIM 18
#define VALOR_SEGURO 50.0

int locacaoExiste(Locacao locacoes[], int totalLocacoes, int codigo) {
    for (int i = 0; i < totalLocacoes; i++) {
        if (locacoes[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

int calcularDiferencaDias(const char *data_inicial, const char *data_final) {
    struct tm tm_inicial = {0};
    struct tm tm_final = {0};
    int dia_inicial, mes_inicial, ano_inicial;
    int dia_final, mes_final, ano_final;

    sscanf(data_inicial, "%d/%d/%d", &dia_inicial, &mes_inicial, &ano_inicial);
    sscanf(data_final, "%d/%d/%d", &dia_final, &mes_final, &ano_final);

    tm_inicial.tm_mday = dia_inicial;
    tm_inicial.tm_mon = mes_inicial - 1;
    tm_inicial.tm_year = ano_inicial - 1900;

    tm_final.tm_mday = dia_final;
    tm_final.tm_mon = mes_final - 1;
    tm_final.tm_year = ano_final - 1900;

    time_t time_inicial = mktime(&tm_inicial);
    time_t time_final = mktime(&tm_final);

    double diff_seconds = difftime(time_final, time_inicial);
    int diff_days = (int)(diff_seconds / (60 * 60 * 24));

    return diff_days;
}

void cadastrarLocacao(Locacao locacoes[], int *totalLocacoes, Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos) {
    if (*totalLocacoes < MAX_LOCACOES) {
        Locacao novaLocacao;

        do {
            printf("Digite o código da locação: ");
            scanf("%d", &novaLocacao.codigo);

            if (locacaoExiste(locacoes, *totalLocacoes, novaLocacao.codigo)) {
                printf("Já existe uma locação com este código. Tente novamente.\n");
            }
        } while (locacaoExiste(locacoes, *totalLocacoes, novaLocacao.codigo));

        while (getchar() != '\n');

        printf("Digite a data de retirada (DD/MM/AAAA): ");
        fgets(novaLocacao.data_retirada, sizeof(novaLocacao.data_retirada), stdin);
        novaLocacao.data_retirada[strcspn(novaLocacao.data_retirada, "\n")] = '\0';

        while (getchar() != '\n');

        printf("Digite a data de devolução (DD/MM/AAAA): ");
        fgets(novaLocacao.data_devolucao, sizeof(novaLocacao.data_devolucao), stdin);
        novaLocacao.data_devolucao[strcspn(novaLocacao.data_devolucao, "\n")] = '\0';

        int diferenca_dias = calcularDiferencaDias(novaLocacao.data_retirada, novaLocacao.data_devolucao);

        novaLocacao.qtd_dias = diferenca_dias;

        printf("O veículo terá seguro? (1 - Sim, 0 - Não): ");
        scanf("%d", &novaLocacao.seguro);

        printf("Digite o código do cliente: ");
        scanf("%d", &novaLocacao.codigo_cliente);

        if (!clienteExiste(clientes, totalClientes, novaLocacao.codigo_cliente)) {
            printf("Cliente não encontrado. Cadastre o cliente antes de realizar a locação.\n");
            return;
        }

        printf("Digite o código do veículo: ");
        scanf("%d", &novaLocacao.codigo_veiculo);

        if (!veiculoExiste(veiculos, totalVeiculos, novaLocacao.codigo_veiculo)) {
            printf("Veículo não encontrado. Cadastre o veículo antes de realizar a locação.\n");
            return;
        }

        Veiculo *novoVeiculo = encontrarVeiculo(veiculos, totalVeiculos, novaLocacao.codigo_veiculo);

        if (novoVeiculo != NULL && strcmp(novoVeiculo->status, "Disponível") == 0) {
            strcpy(novoVeiculo->status, "Alugado");

            locacoes[*totalLocacoes] = novaLocacao;
            (*totalLocacoes)++;

            // Chama a função para atualizar o status dos veículos no arquivo
            atualizarStatusVeiculos(veiculos, totalVeiculos);

            FILE *arquivo = fopen(ARQUIVO_LOCACOES, "ab");
            if (arquivo != NULL) {
            fwrite(&novaLocacao, sizeof(Locacao), 1, arquivo);
            fclose(arquivo);
            } else {
                printf("Erro ao abrir o arquivo de locações.\n");
            }

            printf("Locação cadastrada com sucesso!\n");
        } else {
            printf("Veículo não disponível para locação!\n");
        }
    } else {
        printf("Limite de locações atingido!\n");
    }
}

void carregarLocacoes(Locacao locacoes[], int *totalLocacoes) {
    FILE *arquivo = fopen(ARQUIVO_LOCACOES, "rb");
    if (arquivo != NULL) {
        while (fread(&locacoes[*totalLocacoes], sizeof(Locacao), 1, arquivo) == 1) {
            (*totalLocacoes)++;
        }
        fclose(arquivo);
    }
}

Veiculo *encontrarVeiculo(Veiculo veiculos[], int totalVeiculos, int codigo) {
    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].codigo == codigo) {
            return &veiculos[i];
        }
    }
    return NULL;
}
