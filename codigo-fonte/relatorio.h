// relatorio.h

#ifndef RELATORIO_H
#define RELATORIO_H

#include "estruturas.h"

void imprimirRelatorioClientes(Cliente clientes[], int totalClientes);
void imprimirRelatorioVeiculos(Veiculo veiculos[], int totalVeiculos);
void imprimirRelatorioLocacoes(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos);
void imprimirRelatorios(Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos, Locacao locacoes[], int totalLocacoes);
void salvarRelatorioClientes(Cliente clientes[], int totalClientes);
void carregarRelatorioClientes(Cliente clientes[], int *totalClientes);
void salvarRelatorioVeiculos(Veiculo veiculos[], int totalVeiculos);
void carregarRelatorioVeiculos(Veiculo veiculos[], int *totalVeiculos);
void salvarRelatorioLocacoes(Locacao locacoes[], int totalLocacoes);
void carregarRelatorioLocacoes(Locacao locacoes[], int *totalLocacoes);

#endif // RELATORIO_H
