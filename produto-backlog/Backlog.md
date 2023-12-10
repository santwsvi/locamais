# Backlog do Produto - Projeto LocaMais

## Sprint 1
### 1. Cadastro de Clientes
   - **Módulo:** `cadastrarCliente`
     - *Propósito*: Realizar o cadastro de novos clientes na LocaMais.
     - *Parâmetros de Entrada*: Array de estruturas Cliente, Total de clientes.
     - *Parâmetros de Saída*: Código do cliente, Nome do cliente, Endereço, Telefone
   - *Caso de Sucesso*: Cadastrar um novo cliente com informações válidas.
   - *Casos de Teste*:
     - Entrada: 2, Lucas, Rua Ernesto Austin, N/A
     - Saída Esperada: Novo cliente cadastrado com sucesso.

### 2. Cadastro de Veículos
   - **Módulo:** `cadastrarVeiculo`
     - *Propósito*: Realizar o cadastro de novos veículos na LocaMais.
     - *Parâmetros de Entrada*: Array de estruturas Veiculo, Total de veículos.
     - *Parâmetros de Saída*: Código do veículo, Descrição, Modelo, Cor, Placa, Valor da diária, Capacidade de ocupantes
   - *Caso de Sucesso*: Cadastrar um novo veículo com informações válidas.
   - *Casos de Teste*:
     - Entrada: Informações válidas do veículo.
     - Saída Esperada: Novo veículo cadastrado com sucesso.

### 3. Cadastro de Locações
   - **Módulo:** `cadastrarLocacao`
     - *Propósito*: Registrar uma nova locação de veículo para um cliente.
     - *Parâmetros de Entrada*: Array de estruturas Cliente, Array de estruturas Veiculo, Total de clientes, Total de veículos.
     - *Parâmetros de Saída*: Código da locação, Data de retirada, data de devolução, Seguro (sim ou não), Código do cliente, Código do veículo
   - *Caso de Sucesso*: Registrar uma nova locação com informações válidas.
   - *Casos de Teste*:
     - Entrada: 1, 18/11/2023, 25/11/2023, Sim, 1, 1 
     - Saída Esperada: Locação registrada com sucesso.

## Sprint 2
### 4. Baixa de Locação e Cálculo de Valor Total
   - **Módulo:** `baixaLocacao`
     - *Propósito*: Realizar a baixa em uma locação, calcular o valor total a ser pago por um cliente, alterar o status do veículo para disponível, validar a data de entrega do veículo e calcular multa por atraso.
     - *Parâmetros de Entrada*: Array de estruturas Locacao, Data de entrega do veículo.
     - *Parâmetros de Saída*: Valor total a ser pago.
     - *Caso de Sucesso*: Baixar a locação com informações válidas, calcular o valor total e alterar o status do veículo.

### 5. Funções de Pesquisa
   - **Módulo:** `pesquisar`
     - *Propósito*: Implementar funções para pesquisar clientes por nome ou código e veículos por placa ou código.
     - *Parâmetros de Entrada*: Array de estruturas Cliente/Veiculo, Total de clientes/veículos, Nome/código ou placa/código.
     - *Parâmetros de Saída*: Informações do cliente/veículo correspondente.
     - *Caso de Sucesso*: Encontrar e exibir informações do cliente/veículo.

### 6. Lista de Locações por Cliente
   - **Módulo:** `mostrarLocacoesCliente`
     - *Propósito*: Implementar uma função que mostra na tela todas as locações de um determinado cliente.
     - *Parâmetros de Entrada*: Array de estruturas Locacao, Total de locações, Array de estruturas Cliente, Total de clientes, Nome/código do cliente.
     - *Parâmetros de Saída*: Lista de locações associadas ao cliente.
     - *Caso de Sucesso*: Exibir as locações do cliente especificado.

### 8. Função Extra - Print de Relatório
   - **Módulo:** `gerarRelatorio`
     - *Propósito*: Implementar uma função que gere o print de relatório contendo informações sobre clientes, veículos e locações.
     - *Parâmetros de Entrada*: Array de estruturas Cliente/Veiculo/Locacao, Total de clientes/veículos/locações.
     - *Parâmetros de Saída*: Print com informações do(s) relatório(s).
     - *Caso de Sucesso*: Geração do print com todas as informações cadastradas de clientes, veículos e locações.

### 8. Programa de Fidelidade
   - **Módulo:** `menuPontosFidelidade`
     - *Propósito*: Implementar uma função que calcule a quantidade de pontos de fidelidade de um cliente, pesquisar clientes com 500 pontos no programa de fidelidade e premiar esses clientes.
     - *Parâmetros de Entrada*: Array de estruturas Locacao, Total de locações, Array de estruturas Cliente, Total de clientes.
     - *Parâmetros de Saída*: Pontos de fidelidade do cliente, Lista de clientes premiados.
     - *Caso de Sucesso*: Calcular pontos de fidelidade, identificar clientes premiados e exibir a lista de premiados.

