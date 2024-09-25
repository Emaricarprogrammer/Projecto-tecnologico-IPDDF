# Projecto Tecnológico IPDDF - Versão 0.1

Este projeto é a resolução de uma problemática.

## Complexo Escolar Dom Damião Franklin

**Mini Projeto de TLP – Fase II (POO)**

A instituição pretende que os grupos dêem sequência da fase seguinte do projeto anteriormente feito, isto é, Gestão de Conta Bancária, utilizando o Paradigma Orientado a Objetos (POO) em Java ou C#. O sistema fará todas as transações como consulta de saldo, transferências, consulta de saldo de conta e extratos em classes.

## Funcionalidades do Sistema

A classe `Banco` terá um método principal contendo os seguintes métodos:
1. **Abertura_de_Conta**
2. **Gestão_de_conta()**
3. **Gestão_de_Contas()**
4. **Sair()**

### Método “Abertura_de_Conta”

1. **Abertura de conta**
   - Esta tarefa é exclusiva dos gerentes do banco. Para criar uma conta, um gerente deve acessar o sistema com seu e-mail e senha, previamente cadastrados na classe `Gerente`, que contém os atributos: nome completo, e-mail e senha.
   - O sistema terá uma classe `Conta` com os seguintes atributos:
     - Nome do titular (deve ser do tipo cliente)
     - Número da conta (11 dígitos)
     - Saldo
     - Data de criação da conta (automático)
   - Métodos: `depósito()`, `levantamento()`, `transferência()`, `atualizarSaldo()`.
   - Uma conta pode ser do tipo corrente ou poupança, e todas devem subscrever o método `atualizarSaldo()`. 
     - Na conta corrente, o `atualizarSaldo()` representa uma redução do valor com uma taxa de 2% trimestralmente.
     - Na conta poupança, o saldo é atualizado com uma taxa de juros de 10% semestralmente.
   - O sistema deve manter o registro dos clientes existentes, com a classe `Cliente` contendo:
     - Nome do cliente
     - Data de nascimento
     - Morada
     - Telemóvel
     - Correio eletrónico
     - Código (gerado automaticamente pelo sistema).

### Método “Gestão_de_conta”

Este método vai conter:
1. **Consultar Saldo**
2. **Depósito**
3. **Levantamento**
4. **Extrato bancário**
5. **Transferência**
6. **Consultar IBAN/N° de conta**
7. **Sair**

#### Consultar Saldo

O usuário insere o número da conta e o sistema retorna o saldo.

#### Levantamento

O método `Levantamento()` recebe dois parâmetros: número da conta e o valor a retirar. A transação será bem-sucedida caso obedeça às regras:
- Se o saldo for zero, apresentar a mensagem: "Não será possível efetuar o seu pedido. O teu saldo é negativo".
- Se o saldo for diferente de zero e menor que o valor a levantar, apresentar: "Caro cliente, o teu saldo é inferior ao valor solicitado!".

#### Extrato Bancário

O usuário insere o número da conta, e o sistema lista todas as transações feitas.

#### Transferência

O usuário insere o número da conta para transferências dentro do mesmo banco, e IBAN se forem de bancos diferentes. Aplica-se a mesma regra do levantamento.

#### Consultar IBAN/N° de conta

O IBAN é um número constituído por 21 dígitos:
- Os 8 primeiros identificam o banco.
- Os 11 dígitos representam o número da conta corrente.
- Os 2 dígitos são aleatórios.

### Método “Gestão de Contas”

Somente funcionários do banco (gerentes e caixas) têm acesso. Ao acessar, será pedido o nome do usuário e a senha do gerente. Se o funcionário ainda não tiver uma conta, deverá se cadastrar. Aqui, o gerente poderá visualizar todas as contas já criadas.

## Últimas Considerações

1. Deve ser feito um diagrama de classes para o problema.
2. Aplicar os conceitos de herança e polimorfismo.
3. Todas as classes devem ter o método `toString()`.
4. Para transações como extrato e listar todas as contas, utilizar `ArrayList`.
5. Todos os atributos das classes devem ser privados, aplicando métodos getter e setter.
6. As classes devem conter método construtor.
7. Usar comentários em cada funcionalidade.

## Como Contribuir

Se você gostaria de contribuir para este projeto, sinta-se à vontade para abrir uma issue ou enviar um pull request. 

## Licença

Distribuído sob a licença MIT. Veja `LICENSE` para mais detalhes.
