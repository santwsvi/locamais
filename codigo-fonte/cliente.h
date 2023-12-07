// cliente.h

#ifndef CLIENTE_H
#define CLIENTE_H

#include "estruturas.h"

int clienteExiste(Cliente clientes[], int totalClientes, int codigo);
void cadastrarCliente(Cliente clientes[], int *totalClientes);
void carregarClientes(Cliente clientes[], int *totalClientes);

#endif // CLIENTE_H
