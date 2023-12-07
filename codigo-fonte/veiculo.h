// veiculo.h

#ifndef VEICULO_H
#define VEICULO_H

#include "estruturas.h"

int veiculoExiste(Veiculo veiculos[], int totalVeiculos, int codigo);
void cadastrarVeiculo(Veiculo veiculos[], int *totalVeiculos);
void exibirDetalhesVeiculo(Veiculo veiculo);
void listarVeiculos(Veiculo veiculos[], int totalVeiculos);
void atualizarStatusVeiculos(Veiculo veiculos[], int totalVeiculos);
void carregarVeiculos(Veiculo veiculos[], int *totalVeiculos);
Veiculo *encontrarVeiculo(Veiculo veiculos[], int totalVeiculos, int codigo);

#endif // VEICULO_H
