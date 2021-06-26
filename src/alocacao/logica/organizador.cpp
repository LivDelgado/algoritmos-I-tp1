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
        this->ordernarPostosDistanciaPessoa();

        // itera sobre os postos para achar o primeiro com vaga
        int i = 0;
        for (Posto & posto : this->Postos) {
            if (posto.temVaga()) {
                AtualDaFila.alocarAPosto(posto.getId());
                posto.alocarPessoa(AtualDaFila);
                break;
            }
            i++;
        }

        // buscando otimizar as execuções
        // na primeira vez que rodar após acabarem as vagas ele encerra a iteração
        if ((i == (int)this->Postos.size() - 1) && !pessoa.alocada()) {
            break;
        } 
    }
}

void Organizador::ordenarPostosPorId() {
    std::sort(this->Postos.begin(), this->Postos.end(),
        [](Posto &a, Posto &b) -> bool {
            return a.getId() < b.getId();
        }
    );
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
        if (!posto.getPessoasAlocadas().empty()) {
            std::cout << posto.getId() << std::endl;
            int i = 0;
            for (Pessoa pessoa : posto.getPessoasAlocadas()) {
                std::cout << pessoa.getId();
                i++;
                if (i < (int)posto.getPessoasAlocadas().size())
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

double Organizador::calcularDistancia(Pessoa pessoa, Posto posto) {
    unsigned int diferencaX = abs(pessoa.getPosicaoX() - posto.getPosicaoX());
    unsigned int diferencaY = abs(pessoa.getPosicaoY() - posto.getPosicaoY());

    return sqrt(pow(diferencaX, 2) + pow(diferencaY, 2));
}
