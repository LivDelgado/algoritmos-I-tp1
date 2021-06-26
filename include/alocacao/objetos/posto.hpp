#ifndef POSTO
#define POSTO

namespace alocacao {
    class Posto {
        private:
            int Id;
            int Capacidade;
            int PosicaoX;
            int PosicaoY;
        public:
            Posto();
            Posto(int id, int capacidade, int posicaoX, int posicaoY);
            ~Posto();
    };
}

#endif
