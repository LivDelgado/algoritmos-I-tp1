#ifndef LEITOR
#define LEITOR

#include <iostream>

#include "alocacao/objetos/pessoa.hpp"
#include "alocacao/objetos/posto.hpp"

namespace leitura {
    class Leitor {
        private:
            alocacao::Pessoa* pessoas;
            alocacao::Posto* postos;
        public:
            Leitor();
            ~Leitor();

            void instanciarObjetos();
            alocacao::Pessoa* getPessoas();
            alocacao::Posto* getPostos();
    };
}

#endif
