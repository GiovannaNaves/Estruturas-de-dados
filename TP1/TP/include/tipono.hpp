#ifndef TIPO_NO_H
#define TIPO_NO_H

class TipoNo
{
    public:
        TipoNo(char item){
            this->item = item;
            esq = NULL;
            dir = NULL;
        }

        ~TipoNo(){
            delete esq;
            delete dir;
        }
        
    private:
        char item;
        TipoNo *esq;
        TipoNo *dir;

    friend class ArvoreBinaria;
};

#endif