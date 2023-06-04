#include <bits/stdc++.h>
#include <time.h>

#include "point.hpp"

// Função para ler os pontos a partir de um arquivo
int readPointsFromFile(const char *filename, Point **points)
{
    ifstream arquivo;
    arquivo.open(filename);
    // FILE *file = fopen(filename, "r");
    if (!arquivo.is_open())
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Contar o número de linhas no arquivo
    int numPoints = 0;
    string ch;
    while (getline(arquivo, ch, '\n'))
        numPoints++;
    arquivo.clear();
    arquivo.seekg(0, arquivo.beg);
    // Alocar memória para os pontos
    *points = new Point[numPoints]; //(Point *)malloc(numPoints * sizeof(Point));

    // // Ler os pontos do arquivo
    int i = 0;
    while (getline(arquivo, ch, '\n'))
    {
        stringstream ss(ch);
        string x, y;
        ss >> x >> y;
        (*points)[i].x = stoi(x);
        (*points)[i].y = stoi(y);
        i++;
    }
    arquivo.close();
    return numPoints;
}
