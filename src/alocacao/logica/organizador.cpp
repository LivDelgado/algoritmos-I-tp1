#include "alocacao/logica/organizador.hpp"

#include "leitura/leitor.hpp"

using namespace alocacao;

Organizador::Organizador() {}

Organizador::~Organizador() {
    this->pessoas = nullptr;
    this->postos = nullptr;
}

void Organizador::iniciarVacinacao() {
    this->lerInformacoesEntrada();
}

void Organizador::lerInformacoesEntrada() {
    leitura::Leitor* leitor = new leitura::Leitor();
    leitor->instanciarObjetos();
    this->pessoas = leitor->getPessoas();
    this->postos = leitor->getPostos();
}