// locacao.h

#ifndef LOCACAO_H
#define LOCACAO_H

#include "estruturas.h"
int locacaoExiste(Locacao locacoes[], int totalLocacoes, int codigo);
int calcularDiferencaDias(const char *data_inicial, const char *data_final);
void cadastrarLocacao(Locacao locacoes[], int *totalLocacoes, Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos);
void exibirLocacoes(const Locacao locacoes[], int totalLocacoes, const Cliente clientes[], int totalClientes, const Veiculo veiculos[], int totalVeiculos);
void carregarLocacoes(Locacao locacoes[], int *totalLocacoes);
Veiculo *encontrarVeiculo(Veiculo veiculos[], int totalVeiculos, int codigo);
void baixaLocacao(Locacao locacoes[], int *totalLocacoes, Veiculo veiculos[], int totalVeiculos);


#endif // LOCACAO_H
