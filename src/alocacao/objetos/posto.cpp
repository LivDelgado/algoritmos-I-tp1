#include "alocacao/objetos/posto.hpp"

using namespace alocacao;

Posto::Posto() {}

Posto::~Posto() {}

Posto::Posto(int id, int capacidade, int posicaoX, int posicaoY) {
    this->Id = id;
    this->Capacidade = capacidade;
    this->PosicaoX = posicaoX;
    this->PosicaoY = posicaoY;
}

