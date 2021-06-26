#ifndef ORGANIZADOR
#define ORGANIZADOR

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

#include "alocacao/objetos/pessoa.hpp"
#include "alocacao/objetos/posto.hpp"

namespace alocacao
{
    class Organizador {
        private:
            std::vector<Pessoa> Pessoas;
            std::vector<Posto> Postos;

            Pessoa AtualDaFila;

            void lerInformacoesEntrada();
            void organizarFilaPrioridade();
            void alocarPessoasAPostos();
            void imprimirAlocacao();

            double calcularDistancia(Pessoa & pessoa, Posto & posto);
            Posto* obterPostoComMenorDistanciaPessoa(Pessoa pessoa);

        public:
            Organizador();
            ~Organizador();

            void iniciarVacinacao();
    };
}

#endif
