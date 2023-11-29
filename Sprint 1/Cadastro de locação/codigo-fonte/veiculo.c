#include "veiculo.h"
#include <string.h>

#define MAX_VEICULOS 100
#define ARQUIVO_VEICULOS "veiculos.dat"
#define VEICULOS_TXT "veiculos.txt"


int veiculoExiste(Veiculo veiculos[], int totalVeiculos, int codigo) {
        for (int i = 0; i < totalVeiculos; i++) {
        if (veiculos[i].codigo == codigo) {
            return 1; // Veículo com o mesmo código encontrado
        }
    }
    return 0; // Nenhum veículo com o mesmo código encontrado
}

void cadastrarVeiculo(Veiculo veiculos[], int *totalVeiculos) {
      // Verifica se há espaço para cadastrar mais veículos
    if (*totalVeiculos < MAX_VEICULOS) {
        Veiculo novoVeiculo;

        // Lê os dados do novo veículo do usuário
        do {
            printf("Digite o código do veículo: ");
            scanf("%d", &novoVeiculo.codigo);

            // Verifica se o veículo com o mesmo código já existe
            if (veiculoExiste(veiculos, *totalVeiculos, novoVeiculo.codigo)) {
                printf("Já existe um veículo com este código. Tente novamente.\n");
            }
        } while (veiculoExiste(veiculos, *totalVeiculos, novoVeiculo.codigo));

        while (getchar() != '\n');

        printf("Digite a descrição do veículo: ");
        fgets(novoVeiculo.descricao, sizeof(novoVeiculo.descricao), stdin);
        novoVeiculo.descricao[strcspn(novoVeiculo.descricao, "\n")] = '\0';

        printf("Digite o modelo do veículo: ");
        fgets(novoVeiculo.modelo, sizeof(novoVeiculo.modelo), stdin);
        novoVeiculo.modelo[strcspn(novoVeiculo.modelo, "\n")] = '\0';
        printf("Digite a cor do veículo: ");
        scanf("%s", novoVeiculo.cor);
        printf("Digite a placa do veículo: ");
        scanf("%s", novoVeiculo.placa);
        printf("Digite o valor da diária do veículo: ");
        scanf("%f", &novoVeiculo.valor_diaria);
        printf("Digite a capacidade de ocupantes do veículo: ");
        scanf("%d", &novoVeiculo.ocupantes);
        printf("Digite o status do veículo (alugado, disponível, em manutenção): ");
        scanf("%s", novoVeiculo.status);

        // Adiciona o novo veículo ao array de veículos
        veiculos[*totalVeiculos] = novoVeiculo;
        (*totalVeiculos)++;
    // Grava os veículos no arquivo
        FILE *arquivo = fopen(ARQUIVO_VEICULOS, "ab");
        if (arquivo != NULL) {
        fwrite(&novoVeiculo, sizeof(Veiculo), 1, arquivo);
        fclose(arquivo);
        } else {
        printf("Erro ao abrir o arquivo de veículos.\n");

        }

            // Adiciona o novo cliente ao arquivo de texto
    FILE *arquivoTexto = fopen(VEICULOS_TXT, "a");
    if (arquivoTexto != NULL) {
        fprintf(arquivoTexto, "Código do veiculo: %d | Descrição : %s | Modelo : %s | Cor : %s | Placa: %s | Valor diária: %d | Quantidade de ocupantes: %d | Status: % s |\n", novoVeiculo.codigo, novoVeiculo.descricao, novoVeiculo.modelo, novoVeiculo.cor, novoVeiculo.placa, novoVeiculo.valor_diaria, novoVeiculo.ocupantes, novoVeiculo.status);
        fclose(arquivoTexto);
    } else {
        printf("Erro ao abrir o arquivo de texto de veiculos.\n");
    }

        printf("Veículo cadastrado com sucesso!\n");
        }

}

void carregarVeiculos(Veiculo veiculos[], int *totalVeiculos) {
   FILE *arquivo = fopen(ARQUIVO_VEICULOS, "rb");
if (arquivo != NULL) {
while (fread(&veiculos[*totalVeiculos], sizeof(Veiculo), 1, arquivo) == 1) {
(*totalVeiculos)++;
}
fclose(arquivo);
}
}

