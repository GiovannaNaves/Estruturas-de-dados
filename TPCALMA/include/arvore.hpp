// implementação geral de uma arvore
#pragma once

#include <string>

class ArvoreExp
{
public:
    struct No
    {
        std::string valor;
        No *esq;
        No *dir;

        // Constructor to initialize the member variables
        No(const std::string &valor, No *esq = nullptr, No *dir = nullptr)
            : valor(valor), esq(esq), dir(dir)
        {
        }
    };

    ArvoreExp() {}
    ~ArvoreExp() {}

    void ConstruirArvore(std::string);
    void PrintarEmOrdem(No *node);
    void PrintarPosOrdem(No *node);
    double Resolver(No *node);
    No* getRaiz() const{
        return raiz;
    }

private:
    No *raiz;
};