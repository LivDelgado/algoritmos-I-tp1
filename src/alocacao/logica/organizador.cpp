#include "alocacao/logica/organizador.hpp"

#include "leitura/leitor.hpp"

using namespace alocacao;

Organizador::Organizador() {}

Organizador::~Organizador() {
    this->Pessoas.~vector();
    this->Postos.~vector();
}

void Organizador::iniciarVacinacao() {
    this->lerInformacoesEntrada();
    this->organizarFilaPrioridade();
    this->alocarPessoasAPostos();
    this->imprimirAlocacao();
}

void Organizador::lerInformacoesEntrada() {
    leitura::Leitor *leitor = new leitura::Leitor();
    leitor->instanciarObjetos();
    this->Pessoas = leitor->getPessoas();
    this->Postos = leitor->getPostos();
}

void Organizador::organizarFilaPrioridade() {
    std::sort(this->Pessoas.begin(), this->Pessoas.end(),
        [](Pessoa &a, Pessoa &b) -> bool {
            return (a.getIdade() > b.getIdade()) ||
                    (a.getIdade() == b.getIdade() && a.getId() < b.getId());
        })
    ;
}

void Organizador::alocarPessoasAPostos() {
    for (Pessoa pessoa : this->Pessoas) {
        this->AtualDaFila = pessoa;
        this->ordernarPostosDistanciaPessoa();

        // itera sobre os postos para achar o primeiro com vaga
        Posto *postoAAlocar = nullptr;
        for (Posto posto : this->Postos) {
            if (posto.temVaga()) {
                postoAAlocar = &posto;
                break;
            }
        }

        if (postoAAlocar != nullptr) {
            // aloca pessoa a posto
            AtualDaFila.alocarAPosto(postoAAlocar->getId());
            postoAAlocar->alocarPessoa(AtualDaFila);
        }
    }
}

void Organizador::ordernarPostosDistanciaPessoa() {
    std::sort(this->Postos.begin(), this->Postos.end(),
        [this](Posto &a, Posto &b) -> bool {
            double distanciaPosto1 = this->calcularDistancia(this->AtualDaFila, a);
            double distanciaPosto2 = this->calcularDistancia(this->AtualDaFila, b);

            return (distanciaPosto1 < distanciaPosto2) ||
                    (distanciaPosto1 == distanciaPosto2 && a.getId() < b.getId());
        }
    );
}

void Organizador::imprimirAlocacao() {
    for (Posto posto : this->Postos) {
        std::cout << posto.getId() << std::endl;
        for (Pessoa pessoa : posto.getPessoasAlocadas()) {
            std::cout << pessoa.getId() << " ";
        }
    }
}

double Organizador::calcularDistancia(Pessoa pessoa, Posto posto) {
    unsigned int diferencaX = abs(pessoa.getPosicaoX() - posto.getPosicaoX());
    unsigned int diferencaY = abs(pessoa.getPosicaoY() - posto.getPosicaoY());

    return sqrt(pow(diferencaX, 2) + pow(diferencaY, 2));
}
