//implementação geral de uma pilha

class Pilha
{
    public:
        Pilha(){
            tamanho = 0;
            topo = -1;
        };

        int GetTamanho() {return tamanho;};

        bool Vazia() {return tamanho == 0;};

        virtual void Empilha(TipoItem item){
            if(tamanho == MAXTAM)
                throw "A pilha está cheia!";

            topo++;
            itens[topo] = item;
            tamanho++;

        };
        
        virtual TipoItem Desempilha() {
            TipoItem aux;
            
            if(tamanho == 0)
                throw "A pilha está vazia!";
            
            aux = itens[topo]
            topo--;
            tamanho--;
            return aux;;
        };

        virtual void Limpa() {
            topo = -1
            tamanho = 0;
        };


    protected:
        int tamanho;
        int topo;
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];

};
