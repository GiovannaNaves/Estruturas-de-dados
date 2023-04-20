//implementação geral de uma pilha

class Pilha
{
    public:
        Pilha();

        int GetTamanho() {return tamanho;};

        bool Vazia() {return tamanho == 0;};

        virtual void Empilha(TipoItem item);
        
        virtual TipoItem Desempilha();

        virtual void Limpa()};


    protected:
        int tamanho;
        int topo;
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];

};
