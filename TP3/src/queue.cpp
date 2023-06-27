#include "queue.hpp"
#include <cstddef>

template <typename T>
FilaEncadeada<T>::FilaEncadeada(){
    frente = new Node;
    tras = frente;
    tamanho = 0;
}

template <typename T>
FilaEncadeada<T>::~FilaEncadeada(){
    Limpa();
    delete frente;
}

template <typename T>
void FilaEncadeada<T>::Enfileira(T item){
    Node *nova;

    nova  = new Node();
    nova->ch = item.ch;
    nova->freq= item.freq;

    tras->right = nova;
    tras = nova;
    tamanho++;

}

template <typename T>
int FilaEncadeada<T>::Desenfileira(){
    if (tamanho == 0)
        throw "Fila vazia!";
    
    Node* p = frente->right;
    int aux = p->ch;
    frente->right = p->right;
    
    if (p == tras)
        tras = frente;
    delete p;
    tamanho--;
    return aux;
}

template <typename T>
void FilaEncadeada<T>::Limpa(){
    Node *p;

    p = frente->right;
    while(p!= NULL){
        frente->right = p->right;
        delete p;
        p = frente->right;
    }

    tamanho = 0;
    tras = frente;
}

template <typename T>
T FilaEncadeada<T>::GetFrente(){
    return frente->right->ch;
} 