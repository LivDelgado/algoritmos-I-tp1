#ifndef LEITOR
#define LEITOR

#include <iostream>
#include <vector>

#include "alocacao/objetos/pessoa.hpp"
#include "alocacao/objetos/posto.hpp"

namespace leitura {
    class Leitor {
        private:
            std::vector<alocacao::Pessoa> Pessoas;
            std::vector<alocacao::Posto> Postos;

            void instanciarPostos();
            void instanciarPessoas();

            void validarNumeroTotalPostos(int numeroTotalPostos);
            void validarNumeroTotalPessoas(int numeroTotalPessoas);

        public:
            Leitor();
            ~Leitor();

            void instanciarObjetos();
            std::vector<alocacao::Pessoa> getPessoas();
            std::vector<alocacao::Posto> getPostos();
    };
}

#endif
