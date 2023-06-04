#include <bits/stdc++.h>
#include <time.h>

typedef struct
{
    int x;
    int y;
} Point;

// Função para ler os pontos a partir de um arquivo
int readPointsFromFile(const char *filename, Point **points);