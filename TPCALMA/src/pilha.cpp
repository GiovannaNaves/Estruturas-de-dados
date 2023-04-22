#include "pilha.hpp"

Pilha<T>::Pilha(){
    tamanho = 0;
    topo = -1;
};

int Pilha<T>::GetTamanho() {return tamanho;};

bool Pilha<T>::Vazia() {return tamanho == 0;};

void Pilha<T>::Empilha(TipoItem item){
    if(tamanho == MAXTAM)
        throw "A pilha está cheia!";

    topo++;
    itens[topo] = item;
    tamanho++;

};

T Pilha::Desempilha() {
    TipoItem aux;
    
    if(tamanho == 0)
        throw "A pilha está vazia!";
    
    aux = itens[topo]
    topo--;
    tamanho--;
    return aux;;
};

void Pilha::Limpa() {
    topo = -1
    tamanho = 0;
};
