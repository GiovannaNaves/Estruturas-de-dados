#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

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

// Função para calcular o produto vetorial de três pontos
int crossProduct(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// Implementação do algoritmo de ordenação MergeSort
void merge(Point* points, int low, int mid, int high) {
    int leftLength = mid - low + 1;
    int rightLength = high - mid;

    Point* left = (Point*)malloc(leftLength * sizeof(Point));
    Point* right = (Point*)malloc(rightLength * sizeof(Point));

    for (int i = 0; i < leftLength; i++) {
        left[i] = points[low + i];
    }
    for (int i = 0; i < rightLength; i++) {
        right[i] = points[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < leftLength && j < rightLength) {
        if (left[i].x < right[j].x) {
            points[k] = left[i];
            i++;
        } else if (left[i].x > right[j].x) {
            points[k] = right[j];
            j++;
        } else {
            if (left[i].y <= right[j].y) {
                points[k] = left[i];
                i++;
            } else {
                points[k] = right[j];
                j++;
            }
        }
        k++;
    }

    while (i < leftLength) {
        points[k] = left[i];
        i++;
        k++;
    }

    while (j < rightLength) {
        points[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void mergeSort(Point* points, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(points, low, mid);
        mergeSort(points, mid + 1, high);
        merge(points, low, mid, high);
    }
}

// Implementação do algoritmo de ordenação InsertionSort
void insertionSort(Point* points, int numPoints) {
    for (int i = 1; i < numPoints; i++) {
        Point key = points[i];
        int j = i - 1;
        while (j >= 0 && (points[j].x > key.x || (points[j].x == key.x && points[j].y > key.y))) {
            points[j + 1] = points[j];
            j--;
        }
        points[j + 1] = key;
    }
}

// Implementação do algoritmo de ordenação CountingSort
void countingSort(Point* points, int numPoints) {
    int min_x = points[0].x;
    int max_x = points[0].x;

    for (int i = 1; i < numPoints; i++) {
        if (points[i].x < min_x) {
            min_x = points[i].x;
        }
        if (points[i].x > max_x) {
            max_x = points[i].x;
        }
    }

    int range = max_x - min_x + 1;
    int* count = (int*)calloc(range, sizeof(int));
    Point* output = (Point*)malloc(numPoints * sizeof(Point));

    for (int i = 0; i < numPoints; i++) {
        count[points[i].x - min_x]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = numPoints - 1; i >= 0; i--) {
        output[count[points[i].x - min_x] - 1] = points[i];
        count[points[i].x - min_x]--;
    }

    for (int i = 0; i < numPoints; i++) {
        points[i] = output[i];
    }

    free(count);
    free(output);
}

// Algoritmo de fecho convexo - Graham Scan
int grahamScan(Point* points, int numPoints, Point** convexHull) {
    if (numPoints < 3) {
        return 0;
    }

    // Encontre o ponto com a menor coordenada y (e menor x em caso de empate)
    int minY = points[0].y;
    int minX = points[0].x;
    int minYIndex = 0;

    for (int i = 1; i < numPoints; i++) {
        int currY = points[i].y;
        int currX = points[i].x;

        if (currY < minY || (currY == minY && currX < minX)) {
            minY = currY;
            minX = currX;
            minYIndex = i;
        }
    }

    // Coloque o ponto com a menor coordenada y na primeira posição
    Point temp = points[0];
    points[0] = points[minYIndex];
    points[minYIndex] = temp;

    // Ordenar os pontos pelo ângulo polar em relação ao ponto mínimo
    qsort(&points[1], numPoints - 1, sizeof(Point), compare);

    // Remover pontos colineares
    int m = 1;
    for (int i = 1; i < numPoints; i++) {
        while (i < numPoints - 1 && crossProduct(points[0], points[i], points[i + 1]) == 0) {
            i++;
        }
        points[m] = points[i];
        m++;
    }

    if (m < 3) {
        return 0;
    }

    // Pilha para armazenar os pontos do fecho convexo
    Point* stack = (Point*)malloc(m * sizeof(Point));
    int top = 2;
    stack[0] = points[0];
    stack[1] = points[1];
    stack[2] = points[2];

    for (int i = 3; i < m; i++) {
        while (top > 0 && crossProduct(stack[top - 1], stack[top], points[i]) < 0) {
            top--;
        }
        top++;
        stack[top] = points[i];
    }

    *convexHull = stack;
    return top + 1;
}

// Algoritmo de fecho convexo - Jarvis March
int jarvisMarch(Point* points, int numPoints, Point** convexHull) {
    if (numPoints < 3) {
        return 0;
    }

    // Encontre o ponto com a menor coordenada y (e menor x em caso de empate)
    int minY = points[0].y;
    int minX = points[0].x;
    int minYIndex = 0;

    for (int i = 1; i < numPoints; i++) {
        int currY = points[i].y;
        int currX = points[i].x;

        if (currY < minY || (currY == minY && currX < minX)) {
            minY = currY;
            minX = currX;
            minYIndex = i;
        }
    }

    // Inicie a partir do ponto com a menor coordenada y
    int p = minYIndex;
    int q;

    // Pilha para armazenar os pontos do fecho convexo
    Point* stack = (Point*)malloc(numPoints * sizeof(Point));
    int top = -1;

    do {
        q = (p + 1) % numPoints;
        for (int i = 0; i < numPoints; i++) {
            if (crossProduct(points[p], points[i], points[q]) > 0) {
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

    // Executar os algoritmos de fecho convexo com os diferentes métodos de ordenação
    Point* convexHull;
    clock_t start, end;
    double timeElapsed;

    // Graham Scan com MergeSort
    start = clock();
    mergeSort(points, 0, numPoints - 1);
    int numConvexHullPointsGrahamMergeSort = grahamScan(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsGrahamMergeSort);
    printf("GRAHAM+MERGESORT: %.3fs\n", timeElapsed);

    // Graham Scan com InsertionSort
    start = clock();
    insertionSort(points, numPoints);
    int numConvexHullPointsGrahamInsertionSort = grahamScan(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsGrahamInsertionSort);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", timeElapsed);

    // Graham Scan com CountingSort
    start = clock();
    countingSort(points, numPoints);
    int numConvexHullPointsGrahamCountingSort = grahamScan(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsGrahamCountingSort);
    printf("GRAHAM+COUNTINGSORT: %.3fs\n", timeElapsed);

    // Jarvis March com MergeSort
    start = clock();
    mergeSort(points, 0, numPoints - 1);
    int numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsJarvisMergeSort);
    printf("JARVIS+MERGESORT: %.3fs\n", timeElapsed);

    // Jarvis March com InsertionSort
    start = clock();
    insertionSort(points, numPoints);
    int numConvexHullPointsJarvisInsertionSort = jarvisMarch(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsJarvisInsertionSort);
    printf("JARVIS+INSERTIONSORT: %.3fs\n", timeElapsed);

    // Jarvis March com CountingSort
    start = clock();
    countingSort(points, numPoints);
    int numConvexHullPointsJarvisCountingSort = jarvisMarch(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printConvexHull(convexHull, numConvexHullPointsJarvisCountingSort);
    printf("JARVIS+COUNTINGSORT: %.3fs\n", timeElapsed);

    // Liberar a memória alocada para os pontos
    free(points);

    return 0;
}