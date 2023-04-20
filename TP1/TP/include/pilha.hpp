

template<class T>
class Pilha {
    private:
        T *PilhaArray;
        int top;
        int tamanho;

    public:

        Pilha(){
            tamanho = 0;
        }

        int GetTamanho() {
            return tamanho;
        }

        //bool Vazia() {return tamanho == 0;};

        //virtual void Empilha(TipoItem item) = 0;
        //virtual TipoItem Desempilha() = 0;
        //virtual void Limpa() = 0;

        // Construtor da classe
        Pilha(int tamanho) {
            PilhaArray = new T[tamanho];
            top = -1;
            this->tamanho = tamanho;
        }

        // Destrutor da classe
        ~Pilha() {
            delete[] PilhaArray;
        }

        // Método para empilhar um itemo na pilha
        void Empilha(T item) {
            if (top == tamanho - 1) {
                cout << "A pilha está cheia!" << endl;
            }
            else {
                top++;
                PilhaArray[top] = item;
            }
        }

        // Método para desempilhar um itemo da pilha
        T Desempilha() {
            if (top == -1) {
                cout << "A pilha está vazia!" << endl;
                return NULL;
            }
            else {
                T item = PilhaArray[top];
                top--;
                return item;
            }
        }

        // Método para verificar se a pilha está vazia
        bool isEmpty() {
            return top == -1;
        }
};