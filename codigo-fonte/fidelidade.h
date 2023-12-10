// fidelidade.h

#ifndef FIDELIDADE_H
#define FIDELIDADE_H

#include "locacao.h"
#include "cliente.h"

void calcularPontosFidelidade(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes);
void premiarClientes(Cliente clientes[], int totalClientes);
int verificarPontosCliente(Locacao locacoes[], int totalLocacoes, Cliente clientes[], int totalClientes, int );

#endif // FIDELIDADE_H
