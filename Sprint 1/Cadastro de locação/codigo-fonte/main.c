#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cliente.h"

#define MAX_LOCACOES 100
#define MAX_CLIENTES 100
#define MAX_VEICULOS 100

int main() {

    setlocale(LC_ALL, "Portuguese");
    Locacao locacoes[MAX_LOCACOES];
    int totalLocacoes = 0;

    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    Veiculo veiculos[MAX_VEICULOS];
    int totalVeiculos = 0;

    // Carrega os dados existentes nos arquivos
    carregarLocacoes(locacoes, &totalLocacoes);
    carregarClientes(clientes, &totalClientes);
    carregarVeiculos(veiculos, &totalVeiculos);

    printf("3 - Cadastrar locação\n");

    cadastrarLocacao(locacoes, &totalLocacoes, clientes, totalClientes, veiculos, totalVeiculos);

    return 0;
}
