#include "leitura/leitor.hpp"

using namespace leitura;

Leitor::Leitor() {}

Leitor::~Leitor() {
    this->pessoas = nullptr;
    this->postos = nullptr;
}

void Leitor::instanciarObjetos() {
    int numeroTotalPostos, numeroTotalPessoas;
    int idade, capacidade, posicaoX, posicaoY;

    std::cin >> numeroTotalPostos;
    this->validarNumeroTotalPostos(numeroTotalPostos);
    this->postos = new alocacao::Posto[numeroTotalPostos];
    for (int i = 0; i < numeroTotalPostos; i++) {
        std::cin >> capacidade >> posicaoX >> posicaoY;
        postos[i] = *(new alocacao::Posto(i, capacidade, posicaoX, posicaoY));
    }

    std::cin >> numeroTotalPessoas;
    this->validarNumeroTotalPessoas(numeroTotalPessoas);
    this->pessoas = new alocacao::Pessoa[numeroTotalPessoas];
    for (int i = 0; i < numeroTotalPessoas; i++) {
        std::cin >> idade >> posicaoX >> posicaoY;
        pessoas[i] = *(new alocacao::Pessoa(i, idade, posicaoX, posicaoY));
    }
}

void Leitor::validarNumeroTotalPostos(int numeroTotalPostos) {
    if (numeroTotalPostos <= 0 || numeroTotalPostos > 10000) {
        throw "Número de postos inválido";
    }
}

void Leitor::validarNumeroTotalPessoas(int numeroTotalPessoas) {
    if (numeroTotalPessoas <= 0 || numeroTotalPessoas > 100000) {
        throw "Número de pessoas inválido";
    }
}

alocacao::Pessoa* Leitor::getPessoas() {
    return this->pessoas;
}

alocacao::Posto* Leitor::getPostos() {
    return this->postos;
}

