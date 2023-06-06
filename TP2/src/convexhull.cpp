#include <bits/stdc++.h>

#include "convexhull.hpp"

// Função para imprimir o fecho convexo
void printConvexHull(Point *convexHull, int numPoints)
{
    printf("FECHO CONVEXO:\n");
    for (int i = 0; i < numPoints; i++)
    {
        printf("%d %d\n", convexHull[i].x, convexHull[i].y);
    }
    printf("\n");
};

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
    if (sortType == 2)
        mergeSort(&points[1], 0, numPoints - 1);
    if (sortType == 1)
        insertionSort(&points[1], numPoints - 1);
    if (sortType == 3)
        bucketSort(&points[1], numPoints - 1);

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
    Point *hull = new Point[m]; //(Point*)malloc(m * sizeof(Point));
    int top = 2;
    hull[0] = points[0];
    hull[1] = points[1];
    hull[2] = points[2];

    for (int i = 3; i < m; i++)
    {
        while (top > 0 && crossProduct(hull[top - 1], hull[top], points[i]) < 0)
        {
            top--;
        }
        top++;
        hull[top] = points[i];
    }

    *convexHull = hull;
    delete[] hull;
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
    Point *hull = new Point[numPoints];
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
        hull[top] = points[q];
        p = q;
    } while (p != minYIndex);

    *convexHull = hull;
    return top + 1;
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

// Implementação do algoritmo de ordenação InsertionSort
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

int digitCountOfMaxX(Point *points, int numPoints, int numBuckets)
{
    int i, max = points[0].x, cnt = 0;
    for (i = 1; i < numPoints; i++)
    {
        if (points[i].x > max)
            max = points[i].x;
    }
    while (max > 0)
    {
        cnt++;
        max = max / 10;
    }

    return cnt;
}

// Bucket Sort for the given array of points
void bucketSort(Point *points, int numPoints)
{
    // https://favtutor.com/blogs/bucket-sort-cpp

    // Create buckets based on the maximum value of x
    const int numBuckets = 100;
    Point *bucket[numBuckets];

    for (int i = 0; i < numBuckets; i++)
        bucket[i] = new Point[numPoints];

    static int i, elemsPerBucket[numBuckets], idxInBucket, l, d = 1;
    int count;
    count = digitCountOfMaxX(points, numPoints, numBuckets);

    for (int m = 0; m < count; m++)
    {

        for (i = 0; i < numBuckets; i++)
            elemsPerBucket[i] = 0;

        for (i = 0; i < numPoints; i++)
        {
            idxInBucket = (points[i].x / d) % numBuckets;
            bucket[idxInBucket][elemsPerBucket[idxInBucket]] = points[i];
            elemsPerBucket[idxInBucket]++;
        }

        l = 0;
        for (i = 0; i < numBuckets; i++)
        {
            for (idxInBucket = 0; idxInBucket < elemsPerBucket[i]; idxInBucket++)
            {
                points[i] = bucket[i][idxInBucket];
                l++;
            }
        }

        d *= numBuckets;
    }

    return;
    /*
        std::cout << "1" << std::endl;

        // Point **buckets = (Point **)malloc(numBuckets * sizeof(Point *));

        std::cout << "2" << std::endl;

        // Initialize each bucket with 0 points
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }

        std::cout << "3" << std::endl;

        // Assign each point to its respective bucket
        for (int i = 0; i < numPoints; i++)
        {
            std::cout << "a" << std::endl;
            int index = points[i].x % numBuckets;
            std::cout << "b" << std::endl;
            // Point *newPoint = new (Point);

            std::cout << "c" << std::endl;
            //*newPoint = points[i];
            std::cout << index << std::endl;

            newPoint->y = buckets[index]->y;
            std::cout << "e" << std::endl;
            buckets[index] = newPoint;
            std::cout << "f" << std::endl;
        }

        std::cout << "4" << std::endl;

        // Sort each bucket using Insertion Sort
        for (int i = 0; i < numBuckets; i++)
        {
            Point *bucket = buckets[i];
            insertionSort(bucket, numPoints); // Sort the points within the bucket
        }
        std::cout << "5" << std::endl;

        // Copy the sorted points back to the original array
        int k = 0;
        for (int i = 0; i < numBuckets; i++)
        {
            Point *bucket = buckets[i];
            points[k++] = *bucket;
        }*/
}
