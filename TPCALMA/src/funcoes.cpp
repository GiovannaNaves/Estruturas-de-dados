#include <string>
#include "funcoes.hpp"

// se LER: armazenar a exp
std::string Funcoes::TransformaEmPosfixo(std::string infixo) {
    Pilha<char> pilhaOp;
    std::string posfixo_final;
    std::string elemento;

    std::istringstream iss(infixo);
    while (iss >> elemento) {
        if (std::isspace(elemento)) {
            // pula espaços em branco
            continue;  
        }
        else if (std::isdigit(elemento)) { // ver se funciona
            //  se nao funcionar é só trocar isdigit por outro que aceite float

            // adiciona operando na saída
            posfixo_final += elemento;  
        }
        else {
            bool pilhaNaoVazia = !pilhaOp.Vazia();
            bool topoNaoEhAbreParenteses = pilhaOp.Topo() != '(';
            bool precedenciaOk = precedence(elemento) <= precedence(pilhaOp.Topo());

            while (pilhaNaoVazia && topoNaoEhAbreParenteses && precedenciaOk) {
                // adiciona operador à saída
                posfixo_final += pilhaOp.Desempilha();
            }
            if (c == ')') {
                if (!pilhaOp.Vazia() && pilhaOp.Topo() == '(') {
                    pilhaOp.Desempilha();  // remove o '(' do topo da pilha
                }
                else {
                    throw std::invalid_argument("expressão inválida: parênteses não correspondentes");
                }
            }
            else {
                // Adiciona operadores à pilha
                pilhaOp.Empilha(elemento);
            }
        }
    }

    while (!pilhaOp.Vazia()) {
        if (pilhaOp.Topo() == '(') {
            throw std::invalid_argument("expressão inválida: parênteses não correspondentes");
        }
        // Adiciona operadores restantes à saída
        posfixo_final += pilhaOp.Desempilha(); 
    }

    return posfixo_final;
}

