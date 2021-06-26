#include "alocacao/logica/organizador.hpp"

#include "leitura/leitor.hpp"
#include <time.h>

using namespace alocacao;

Organizador::Organizador() {}

Organizador::~Organizador() {}

void Organizador::iniciarVacinacao() {
    clock_t t;
    t = clock();
    this->lerInformacoesEntrada();
    this->organizarFilaPrioridade();
    this->alocarPessoasAPostos();
    this->ordenarPostosPorId();
    this->imprimirAlocacao();
    t = clock() - t;
    std::cout << "Executado em: " << ((float)t)/CLOCKS_PER_SEC << " segundos" << std::endl;
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
    for (Pessoa & pessoa : this->Pessoas) {
        this->AtualDaFila = pessoa;
        Posto* postoComMenorDistancia = this->obterPostoComMenorDistanciaPessoa(pessoa);

        if (postoComMenorDistancia != nullptr) {
            AtualDaFila.alocarAPosto(postoComMenorDistancia->getId());
            postoComMenorDistancia->alocarPessoa(AtualDaFila.getId());
        } else {
            break;
        }
    }
}

Posto* Organizador::obterPostoComMenorDistanciaPessoa(Pessoa pessoa) {
    double menorDistancia = MAXFLOAT;
    Posto* postoMaisPerto = nullptr;
    for (Posto & posto : this->Postos) {
        if (posto.temVaga()) {
            double distancia = this->calcularDistancia(pessoa, posto);
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                postoMaisPerto = &posto;
            }
        }
    }

    return postoMaisPerto;
}

void Organizador::ordenarPostosPorId() {
    std::sort(this->Postos.begin(), this->Postos.end(),
        [](Posto &a, Posto &b) -> bool {
            return a.getId() < b.getId();
        }
    );
}


void Organizador::imprimirAlocacao() {
    for (Posto & posto : this->Postos) {
        std::cout << posto.getId() << std::endl;
        int* pessoasAlocadas = posto.getPessoasAlocadas();
        int numeroPessoasAlocadas = posto.getNumeroPessoasAlocadas();
        for (int i = 0; i < numeroPessoasAlocadas; i++) {
            std::cout << pessoasAlocadas[i];
            if (i+1 < numeroPessoasAlocadas)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

double Organizador::calcularDistancia(Pessoa & pessoa, Posto & posto) {
    unsigned int diferencaX = abs(pessoa.getPosicaoX() - posto.getPosicaoX());
    unsigned int diferencaY = abs(pessoa.getPosicaoY() - posto.getPosicaoY());

    return sqrt(pow(diferencaX, 2) + pow(diferencaY, 2));
}
