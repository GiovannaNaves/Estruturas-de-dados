#include "fila.hpp"
#include "pilha.hpp"
  
Pilha::Pilha(){
    topo = NULL;
    tamanho = 0;
}

void Pilha::PilhaVazia(){
    topo = NULL;
    tamanho = 0;
}

void Pilha::Empilhar(int p){
    TipoCelula<int> *nova = new TipoCelula<int>();
    nova->item = p;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

int Pilha::Desempilhar(){
    if(tamanho == 0) throw "Pilha vazia!";
    TipoCelula<int> *p = topo;
    int aux = topo->item;
    topo = topo->prox;
    delete p;
    tamanho--;
    return aux;
}

int Pilha::GetTopo(){
    if(tamanho == 0) throw "Pilha vazia!";
    return topo->item;
}

int Pilha::GetTamanho(){
    return tamanho;
}

void Pilha::Limpa(){
    TipoCelula<int> *p;
    while(topo != NULL){
        p = topo;
        topo = topo->prox;
        delete p;
    }
    tamanho = 0;
}