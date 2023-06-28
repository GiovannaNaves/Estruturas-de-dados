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
        T GetFrente(){
            return frente->right;
        };
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

template <typename T>
FilaEncadeada<T>::FilaEncadeada(){
    frente = new Node;
    tras = frente;
    tamanho = 0;
}

template <typename T>
FilaEncadeada<T>::~FilaEncadeada(){
    Limpa();
    delete frente;
}

template <typename T>
void FilaEncadeada<T>::Enfileira(T item){
    Node *nova;

    nova  = new Node();
    nova->ch = item->ch;
    nova->freq= item->freq;

    tras->right = nova;
    tras = nova;
    tamanho++;

}

template <typename T>
int FilaEncadeada<T>::Desenfileira(){
    if (tamanho == 0)
        throw "Fila vazia!";
    
    Node* p = frente->right;
    int aux = p->ch;
    frente->right = p->right;
    
    if (p == tras)
        tras = frente;
    delete p;
    tamanho--;
    return aux;
}

template <typename T>
void FilaEncadeada<T>::Limpa(){
    Node *p;

    p = frente->right;
    while(p!= NULL){
        frente->right = p->right;
        delete p;
        p = frente->right;
    }

    tamanho = 0;
    tras = frente;
}

#endif