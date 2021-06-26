#ifndef PESSOA
#define PESSOA

namespace alocacao {
    class Pessoa {
        private:
            int Id;
            int Idade;
            int PosicaoX;
            int PosicaoY;
        public:
            Pessoa();
            Pessoa(int id, int idade, int posicaoX, int posicaoY);
            ~Pessoa();
    };
}

#endif
