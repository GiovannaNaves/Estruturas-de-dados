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

// Implementação do algoritmo de ordenação MergeSort
void merge(Point *points, int low, int mid, int high)
{
    int leftLength = mid - low + 1;
    int rightLength = high - mid;

    Point *left = new Point[leftLength];   //(Point *)malloc(leftLength * sizeof(Point));
    Point *right = new Point[rightLength]; // Point *)malloc(rightLength * sizeof(Point));

    for (int i = 0; i < leftLength; i++)
    {
        left[i] = points[low + i];
    }
    for (int i = 0; i < rightLength; i++)
    {
        right[i] = points[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < leftLength && j < rightLength)
    {
        if (left[i].x < right[j].x)
        {
            points[k] = left[i];
            i++;
        }
        else if (left[i].x > right[j].x)
        {
            points[k] = right[j];
            j++;
        }
        else
        {
                int cross = crossProduct(points[low], left[i], right[j]);
                if (cross < 0)
                {
                    points[k] = left[i];
                    i++;
                }
                else if (cross > 0)
                {
                    points[k] = right[j];
                    j++;
                }
                else
                {
                    if (left[i].y <= right[j].y)
                    {
                    points[k] = left[i];
                    i++;
                }
                else
                {
                    points[k] = right[j];
                    j++;
                }
            }
        }
        k++;
    }

    while (i < leftLength)
    {
        points[k] = left[i];
        i++;
        k++;
    }

    while (j < rightLength)
    {
        points[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(Point *points, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(points, low, mid);
        mergeSort(points, mid + 1, high);
        merge(points, low, mid, high);
    }
}

//Implementação do algoritmo de ordenação InsertionSort
void insertionSort(Point *points, int numPoints)
{
    for (int i = 1; i < numPoints; i++)
    {
        Point key = points[i];
        int j = i - 1;
        while (j >= 0 && (points[j].x > key.x || (points[j].x == key.x && points[j].y > key.y)))
        {
            points[j + 1] = points[j];
            j--;
        }
        points[j + 1] = key;
    }
}

/// Bucket Sort for the given array of points
// void bucketSort(Point *points, int numPoints)
// {
//     // Find the maximum value of x to determine the number of buckets
//     int max_x = points[0].x;
//     for (int i = 1; i < numPoints; i++)
//     {
//         if (points[i].x > max_x)
//             max_x = points[i].x;
//     }

//     // Create buckets based on the maximum value of x
//     int numBuckets = max_x + 1;
//     Point **buckets = (Point **)malloc(numBuckets * sizeof(Point *));

//     // Initialize each bucket with 0 points
//     for (int i = 0; i < numBuckets; i++)
//     {
//         buckets[i] = NULL;
//     }

//     // Assign each point to its respective bucket
//     for (int i = 0; i < numPoints; i++)
//     {
//         int index = points[i].x;
//         Point *newPoint = (Point *)malloc(sizeof(Point));
//         *newPoint = points[i];
//         newPoint->y = buckets[index];
//         buckets[index] = newPoint;
//     }

//     // Sort each bucket using Insertion Sort
//     for (int i = 0; i < numBuckets; i++)
//     {
//         Point *bucket = buckets[i];
//         insertionSort(bucket, numPoints); // Sort the points within the bucket
//     }

//     // Copy the sorted points back to the original array
//     int k = 0;
//     for (int i = 0; i < numBuckets; i++)
//     {
//         Point *bucket = buckets[i];
//         while (bucket != NULL)
//         {
//             points[k++] = *bucket;
//             bucket = bucket->y;
//         }
//     }

//     // Free the memory allocated for buckets
//     for (int i = 0; i < numBuckets; i++)
//     {
//         Point *bucket = buckets[i];
//         while (bucket != NULL)
//         {
//             Point *temp = bucket;
//             bucket = bucket->y;
//             free(temp);
//         }
//     }
//     free(buckets);
// }

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

// Algoritmo de fecho convexo - Graham Scan
int grahamScan(Point *points, int numPoints, Point **convexHull, int sortType)
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

    // Coloque o ponto com a menor coordenada y na primeira posição
    Point temp = points[0];
    points[0] = points[minYIndex];
    points[minYIndex] = temp;

    // Ordenar os pontos pelo ângulo polar em relação ao ponto mínimo
    if (sortType == 1)
        mergeSort(&points[1], 0, numPoints - 1);
    if (sortType == 2)
        insertionSort(&points[1], numPoints - 1);
    // if (sortType == 3)
    //     bucketSort(&points[1], numPoints - 1);

    // Remover pontos colineares
    int m = 1;
    for (int i = 1; i < numPoints; i++)
    {
        while (i < numPoints - 1 && crossProduct(points[0], points[i], points[i + 1]) == 0)
        {
            i++;
        }
        points[m] = points[i];
        m++;
    }

    if (m < 3)
    {
        return 0;
    }

    // Pilha para armazenar os pontos do fecho convexo
    Point *stack = new Point[m]; //(Point*)malloc(m * sizeof(Point));
    int top = 2;
    stack[0] = points[0];
    stack[1] = points[1];
    stack[2] = points[2];

    for (int i = 3; i < m; i++)
    {
        while (top > 0 && crossProduct(stack[top - 1], stack[top], points[i]) < 0)
        {
            top--;
        }
        top++;
        stack[top] = points[i];
    }

    *convexHull = stack;
    delete[] stack;
    return top + 1;
}

// Algoritmo de fecho convexo - Jarvis March
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
    Point *stack = new Point[numPoints]; //(Point *)malloc(numPoints * sizeof(Point));
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
    if (numPoints == 0)
    {
        return 1;
    }

    // Executar os algoritmos de fecho convexo com os diferentes métodos de ordenação
    Point *convexHull;
    clock_t start, end;
    double timeElapsed;

    int numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    printConvexHull(convexHull, numConvexHullPointsJarvisMergeSort);

    // Graham Scan com MergeSort
    start = clock();
    int numConvexHullPointsGrahamMergeSort = grahamScan(points, numPoints, &convexHull, 1);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("GRAHAM+MERGESORT: %.3fs\n", timeElapsed);

    // Graham Scan com InsertionSort
    start = clock();
    int numConvexHullPointsGrahamInsertionSort = grahamScan(points, numPoints, &convexHull, 2);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", timeElapsed);

    // // Graham Scan com BucketSort
    // start = clock();
    // int numConvexHullPointsGrahamBucketSort = grahamScan(points, numPoints, &convexHull, 3);
    // end = clock();
    // timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printConvexHull(convexHull, numConvexHullPointsGrahamBucketSort);
    // printf("GRAHAM+BucketSORT: %.3fs\n", timeElapsed);

    // Jarvis March
    start = clock();
    numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("JARVIS: %.3fs\n", timeElapsed);

    // Liberar a memória alocada para os pontos
    free(points);

    return 0;
}