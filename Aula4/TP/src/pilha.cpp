#include "pilha.hpp"
  

Pilha::Pilha(){
    primeira_fila = new FilaEncadeada();
}

void Pilha::PilhaVazia(){
    if(primeira_fila->Vazia())
        cout << "Pilha vazia!" << endl;
    else
        cout << "Pilha nao vazia!" << endl;
}

void Pilha::Empilhar(int p){
    primeira_fila->Enfileira(p);
}

int Pilha::Desempilhar(){
    FilaEncadeada *nova_fila;
    TipoCelula *p, *q;
    int aux;

    if(primeira_fila->Vazia()) throw "Pilha vazia!";

    nova_fila = new FilaEncadeada();

    p = primeira_fila->GetFrente();
    while(p->prox != NULL){
        q = p->prox;
        nova_fila->Enfileira(q->item);
        p = p->prox;
    }

    aux = p->item;
    nova_fila->Enfileira(aux);
    primeira_fila->Limpa();

    p = nova_fila->GetFrente();
    while(p->prox != NULL){
        q = p->prox;
        primeira_fila->Enfileira(q->item);
        p = p->prox;
    }

    delete nova_fila;

    return aux;
}

int Pilha::GetTopo(){
    FilaEncadeada *nova_fila;
    TipoCelula *p, *q;
    int aux;

    if(primeira_fila->Vazia()) throw "Pilha vazia!";

    nova_fila = new FilaEncadeada();

    p = primeira_fila->GetFrente();
    while(p->prox != NULL){
        q = p->prox;
        nova_fila->Enfileira(q->item);
        p = p->prox;
    }

    aux = p->item;

    p = nova_fila->GetFrente();
    while(p->prox != NULL){
        q = p->prox;
        primeira_fila->Enfileira(q->item);
        p = p->prox;
    }

    delete nova_fila;

    return aux;
}

int Pilha::GetTamanho(){
    return primeira_fila->GetTamanho();
}

void Pilha::Limpa(){
    primeira_fila->Limpa();
}