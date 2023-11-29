#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[15];
} Cliente;

typedef struct {
    int codigo;
    char descricao[50];
    char modelo[20];
    char cor[20];
    char placa[10];
    float valor_diaria;
    int ocupantes;
    char status[15];
} Veiculo;

typedef struct {
    int codigo;
    char data_retirada[11];
    char data_devolucao[11];
    int seguro;
    int qtd_dias;
    int codigo_cliente;
    int codigo_veiculo;
} Locacao;

#endif

