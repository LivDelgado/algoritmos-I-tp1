#ifndef POSTO
#define POSTO

#include <vector>

#include "alocacao/objetos/pessoa.hpp"

namespace alocacao {
    class Posto {
        private:
            int Id;
            int Capacidade;
            int PosicaoX;
            int PosicaoY;
            int* PessoasAlocadas;
            int NumeroPessoasAlocadas;

            void validarParametros();
        public:
            Posto();
            Posto(int id, int capacidade, int posicaoX, int posicaoY);
            ~Posto();

            int getId();
            int getCapacidade();
            int getPosicaoX();
            int getPosicaoY();
            int* getPessoasAlocadas();
            int getNumeroPessoasAlocadas();

            void alocarPessoa(int idPessoa);
            bool temVaga();
    };
}

#endif
