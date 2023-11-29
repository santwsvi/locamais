#include "locacao.h"
#include "cliente.h"
#include <string.h>
#include "veiculo.h"
#define MAX_LOCACOES 100
#define ARQUIVO_LOCACOES "locacoes.dat"
#define LOCACOES_TXT "locacoes.txt"

int locacaoExiste(Locacao locacoes[], int totalLocacoes, int codigo) {
    for (int i = 0; i < totalLocacoes; i++) {
        if (locacoes[i].codigo == codigo) {
            return 1; // Locação com o mesmo código encontrado
        }
    }
    return 0; // Nenhuma locação com o mesmo código encontrado
}

void carregarClientes(Cliente clientes[], int *totalClientes);

void cadastrarLocacao(Locacao locacoes[], int *totalLocacoes, Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos) {
    // Verifica se há espaço para cadastrar mais locações
    if (*totalLocacoes < MAX_LOCACOES) {
        Locacao novaLocacao;
        // Lê os dados da nova locação do usuário
        do {
            printf("Digite o código da locação: ");
            scanf("%d", &novaLocacao.codigo);

            // Limpar o buffer após a leitura do inteiro
            while (getchar() != '\n');

            // Verifica se a locação com o mesmo código já existe
            if (locacaoExiste(locacoes, *totalLocacoes, novaLocacao.codigo)) {
                printf("Já existe uma locação com este código. Tente novamente.\n");
            }
        } while (locacaoExiste(locacoes, *totalLocacoes, novaLocacao.codigo));

        printf("Digite o nome do cliente: ");
        char nomeCliente[50];
        scanf("%s", nomeCliente);

        // Procura o cliente pelo nome
        int codigoCliente = -1;
        int nomeDoCliente = "";
        for (int i = 0; i < totalClientes; i++) {
            if (strcmp(clientes[i].nome, nomeCliente) == 0) {
                codigoCliente = clientes[i].codigo;
                nomeDoCliente = clientes[i].nome;
                break;
            }
        }

        if (codigoCliente == -1) {
            printf("Cliente não encontrado. Cadastre o cliente antes de fazer a locação.\n");
            return;
        }

        novaLocacao.codigo_cliente = codigoCliente;

        // Apresenta um menu de veículos disponíveis para o cliente escolher
printf("Veículos disponíveis:\n");
for (int i = 0; i < totalVeiculos; i++) {
    if (strcmp(veiculos[i].status, "disponível") != 0) {
        printf("%d - %s\n", veiculos[i].codigo, veiculos[i].descricao);
    }
}

int escolhaVeiculo;
printf("Escolha o código do veículo desejado: ");
scanf("%d", &escolhaVeiculo);

        // Verifica se o veículo escolhido está disponível
        int codigoVeiculoEscolhido = 0;
        for (int i = 0; i < totalVeiculos; i++) {
            if (veiculos[i].codigo == escolhaVeiculo && strcmp(veiculos[i].status, "disponível") == 0 && veiculos[i].ocupantes >= 1) {
                codigoVeiculoEscolhido = escolhaVeiculo;

                break;
            }
        }



        if (codigoVeiculoEscolhido == -1) {
            printf("Veículo escolhido não está disponível ou não existe. Cancelando locação.\n");
            return;
        }

        novaLocacao.codigo_veiculo = codigoVeiculoEscolhido;

        // Continuação do restante do código...

        printf("Digite a data de retirada (DD/MM/AAAA): ");
        fgets(novaLocacao.data_retirada, sizeof(novaLocacao.data_retirada), stdin);
        novaLocacao.data_retirada[strcspn(novaLocacao.data_retirada, "\n")] = '\0'; // Remover o caractere de nova linha do final

        while (getchar() != '\n');

        printf("Digite a data de devolução (DD/MM/AAAA): ");
        fgets(novaLocacao.data_devolucao, sizeof(novaLocacao.data_devolucao), stdin);
        novaLocacao.data_devolucao[strcspn(novaLocacao.data_devolucao, "\n")] = '\0'; // Remover o caractere de nova linha do final

        // Restante do código...

        // Procura um veículo disponível para a locação
        int codigoVeiculo;
        int nomeDoVeiculo = "";
        for (int i = 0; i < totalVeiculos; i++) {
            if (strcmp(veiculos[i].status, "disponível") != 0 && veiculos[i].ocupantes >= 1) {
                codigoVeiculo = veiculos[i].codigo;
                nomeDoVeiculo = veiculos[i].descricao;
                break;
            }
        }

        if (codigoVeiculo == -1) {
            printf("Nenhum veículo disponível atende aos requisitos da locação.\n");
            return;
        }

        novaLocacao.codigo_veiculo = codigoVeiculo;

        printf("Deseja contratar seguro para o veículo? (1 - Sim / 0 - Não): ");
        scanf("%d", &novaLocacao.seguro);

        // Calcula a quantidade de diárias com base nas datas de retirada e devolução
        // (assumindo que as datas estão em um formato adequado, sem validação completa neste exemplo)
        // Aqui, considerei que a quantidade de diárias é igual ao número de dias entre as datas.
        // Em uma implementação real, você precisaria lidar com datas de maneira mais sofisticada.
        int diasRetirada, mesesRetirada, anosRetirada;
        int diasDevolucao, mesesDevolucao, anosDevolucao;

        sscanf(novaLocacao.data_retirada, "%d/%d/%d", &diasRetirada, &mesesRetirada, &anosRetirada);
        sscanf(novaLocacao.data_devolucao, "%d/%d/%d", &diasDevolucao, &mesesDevolucao, &anosDevolucao);
        novaLocacao.qtd_dias = (diasDevolucao - diasRetirada) + 30 * (mesesDevolucao - mesesRetirada) + 365 * (anosDevolucao - anosRetirada);

        // Adiciona a nova locação ao array de locações
        locacoes[*totalLocacoes] = novaLocacao;
        (*totalLocacoes)++;

        // Atualiza o status do veículo para "alugado"
        for (int i = 0; i < totalVeiculos; i++) {
            if (veiculos[i].codigo == codigoVeiculo) {
                strcpy(veiculos[i].status, "alugado");
                break;
            }
        }

        // Grava as locações no arquivo
        FILE *arquivo = fopen(ARQUIVO_LOCACOES, "ab");
        if (arquivo != NULL) {
            fwrite(&novaLocacao, sizeof(Locacao), 1, arquivo);
            fclose(arquivo);
        } else {
            printf("Erro ao abrir o arquivo de locações.\n");
        }

        // Adiciona uma nova locação a um arquivo de texto
        FILE *arquivoTexto = fopen(LOCACOES_TXT, "a");
        if (arquivoTexto != NULL) {
            fprintf(arquivoTexto, "Código da locação: %d | Nome do cliente: %s | Código do cliente: %d | Nome do veículo: %s | Data de retirada: %s | Data de devolução: %s | Diárias: %d | Seguro: %d |\n", novaLocacao.codigo, nomeDoCliente, novaLocacao.codigo_cliente, nomeDoVeiculo, novaLocacao.data_retirada, novaLocacao.data_devolucao, novaLocacao.qtd_dias, novaLocacao.seguro);
            fclose(arquivoTexto);
        } else {
            printf("Erro ao abrir o arquivo de texto de locações.\n");
        }

        printf("Locação cadastrada com sucesso!\n");

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

