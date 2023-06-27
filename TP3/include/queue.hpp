#ifndef FILA_ENC_H
#define FILA_ENC_H

struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

template <typename T>
class FilaEncadeada { 
    public: 
        FilaEncadeada(); 
        virtual ~FilaEncadeada(); 
        void Enfileira(T item); 
        int Desenfileira(); 
        void Limpa(); 
        T GetFrente();

        int GetTamanho(){
            return tamanho;
        };
        bool Vazia() {
            return tamanho == 0;
        };

    private: 
        int tamanho;
        Node* frente; 
        Node* tras; 
};

#endif