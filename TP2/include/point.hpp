#include <bits/stdc++.h>

#ifndef POINT_HPP
#define POINT_HPP
typedef struct
{
    int x;
    int y;
} Point;

#endif

// Função para ler os pontos a partir de um arquivo
int readPointsFromFile(const char *filename, Point **points);

// Função para calcular o produto vetorial de três pontos
int crossProduct(Point p, Point q, Point r);

