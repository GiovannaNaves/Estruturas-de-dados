#ifndef FILA_ENC_H
#define FILA_ENC_H
#include "fila.hpp"
#include "tipocelula.hpp"

class FilaEncadeada : public Fila { 
    public: FilaEncadeada(); 
        virtual ~FilaEncadeada(); 
        void Enfileira(int item); 
        int Desenfileira(); 
        void Limpa(); 
        TipoCelula* GetFrente();

    private: 
        TipoCelula* frente; 
        TipoCelula* tras; 
};

#endif