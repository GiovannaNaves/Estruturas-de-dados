#include <iostream>
#include <fstream>
#include <string>
#include "queue.hpp"
#include "huffman.cpp"

using namespace std;

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

    std::string text;
    std::string line;
    while (std::getline(infile, line))
    {
        text += line;
    }

    buildHuffmanTree(text);

    return 0;
}