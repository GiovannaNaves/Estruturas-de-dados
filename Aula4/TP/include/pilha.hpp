#ifndef PILHA_H
#define PILHA_H

#include "filaencadeada.hpp"

class Pilha{
    public:
        Pilha();
        void PilhaVazia();
        void Empilhar(int p);
        int Desempilhar();
        int GetTopo();
        int GetTamanho();
        void Limpa();
    private:
        FilaEncadeada* primeira_fila;
};

#endif