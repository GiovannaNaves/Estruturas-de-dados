#ifndef ARVORE_H
#define ARVORE_H
#include <string>

struct No
{
    std::string valor;
    No *esq;
    No *dir;

    // Construtor para iniciar as variaveis
    No(const std::string &valor, No *esq = nullptr, No *dir = nullptr)
        : valor(valor), esq(esq), dir(dir)
    {
    }
};

class ArvoreExp
{
public:
    ArvoreExp(){};
    ~ArvoreExp(){};

    void ConstruirArvore(std::string);
    void PrintarEmOrdem(No *node);
    void PrintarPosOrdem(No *node);

    double Resolver(No *node);
    No *getRaiz();

private:
    No *raiz;
};

#endif