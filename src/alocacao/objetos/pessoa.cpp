#include "alocacao/objetos/pessoa.hpp"

using namespace alocacao;

Pessoa::Pessoa() {}

Pessoa::~Pessoa() {}

Pessoa::Pessoa(int id, int idade, int posicaoX, int posicaoY) {
    this->Id = id;
    this->Idade = idade;
    this->PosicaoX = posicaoX;
    this->PosicaoY = posicaoY;
}

void Pessoa::validarParametros() {
    if (this->Idade <= 0 || this->Idade > 10000 ||
        this->PosicaoX < 0 || this->PosicaoX > 100000 ||
        this->PosicaoY < 0 || this->PosicaoY > 100000
    )
        throw "Parâmetros da nova pessoa são inválidos.";
}