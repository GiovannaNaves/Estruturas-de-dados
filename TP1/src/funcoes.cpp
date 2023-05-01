#include <string>
#include <sstream>
#include <iostream>

#include "funcoes.hpp"
#include "pilha.hpp"

int precedencia(const std::string &op)
{
    if (op == "(") {
        return 3;
    }
    else if (op == "*" || op == "/")
    {
        return 2;
    }
    else if (op == "+" || op == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// se LER: armazenar a exp
std::string Funcoes::TransformaEmPosfixo(std::string infixo)
{
    Pilha<std::string> pilhaOp;
    std::string posfixo_final;
    std::string elemento;

    std::istringstream iss(infixo);

    while (iss >> elemento)
    {
        if (std::isspace(elemento[0]))
        {
            // pula espaços em branco
            continue;
        }
        else if (elemento == "INFIXA")
        {
            // pula a flag de infixa
            continue;
        }
        else if (std::isdigit(elemento[0]))
        {
            std::string numero_atual;
            numero_atual += elemento;
            posfixo_final += numero_atual + " ";
        }
        else
        {
            while (!pilhaOp.Vazia() && pilhaOp.Topo() != "(" && precedencia(elemento) <= precedencia(pilhaOp.Topo()))
            {
                // adiciona operador à saída
                posfixo_final += pilhaOp.Desempilha() + " ";
            }

            if (elemento == ")")
            {
                if (!pilhaOp.Vazia() && pilhaOp.Topo() == "(")
                {
                    pilhaOp.Desempilha(); // remove o '(' do topo da pilha
                }
                else
                {
                    std::cout << "Expressão inválida: parênteses não correspondentes" << std::endl;
                }
            }
            else
            {
                // Adiciona operadores à pilha
                pilhaOp.Empilha(elemento);
            }
        }
    }

    while (!pilhaOp.Vazia())
    {
        if (pilhaOp.Topo() == "(")
        {
            std::cout << "Expressão inválida: parênteses não correspondentes ELE TA AQUI" << std::endl;
        }
        // Adiciona operadores restantes à saída
        posfixo_final += pilhaOp.Desempilha();
    }

    return posfixo_final;
}
