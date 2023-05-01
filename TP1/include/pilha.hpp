#ifndef PILHA_H
#define PILHA_H
#include "arvore.hpp"
template <typename T>
class Pilha{
    public:
        Pilha();

        int GetTamanho();

        bool Vazia();

        void Empilha(T item);

        T Desempilha();

        void Limpa();

        T Topo();

    protected:
        int tamanho;
        int topo;
        static const int MAXTAM = 100;
        T itens[MAXTAM];
};

template class Pilha<std::string>;
template class Pilha<No*>;

#endif