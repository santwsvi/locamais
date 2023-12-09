// locacao.c

#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MULTA_PERCENTUAL 0.05
#define MULTA_DIARIA 30.0
#define MAX_LOCACOES 100
#define ARQUIVO_LOCACOES "locacoes.dat"
#define ARQUIVO_VEICULOS "veiculos.dat"
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



// Função auxiliar para persistir as alterações no arquivo
void salvarLocacoes(Locacao locacoes[], int totalLocacoes) {
    FILE *arquivo = fopen(ARQUIVO_LOCACOES, "wb");
    if (arquivo != NULL) {
        fwrite(locacoes, sizeof(Locacao), totalLocacoes, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de locações.\n");
    }
}

// Função auxiliar para persistir as alterações no estado do veículo
void salvarVeiculos(Veiculo veiculos[], int totalVeiculos) {
    FILE *arquivo = fopen(ARQUIVO_VEICULOS, "wb");
    if (arquivo != NULL) {
        fwrite(veiculos, sizeof(Veiculo), totalVeiculos, arquivo);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de veículos.\n");
    }
}

void baixaLocacao(Locacao locacoes[], int *totalLocacoes, Veiculo veiculos[], int totalVeiculos) {

int codigoLocacao;
    printf("Digite o código da locação a ser encerrada: ");
    scanf("%d", &codigoLocacao);

    int indexLocacao = -1;
    for (int i = 0; i < *totalLocacoes; i++) {
        if (locacoes[i].codigo == codigoLocacao) {
            indexLocacao = i;
            break;
        }
    }

    if (indexLocacao == -1) {
        printf("Locação não encontrada.\n");
        return;
    }

    // Obter a data atual
    time_t now;
    time(&now);
    struct tm *localAtual = localtime(&now);
    char dataAtual[11];  // formato: dd/mm/aaaa
    strftime(dataAtual, sizeof(dataAtual), "%d/%m/%Y", localAtual);

    printf("Data Atual: %s\n", dataAtual);

    // Obter a data de devolução prevista
    struct tm localDevolucao;
    sscanf(locacoes[indexLocacao].data_devolucao, "%d/%d/%d", &localDevolucao.tm_mday, &localDevolucao.tm_mon, &localDevolucao.tm_year);
    localDevolucao.tm_mon -= 1;  // Reduzir 1 do mês, pois a estrutura tm utiliza meses de 0 a 11
    localDevolucao.tm_year -= 1900;  // Ajustar o ano para contar a partir de 1900

    char dataDevolucaoPrevista[11];
    strftime(dataDevolucaoPrevista, sizeof(dataDevolucaoPrevista), "%d/%m/%Y", &localDevolucao);
    printf("Data Devolução Prevista: %s\n", dataDevolucaoPrevista);

int diasAtraso = calcularDiferencaDias(dataDevolucaoPrevista, dataAtual);
    printf("Dias de Atraso: %d\n", diasAtraso);

    double valorTotal = 0;

    // Se houver dias de atraso, calcular a multa
    if (diasAtraso > 0) {
        // Calcular multa por atraso
        double multa = veiculos[indexLocacao].valor_diaria * MULTA_PERCENTUAL * diasAtraso + MULTA_DIARIA * diasAtraso;
        printf("Multa por atraso: R$ %.2lf\n", multa);

        // Adicionar multa ao valor total a ser pago

        valorTotal = valorTotal + multa;

    }

    strcpy(locacoes[indexLocacao].data_devolucao, dataAtual);

    // Atualizar o status do veículo
    int codigoVeiculo = locacoes[indexLocacao].codigo_veiculo;
    for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].codigo == codigoVeiculo) {
            strcpy(veiculos[i].status, "Disponível");
            // Persistir alterações no estado do veículo
            salvarVeiculos(veiculos, totalVeiculos);
            break;
        }
    }

    int diasLocacao = locacoes[indexLocacao].qtd_dias;

    valorTotal += veiculos[indexLocacao].valor_diaria * diasLocacao;

    printf("Valor total a ser pago: R$ %.2lf\n", valorTotal);


    // Persistir as alterações no arquivo
    salvarLocacoes(locacoes, *totalLocacoes);
}
