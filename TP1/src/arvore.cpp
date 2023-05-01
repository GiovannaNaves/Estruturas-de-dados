#include <iostream>
#include <sstream>

#include "arvore.hpp"
#include "pilha.hpp"

bool isOperator(std::string c)
{
    return c == "+" || c == "-" || c == "*" || c == "/";
}

void ArvoreExp::ConstruirArvore(std::string exp)
{
    Pilha<No *> p = Pilha<No *>();

    std::stringstream ss(exp);
    std::string token;
    while (ss >> token) {
        No *no = new No(token);
        if (no == nullptr) {
            std::cout << "Falha na alocacao de memoria para No." << std::endl;
        }
        if (isOperator(token))
        {
            no->dir = p.Desempilha();
            no->esq = p.Desempilha();
        }

        p.Empilha(no);
    }

    this->raiz = p.Desempilha();
}

double ArvoreExp::Resolver(No *node)
{
    if (node->esq == nullptr && node->dir == nullptr) {
        // O nó é um operando
        return std::stod(node->valor);
    } else {
        // O nó é um operador
        double leftValue = Resolver(node->esq);
        double rightValue = Resolver(node->dir);
        if (node->valor == "+") {
            return leftValue + rightValue;
        } else if (node->valor == "-") {
            return leftValue - rightValue;
        } else if (node->valor == "*") {
            return leftValue * rightValue;
        } else if (node->valor == "/") {
            return leftValue / rightValue;
        } else {
            throw std::runtime_error("Operador inválido");
        }
    }
}

void ArvoreExp::PrintarPosOrdem(No *node)
{
    if (node->esq != NULL)
    {
        return PrintarPosOrdem(node->esq);
    }

    if (node->dir != NULL)
    {
        return PrintarPosOrdem(node->dir);
    }

    std::cout << node->valor << " ";
}

void ArvoreExp::PrintarEmOrdem(No *node)
{
    std::cout << "( ";

    if (node->esq != NULL)
    {
        return PrintarEmOrdem(node->esq);
    }

    std::cout << node->valor << " ";

    if (node->dir != NULL)
    {
        return PrintarEmOrdem(node->dir);
    }

    std::cout << ") ";
}