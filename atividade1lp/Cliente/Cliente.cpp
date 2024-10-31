#include "Cliente.h"

//Implementação do construtor da Classe
Cliente::Cliente(std::string nome, std::string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}
//Destrutor da Classe
Cliente::~Cliente(){}
//Retorna o nome do cliente
std::string Cliente::getClienteNome() {
    return nome;
}
//Retorna o cpf do cliente
std::string Cliente::getClienteCpf() {
    return cpf;
}
//Exibe o nome do cliente
void Cliente::exibeClienteNome() {
    std::cout << nome; 
}
//Exibe o cpf do cliente
void Cliente::exibeClienteCPF() {
    std::cout << cpf; 
}