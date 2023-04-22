#include <iostream>
#include <fstream>
#include <string>

#include "arvore.hpp"


int main(int argc, char* argv[]) {
    // Se não der nome do arquivo -> erro
    if (argc < 2) {
        std::cerr << "Error: Nenhum arquivo encontrado" << std::endl;
        return 1;
    }

    // Pega o nome do arquivo
    std::string filename(argv[1]);

    // Abre o arquivo
    std::ifstream infile(filename);

    // Checa se abriu
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }

    // Le linha por linha
     std::string line;
     std::string exp;
     ArvoreExp arvore = ArvoreExp();
     while (std::getline(infile, line)) {
          

        if (line[0] == "L") {
          // Por padrao identificamos como pos
          std::string tipo = "pos";

          // Posição do inicio da exp
          int comeco_exp = line.find_first_not_of(" \t", 3);

          // Se houver um parenteses então é prefixo
          if (line[comeco_exp] == "(")
               tipo = "pre";
          
          // Guarda a expressao
          exp = line.substr(comeco_exp);

          // Se pre transforma em pos
          if (tipo == "pre") {
               exp = TransformaEmPosfixo(exp);
          }

          // Aqui temos a expressao como pós -> construir a arvore
          arvore.ConstruirArvore(exp);

        } else if (line[0] == "I") {

        } else if (line[0] == "P") {

        } else if (line[0] == "R") {

        } 
        
    }

    // Close the input file
    infile.close();

    return 0;
}
