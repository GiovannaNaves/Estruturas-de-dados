#include <iostream>
#include "pilha.hpp"

template <typename T>
Pilha<T>::Pilha()
{
    this->tamanho = 0;
    this->topo = -1;
};

template <typename T>
int Pilha<T>::GetTamanho() { 
    return this->tamanho; 
};

template <typename T>
bool Pilha<T>::Vazia() { 
    return this->tamanho == 0;
};

template <typename T>
void Pilha<T>::Empilha(T item)
{
    if (tamanho == MAXTAM)
        throw "A pilha está cheia!";

    this->topo++;
    this->itens[topo] = item;
    this->tamanho++;
};

template <typename T>
T Pilha<T>::Desempilha()
{
    T aux;

    if (tamanho == 0)
        throw "A pilha está vazia!";

    aux = this->itens[topo];
    this->topo--;
    this->tamanho--;
    return aux;
    ;
};

template <typename T>
void Pilha<T>::Limpa()
{
    this->topo = -1;
    this->tamanho = 0;
};

template <typename T>
T Pilha<T>::Topo() { 
    return itens[topo]; 
};