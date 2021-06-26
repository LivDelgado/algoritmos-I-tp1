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

