#ifndef FILA_H
#define FILA_H

#include <bits/stdc++;h>

using namespace std;

template< typename tipo>
class Fila{
    public:
        Fila(){tamanho=0;};
        int GetTamanho(){return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Enfileira(TipoItem item) = 0; 
        virtual TipoItem Desenfileira() = 0; 
        virtual void Limpa() = 0; 
        protected: int tamanho; 
};

#endif