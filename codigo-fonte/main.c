#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cliente.h"

#define MAX_CLIENTES 100

int main() {

    setlocale(LC_ALL, "Portuguese");
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    // Carrega os dados existentes nos arquivos
    carregarClientes(clientes, &totalClientes);

        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar Cliente\n");

        cadastrarCliente(clientes, &totalClientes);

    return 0;
}
