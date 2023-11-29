#ifndef LOCACAO_H
#define LOCACAO_H

#include <stdio.h>
#include "estruturalocacao.h"

int locacaoExiste(Locacao locacoes[], int totalLocacoes, int codigo);
void cadastrarLocacao(Locacao locacoes[], int *totalLocacoes, Cliente clientes[], int totalClientes, Veiculo veiculos[], int totalVeiculos);
void carregarLocacoes(Locacao locacoes[], int *totalLocacoes);

#endif

