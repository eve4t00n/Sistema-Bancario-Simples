#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

class Cliente {
private:
    std::string nome, cpf;
public:
    Cliente(std::string nome, std::string cpf);
    ~Cliente();
    std::string getClienteNome();
    std::string getClienteCpf();
    void exibeClienteNome();
    void exibeClienteCPF();
};

#endif // CLIENTE_H
