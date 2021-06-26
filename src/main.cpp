#include <cstdlib>
#include <iostream>

#include "alocacao/logica/organizador.hpp"

int main() {
    std::system("clear");

    try {
        alocacao::Organizador* organizador = new alocacao::Organizador();
        organizador->iniciarVacinacao();
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}