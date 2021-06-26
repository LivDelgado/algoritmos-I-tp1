#ifndef ORGANIZADOR
#define ORGANIZADOR

#include "alocacao/objetos/pessoa.hpp"
#include "alocacao/objetos/posto.hpp"

namespace alocacao {
    class Organizador {
        private:
            Pessoa* pessoas;
            Posto* postos;

            void lerInformacoesEntrada();
        public:
            Organizador();
            ~Organizador();

            void iniciarVacinacao();
    };
}

#endif
