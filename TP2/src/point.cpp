#include <bits/stdc++.h>

#include "point.hpp"
using namespace std; 

// Função para ler os pontos a partir de um arquivo
int readPointsFromFile(const char *filename, Point **points)
{
    ifstream arquivo;
    arquivo.open(filename);
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
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
    *points = new Point[numPoints];

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

// Função para calcular o produto vetorial de três pontos
int crossProduct(Point p, Point q, Point r)
{
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}