#include <string>
#include <sstream>
#include <iostream>
#include "funcoes.hpp"
#include "pilha.hpp"

int precedence(const std::string &op)
{
    if (op == "*" || op == "/")
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
    Pilha<std::string> pilhaOp();
    std::string posfixo_final;
    std::string elemento;

    std::istringstream iss(infixo);
    while (iss >> elemento)
    {
        if (std::isspace(static_cast<unsigned char>(elemento[0])))
        {
            // pula espaços em branco
            continue;
        }
        else if (std::isdigit(static_cast<unsigned char>(elemento[0])))
        { // ver se funciona
            std::string numero_atual;
            numero_atual += elemento;

            while (iss >> elemento && !std::isspace(static_cast<unsigned char>(elemento[0])))
            {
                numero_atual += elemento;
            }

            posfixo_final += numero_atual + " ";
        }
        else
        {
            bool pilhaNaoVazia = !pilhaOp.Vazia();
            bool topoNaoEhAbreParenteses = pilhaOp.Topo() != "(";
            bool precedenciaOk = precedence(elemento) <= precedence(pilhaOp.Topo());

            while (pilhaNaoVazia && topoNaoEhAbreParenteses && precedenciaOk)
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
                    // throw std::invalid_argument("expressão inválida: parênteses não correspondentes");
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
            // throw std::invalid_argument("expressão inválida: parênteses não correspondentes");
        }
        // Adiciona operadores restantes à saída
        posfixo_final += pilhaOp.Desempilha();
    }

    return posfixo_final;
}
