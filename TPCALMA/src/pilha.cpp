#include "pilha.hpp"

template <typename T>
Pilha<T>::Pilha(){
    tamanho = 0;
    topo = -1;
};

template <typename T>
int Pilha<T>::GetTamanho() {return tamanho;};

template <typename T>
bool Pilha<T>::Vazia() {return tamanho == 0;};

template <typename T>
void Pilha<T>::Empilha(TipoItem item){
    if(tamanho == MAXTAM)
        throw "A pilha está cheia!";

    topo++;
    itens[topo] = item;
    tamanho++;

};

template <typename T>
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
