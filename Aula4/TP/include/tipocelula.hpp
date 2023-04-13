#ifndef TIPO_CELULA_H
#define TIPO_CELULA_H

class TipoCelula { 
    public: 
        TipoCelula(){ 
            item = -1; 
            prox = NULL; 
        } 
        
    private: 
        int item; 
        TipoCelula *prox; 
        friend class FilaEncadeada; 
        friend class Pilha; 
};

#endif