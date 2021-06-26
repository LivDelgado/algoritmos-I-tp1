#include "alocacao/objetos/posto.hpp"

using namespace alocacao;

Posto::Posto() {}

Posto::~Posto() {}

Posto::Posto(int id, int capacidade, int posicaoX, int posicaoY) {
    this->Id = id;
    this->Capacidade = capacidade;
    this->PosicaoX = posicaoX;
    this->PosicaoY = posicaoY;
    this->validarParametros();
}

void Posto::validarParametros() {
    if (this->Capacidade <= 0 || this->Capacidade > 10000 ||
        this->PosicaoX < 0 || this->PosicaoX > 100000 ||
        this->PosicaoY < 0 || this->PosicaoY > 100000
    )
        throw "Parâmetros do novo posto são inválidos.";
}

int Posto::getId() {
    return this->Id;
}

int Posto::getCapacidade() {
    return this->Capacidade;
}

int Posto::getPosicaoX() {
    return this->PosicaoX;
}

int Posto::getPosicaoY() {
    return this->PosicaoY;
}

std::vector<Pessoa> Posto::getPessoasAlocadas() {
    return this->PessoasAlocadas;
}

void Posto::alocarPessoa(Pessoa pessoa) {
    this->PessoasAlocadas.push_back(pessoa);
}

bool Posto::temVaga() {
    return ((int)this->PessoasAlocadas.size() < this->Capacidade);
}

