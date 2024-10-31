#include "ContaBancaria.h"

//Implementação do construtor da Classe caso o saldo não tenha sido definido
ContaBancaria::ContaBancaria(int numero, Cliente &cliente) {
    this->numero = numero;
    this->saldo = 0;
    titular = new Cliente(cliente.getClienteNome(), cliente.getClienteCpf());
}
//Implementação do construtor da Classe caso o saldo tenha sido definido
ContaBancaria::ContaBancaria(int numero, Cliente &cliente, double saldo) {
    this->numero = numero;
    if (saldo > 0) {
        this->saldo = saldo;
    } else {
        this->saldo = 0;
    }
    titular = new Cliente(cliente.getClienteNome(), cliente.getClienteCpf());
}
//Destrutor da classe
ContaBancaria::~ContaBancaria() {
    delete titular;
}
//Depositar valor na conta
void ContaBancaria::depositar(double valor) {
    if (valor > 0) {
        this->saldo += valor;
        std::cout << "Deposito de " << valor << " concluído com sucesso.\n";
        return;
    }
    std::cout << "Valor para depósito inválido!\n"; 
}
//Sacar valor da conta
void ContaBancaria::sacar(double valor) {
    if (valor < this->saldo) {
        this->saldo -= valor;
        std::cout << "Saque de " << valor << " concluído com sucesso.\n";
        return;
    }
    std::cout << "Valor para saque inválido!\n"; 
}
//O & foi utilizado para acessar o endereço de memória do clienteX(destino) e
//Alterar o saldo da sua conta diretamente no espaço de memória do cliente
//Invés de alterar somente a variável local
//Transfere valor de uma conta para outra
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor < this->saldo) {
        destino.saldo += valor;
        this->saldo -= valor;
        std::cout << "Transferido: " << valor << " da conta " << this->numero;
        std::cout << " para a conta " << destino.numero << '\n';
        return;
    }
    std::cout << "Valor para transferência inválido\n";
}
//O & foi utilizado para acessar o endereço de memória do clienteX(destino) e
//Alterar o saldo da sua conta diretamente no espaço de memória do cliente
//Invés de alterar somente a variável local
//Transfere o valor de uma conta para outras duas. O valor transferido será dividido  entre as contas
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if (valor < this->saldo) {
        destino1.saldo += valor / 2;
        destino2.saldo += valor / 2;
        this->saldo -= valor;
        std::cout << "Transferido: " << valor / 2 << " para cada conta ";
        std::cout << '(' << destino1.numero << " e " << destino2.numero << ") da conta " << this->numero << '\n'; 
        return;
    }
    std::cout << "Valor para transferência inválido\n";
}
//Exibe saldo da conta
void ContaBancaria::exibirSaldo() {
    std::cout << "Saldo atual da conta " << this->numero << ": R$" << this->saldo << '\n';
}
//Exibe informações sobre a conta
void ContaBancaria::exibirInformacoes() {
    std::cout << "Titular: " << titular->getClienteNome() << ", CPF: " << titular->getClienteCpf() << '\n';
    std::cout << "Número da conta: " << this->numero << ", Saldo: R$" << this->saldo << '\n'; 
}