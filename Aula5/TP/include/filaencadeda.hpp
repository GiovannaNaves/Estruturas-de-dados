#ifndef FILA_ENC_H
#define FILA_ENC_H
#include "fila.hpp"
#include "tipocelula.hpp"

template< typename Tipo>
class FilaEncadeada : public Fila { 
    public: FilaEncadeada(); 
        virtual ~FilaEncadeada(); 

        void Enfileira(TipoItem item); 
        TipoItem Desenfileira(); 
        void Limpa(); 

    private: 
        TipoCelula* frente; 
        TipoCelula* tras; 
};

#endif