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
            std::vector<Pessoa> PessoasAlocadas;

            void validarParametros();
            bool atingiuCapacidadeMaxima();

        public:
            Posto();
            Posto(int id, int capacidade, int posicaoX, int posicaoY);
            ~Posto();

            int getId();
            int getCapacidade();
            int getPosicaoX();
            int getPosicaoY();
            std::vector<Pessoa> getPessoasAlocadas();

            bool alocarPessoa(Pessoa pessoa);
            bool temVaga();
    };
}

#endif
