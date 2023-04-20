        Pilha::Pilha(){
            tamanho = 0;
            topo = -1;
        };

        int Pilha::GetTamanho() {return tamanho;};

        bool Pilha::Vazia() {return tamanho == 0;};

        virtual void Pilha::Empilha(TipoItem item){
            if(tamanho == MAXTAM)
                throw "A pilha está cheia!";

            topo++;
            itens[topo] = item;
            tamanho++;

        };
        
        virtual TipoItem Pilha::Desempilha() {
            TipoItem aux;
            
            if(tamanho == 0)
                throw "A pilha está vazia!";
            
            aux = itens[topo]
            topo--;
            tamanho--;
            return aux;;
        };

        virtual void Pilha::Limpa() {
            topo = -1
            tamanho = 0;
        };
