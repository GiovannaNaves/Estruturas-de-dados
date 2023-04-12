#ifndef TIPO_CELULA_H
#define TIPO_CELULA_H

template< typename Tipo>
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
};

#endif