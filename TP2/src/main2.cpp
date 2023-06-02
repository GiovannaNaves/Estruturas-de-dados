#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

typedef struct
{
    int x;
    int y;
} Point;

Point points[100];

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

// Função para imprimir o fecho convexo
void printConvexHull(Point *convexHull, int numPoints)
{
    printf("FECHO CONVEXO:\n");
    for (int i = 0; i < numPoints; i++)
    {
        printf("%d %d\n", convexHull[i].x, convexHull[i].y);
    }
    printf("\n");
}

// Função para calcular o produto vetorial de três pontos
int crossProduct(Point p, Point q, Point r)
{
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// Function to compare two points for sorting
int compare(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    int orientation = crossProduct(points[0], *p1, *p2);
    if (orientation == 0)
    {
        // If points are collinear, compare based on distance from the anchor point
        int dist1 = (p1->x - points[0].x) * (p1->x - points[0].x) + (p1->y - points[0].y) * (p1->y - points[0].y);
        int dist2 = (p2->x - points[0].x) * (p2->x - points[0].x) + (p2->y - points[0].y) * (p2->y - points[0].y);
        return dist1 - dist2;
    }
    return orientation;
}

int jarvisMarch(Point *points, int numPoints, Point **convexHull)
{
    if (numPoints < 3)
    {
        return 0;
    }

    // Encontre o ponto com a menor coordenada y (e menor x em caso de empate)
    int minY = points[0].y;
    int minX = points[0].x;
    int minYIndex = 0;

    for (int i = 1; i < numPoints; i++)
    {
        int currY = points[i].y;
        int currX = points[i].x;

        if (currY < minY || (currY == minY && currX < minX))
        {
            minY = currY;
            minX = currX;
            minYIndex = i;
        }
    }

    // Inicie a partir do ponto com a menor coordenada y
    int p = minYIndex;
    int q;

    // Pilha para armazenar os pontos do fecho convexo
    Point *stack = new Point[numPoints];
    int top = -1;

    do
    {
        q = (p + 1) % numPoints;
        for (int i = 0; i < numPoints; i++)
        {
            if (crossProduct(points[p], points[i], points[q]) > 0)
            {
                q = i;
            }
        }
        top++;
        stack[top] = points[q];
        p = q;
    } while (p != minYIndex);

    *convexHull = stack;
    return top + 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Uso: %s <arquivo de entrada>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    Point *points = nullptr;
    int numPoints = readPointsFromFile(filename, &points);
    cout << numPoints << endl;
    if (numPoints == 0)
    {
        return 1;
    }

    // // Executar os algoritmos de fecho convexo com os diferentes métodos de ordenação
    Point *convexHull;
    clock_t start, end;
    double timeElapsed;

    // Jarvis March
    start = clock();
    int numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsJarvisMergeSort);
    printf("JARVIS+MERGESORT: %.3fs\n", timeElapsed);

    // Liberar a memória alocada para os pontos
    delete[] points;

    return 0;
}