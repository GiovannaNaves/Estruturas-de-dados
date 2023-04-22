// implementação geral de uma pilha

template <typename T>
class Pilha
{
public:
    Pilha();

    int GetTamanho() { return tamanho; };

    bool Vazia() { return tamanho == 0; };

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
