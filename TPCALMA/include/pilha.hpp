#pragma once
template <typename T>
class Pilha
{
public:
    Pilha();

    int GetTamanho();

    bool Vazia();

    void Empilha(T item);

    T Desempilha();

    void Limpa();

    T Topo() { return topo; }

protected:
    int tamanho;
    T topo;
    static const int MAXTAM = 100;
    T itens[MAXTAM];
};
