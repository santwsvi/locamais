# Backlog do Produto - Projeto LocaMais

## 1. Cadastro de Clientes
   - **Módulo:** `cadastrarCliente`
     - *Propósito*: Realizar o cadastro de novos clientes na LocaMais.
     - *Parâmetros de Entrada*: Array de estruturas Cliente, Total de clientes.
     - *Parâmetros de Saída*: Código do cliente, Nome do cliente, Endereço, Telefone
   - *Caso de Sucesso*: Cadastrar um novo cliente com informações válidas.
   - *Casos de Teste*:
     - Entrada: 2, Lucas, Rua Ernesto Austin, N/A
     - Saída Esperada: Novo cliente cadastrado com sucesso.

## 2. Cadastro de Veículos
   - **Módulo:** `cadastrarVeiculo`
     - *Propósito*: Realizar o cadastro de novos veículos na LocaMais.
     - *Parâmetros de Entrada*: Array de estruturas Veiculo, Total de veículos.
     - *Parâmetros de Saída*: Código do veículo, Descrição, Modelo, Cor, Placa, Valor da diária, Capacidade de ocupantes
   - *Caso de Sucesso*: Cadastrar um novo veículo com informações válidas.
   - *Casos de Teste*:
     - Entrada: Informações válidas do veículo.
     - Saída Esperada: Novo veículo cadastrado com sucesso.

## 3. Cadastro de Locações
   - **Módulo:** `cadastrarLocacao`
     - *Propósito*: Registrar uma nova locação de veículo para um cliente.
     - *Parâmetros de Entrada*: Array de estruturas Cliente, Array de estruturas Veiculo, Total de clientes, Total de veículos.
     - *Parâmetros de Saída*: Código da locação, Data de retirada, data de devolução, Seguro (sim ou não), Código do cliente, Código do veículo
   - *Caso de Sucesso*: Registrar uma nova locação com informações válidas.
   - *Casos de Teste*:
     - Entrada: 1, 18/11/2023, 25/11/2023, Sim, 1, 1 
     - Saída Esperada: Locação registrada com sucesso.
