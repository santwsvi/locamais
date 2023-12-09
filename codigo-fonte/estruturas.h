
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[20];
} Cliente;

typedef struct {
    int codigo;
    char descricao[200];
    char modelo[50];
    char cor[20];
    char placa[20];
    double valor_diaria;
    int ocupantes;
    char status[20];
} Veiculo;

typedef struct {
    int codigo;
    char data_retirada[11];  // DD/MM/AAAA
    char data_devolucao[11];  // DD/MM/AAAA
    int qtd_dias;
    int seguro;
    int codigo_cliente;
    int codigo_veiculo;
} Locacao;


#endif // ESTRUTURAS_H


