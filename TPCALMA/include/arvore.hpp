//implementação geral de uma arvore
#pragma once

#include <string>

class ArvoreExp {
public:
    struct No {
        std::string valor;
        No* esq;
        No* dir;
    }

    ArvoreExp();
    ~ArvoreExp();

    void ConstruirArvore(std::string);
    float Resolver();

private:
    TipoNo* raiz;    
}