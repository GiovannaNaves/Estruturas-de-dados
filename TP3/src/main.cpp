#include <iostream>
#include <fstream>
#include <string>
#include "queue.hpp"
#include "huffman.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    // Error if there's no file's name
    if (argc < 2)
    {
        std::cerr << "Erro: Nenhum arquivo encontrado" << std::endl;
        return 1;
    }
        
    // Gets the file's name
    std::string filename(argv[1]);

    // Opens the file
    std::ifstream infile(filename);

    // Checks if the file's open
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
    Huffman h; 
    h.buildHuffmanTree(text);

    return 0;
}