#include "alocacao/objetos/pessoa.hpp"

using namespace alocacao;

Pessoa::Pessoa() {}

Pessoa::~Pessoa() {}

Pessoa::Pessoa(int id, int idade, int posicaoX, int posicaoY) {
    this->Id = id;
    this->Idade = idade;
    this->PosicaoX = posicaoX;
    this->PosicaoY = posicaoY;
    this->PostoEmQueIraVacinar = -1;
    this->validarParametros();
}

void Pessoa::validarParametros() {
    if (this->Idade <= 0 || this->Idade > 10000 ||
        this->PosicaoX < 0 || this->PosicaoX > 100000 ||
        this->PosicaoY < 0 || this->PosicaoY > 100000
    )
        throw "Parâmetros da nova pessoa são inválidos.";
}


int Pessoa::getId() {
    return this->Id;
}

int Pessoa::getIdade() {
    return this->Idade;
}

int Pessoa::getPosicaoX() {
    return this->PosicaoX;
}

int Pessoa::getPosicaoY() {
    return this->PosicaoY;
}

int Pessoa::getPostoEmQueIraVacinar() {
    return this->PostoEmQueIraVacinar;
}

void Pessoa::alocarAPosto(int posto) {
    this->PostoEmQueIraVacinar = posto;
}

bool Pessoa::alocada() {
    return this->PostoEmQueIraVacinar != -1;
}
