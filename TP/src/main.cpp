#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "pilha.hpp"
#include "arvore.hpp"
#include "funcoes.hpp"

int main(int argc, char *argv[])
{
    
    // Se não der nome do arquivo -> erro
    if (argc < 2)
    {
        std::cerr << "Erro: Nenhum arquivo encontrado" << std::endl;
        return 1;
    }

    // Pega o nome do arquivo
    std::string filename(argv[1]);

    // Abre o arquivo
    std::ifstream infile(filename);

    // Checa se abriu
    if (!infile.is_open())
    {
        std::cout << "Erro: não foi possível abrir o arquivo" << filename << std::endl;
        return 1;
    }

    // Le linha por linha
    std::string line;
    std::string exp;
    ArvoreExp arvore = ArvoreExp();

    while (std::getline(infile, line))
    {
        // lendo a primeira linha
        if (line[0] == 'L')
        {
            // Por padrao identificamos como pos
            std::string tipo = "POSFIXA";
            exp = "";

            // Lendo a primeira linha
            std::istringstream iss(line);
            std::string token;
            iss >> token; // 'LER' token
            iss >> token; // 'INFIXA'/'POSFIXA' token
            std::getline(iss, exp);

            // Se houver um parenteses então é infixa

            if (exp.find("(") != std::string::npos){
                tipo = "INFIXA";
            }

            if (tipo != token)
            {
                std::cout << "Expressão inválida: tipo da expressão não correspondente." << std::endl;
                break;
            }
            
           
            // Se pre transforma em pos
            if (tipo == "INFIXA")
            {
                Funcoes exp_nova;
                exp = exp_nova.TransformaEmPosfixo(exp);
            }
            // Aqui temos a expressao como pós -> construir a arvore
            arvore.ConstruirArvore(exp);
        }

        // lendo a segunda linha
        else if (line[0] == 'I')
        {
            std::cout << "INFIXA : ";
            arvore.PrintarEmOrdem(arvore.getRaiz());
            std::cout << std::endl;
        }
        else if (line[0] == 'P')
        {
            std::cout << "POSFIXA: ";
            std::cout << exp << std::endl;
            // arvore.PrintarPosOrdem(arvore.getRaiz()); -> seria uma outra opção
        }
        else if (line[0] == 'R')
        {
            std::cout << "VAL: ";
            double resolvida = arvore.Resolver(arvore.getRaiz());
            std::cout << resolvida << std::endl;
        }
    }

    // Close the input file
    infile.close();

    return 0;
}
