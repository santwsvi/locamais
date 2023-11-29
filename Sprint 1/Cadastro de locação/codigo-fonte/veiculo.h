#ifndef VEICULO_H
#define VEICULO_H

#include <stdio.h>
#include "estruturalocacao.h"

int veiculoExiste(Veiculo veiculos[], int totalVeiculos, int codigo);
void cadastrarVeiculo(Veiculo veiculos[], int *totalVeiculos);
void carregarVeiculos(Veiculo veiculos[], int *totalVeiculos);

#endif

