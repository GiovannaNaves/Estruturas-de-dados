#include <iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include <sys/resource.h>
#include "queue.hpp"
#include "huffman.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    char action;

    for(int i=1; i<argc; i++){
        char option = argv[i][1];
        try{
            switch(option){
                case 'c':
                    action = 'c';
                    break;
                case 'd':
                    action = 'd';
                    break;
            }
        }
        catch (...){}

    }
    // Error if there's no file's name
    if (argc < 2)
    {
        std::cerr << "Erro: Nenhum arquivo encontrado" << std::endl;
        return 1;
    }
        
    // Gets the input and the output files' name
    std::string filename(argv[2]);
    std::string outputFilename(argv[3]);

    // Create the name of descompression key file
    std::string keyFilename;
    if (action == 'c') keyFilename = outputFilename.substr(0, outputFilename.find_last_of('.')) + "key.txt";
    if (action == 'd') keyFilename = filename.substr(0, filename.find_last_of('.')) + "key.txt";
    // Checks if the file's open

    std::string text;
    std::string line;
    
    // clock_t start, end; 
    struct rusage start_ru, end_ru;
    struct timespec start_clock, end_clock;
    double timeElapsed[4];

        getrusage(RUSAGE_SELF, &start_ru);
        clock_gettime(CLOCK_MONOTONIC, &start_clock);

    
    Huffman h; 
        h.buildHuffmanTree(filename, keyFilename, outputFilename, action);

        getrusage(RUSAGE_SELF, &end_ru);
        clock_gettime(CLOCK_MONOTONIC, &end_clock);
        
        timeElapsed[3] = (end_clock.tv_sec - start_clock.tv_sec) + (end_clock.tv_nsec - start_clock.tv_nsec) / 10e9;

        printf("Tempo gasto: %.3fs\n", timeElapsed[3]);

    return 0;
}