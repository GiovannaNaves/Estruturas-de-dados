#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

Point points[100]; 

// Função para ler os pontos a partir de um arquivo
int readPointsFromFile(const char* filename, Point** points) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Contar o número de linhas no arquivo
    int numPoints = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            numPoints++;
        }
    }
    rewind(file);

    // Alocar memória para os pontos
    *points = (Point*)malloc(numPoints * sizeof(Point));
    if (*points == NULL) {
        printf("Erro de alocação de memória.\n");
        return 0;
    }

    // Ler os pontos do arquivo
    int i = 0;
    while (fscanf(file, "%d %d", &((*points)[i].x), &((*points)[i].y)) != EOF) {
        i++;
    }

    fclose(file);
    return numPoints;
}

// Função para imprimir o fecho convexo
void printConvexHull(Point* convexHull, int numPoints) {
    printf("FECHO CONVEXO:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("%d x + %d = 0\n", convexHull[i].x, convexHull[i].y);
    }
    printf("\n");
}

int crossProduct(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}