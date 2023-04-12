#include "filaencadeada.hpp"
#include "fila.hpp"

FilaEncadeada::FilaEncadeada(){
    frente = new TipoCelula;
    tras = frente;
}

FilaEncadeada::~FilaEncadeada(){
    Limpa();
    delete frente;
}

void FilaEncadeada::Enfileira(int item){
    TipoCelula *nova;

    nova  = new TipoCelula();
    nova->item = item;
    tras->prox = nova;
    tras = nova;
    tamanho++;

}

int FilaEncadeada::Densenfileira(){
    TipoCelula *p;
    int aux;

    if(tamanho == 0) throw "Fila vazia!";

    aux = frente->prox->item;
    p = frente;
    frente = frente->prox;
    delete p;
    tamanho--;
    return aux;
}

void FilaEncadeada::Limpa(){
    TipoCelula *p;

    p = frente->prox;
    while(p!= NULL){
        frente->prox = p->prox;
        delete p;
        p = frente->prox;
    }

    tamanho = 0;
    tras = frente;
}

TipoCelula* FilaEncadeada::GetFrente(){
    return frente;
}