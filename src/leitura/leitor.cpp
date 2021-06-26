#include "leitura/leitor.hpp"

using namespace leitura;

Leitor::Leitor() {}

Leitor::~Leitor() {}

void Leitor::instanciarObjetos() {
    this->instanciarPostos();
    this->instanciarPessoas();
}

void Leitor::instanciarPostos() {
    int numeroTotalPostos, capacidade, posicaoX, posicaoY;
    std::cin >> numeroTotalPostos;
    this->validarNumeroTotalPostos(numeroTotalPostos);
    for (int i = 0; i < numeroTotalPostos; i++) {
        std::cin >> capacidade >> posicaoX >> posicaoY;
        this->Postos.push_back(alocacao::Posto(i, capacidade, posicaoX, posicaoY));
    }
}

void Leitor::instanciarPessoas() {
    int numeroTotalPessoas, idade, posicaoX, posicaoY;
    std::cin >> numeroTotalPessoas;
    this->validarNumeroTotalPessoas(numeroTotalPessoas);
    for (int i = 0; i < numeroTotalPessoas; i++) {
        std::cin >> idade >> posicaoX >> posicaoY;
        this->Pessoas.push_back(alocacao::Pessoa(i, idade, posicaoX, posicaoY));
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

std::vector<alocacao::Pessoa> Leitor::getPessoas() {
    return this->Pessoas;
}

std::vector<alocacao::Posto> Leitor::getPostos() {
    return this->Postos;
}

