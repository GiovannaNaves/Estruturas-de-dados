#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

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

void printConvexHull(Point* convexHull, int numPoints) {
    printf("FECHO CONVEXO:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("%d x + %d = 0\n", convexHull[i].x, convexHull[i].y);
    }
    printf("\n");
}

double measureTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Implemente os algoritmos de ordenação (MergeSort, InsertionSort e um método linear)
// Implemente os algoritmos de fecho convexo (Graham Scan e Jarvis March)

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo de entrada>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    Point* points;
    int numPoints = readPointsFromFile(filename, &points);
    if (numPoints == 0) {
        return 1;
    }

    // Implemente a chamada dos algoritmos de ordenação e de fecho convexo aqui
    // Meça o tempo consumido por cada método utilizando a função clock()

    // Imprima os resultados
    printConvexHull(convexHull, numPoints);
    printf("GRAHAM+MERGESORT: %.3fs\n", timeGrahamMergeSort);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", timeGrahamInsertionSort);
    printf("GRAHAM+LINEAR: %.3fs\n", timeGrahamLinear);
    printf("JARVIS+MERGESORT: %.3fs\n", timeJarvisMergeSort);
    printf("JARVIS+INSERTIONSORT: %.3fs\n", timeJarvisInsertionSort);
    printf("JARVIS+LINEAR: %.3fs\n", timeJarvisLinear);

    // Libere a memória alocada para os pontos

    return 0;
}