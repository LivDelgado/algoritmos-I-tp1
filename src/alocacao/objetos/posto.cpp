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
