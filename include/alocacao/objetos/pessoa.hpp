#ifndef PESSOA
#define PESSOA

namespace alocacao {
    class Pessoa {
        private:
            int Id;
            int Idade;
            int PosicaoX;
            int PosicaoY;
            int PostoEmQueIraVacinar;

            void validarParametros();

        public:
            Pessoa();
            Pessoa(int id, int idade, int posicaoX, int posicaoY);
            ~Pessoa();

            int getId();
            int getIdade();
            int getPosicaoX();
            int getPosicaoY();
            int getPostoEmQueIraVacinar();

            void alocarAPosto(int posto);
            bool alocada();
    };
}

#endif
