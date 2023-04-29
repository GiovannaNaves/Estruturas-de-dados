#include <iostream>
#include "arvore.hpp"
#include "pilha.hpp"

bool isOperator(std::string c)
{
    return c == "+" || c == "-" || c == "*" || c == "/";
}

void ArvoreExp::ConstruirArvore(std::string exp)
{
    Pilha<ArvoreExp::No *> p = Pilha<ArvoreExp::No *>();

    for (auto e : exp)
    {
        std::string elemento(1, e);
        ArvoreExp::No *no = new ArvoreExp::No(elemento);

        if (isOperator(elemento))
        {
            no->dir = p.Desempilha();
            no->esq = p.Desempilha();
        }

        p.Empilha(no);
    }

    this->raiz = p.Pilha::Desempilha();
}

double ArvoreExp::Resolver(No *node)
{
    if (node->left == nullptr && node->right == nullptr) {
        // O nó é um operando
        return stod(node->value);
    } else {
        // O nó é um operador
        double leftValue = evaluate(node->left);
        double rightValue = evaluate(node->right);
        if (node->value == "+") {
            return leftValue + rightValue;
        } else if (node->value == "-") {
            return leftValue - rightValue;
        } else if (node->value == "*") {
            return leftValue * rightValue;
        } else if (node->value == "/") {
            return leftValue / rightValue;
        } else {
            throw runtime_error("Operador inválido");
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