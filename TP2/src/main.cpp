#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
// #include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

#include "convexhull.hpp"
#include "point.hpp"

Point points[100];

int main(int argc, char *argv[])
{

    ofstream fout("graph.csv", ios::app);

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
    clock_t start, end; // startj, endj, startgi, endgi, startgm, endgm, startgb, endgb;
    struct rusage graham_start, graham_end, jarvis_start, jarvis_end;
    struct timespec graham_start_clock, graham_end_clock, jarvis_start_clock, jarvis_end_clock;
    double timeElapsed[4];

    int numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    printConvexHull(convexHull, numConvexHullPointsJarvisMergeSort);

    // 1 - insertion, 2 - merge, 3 - bucket
    for (int i = 1; i <= 3; i++)
    {
        getrusage(RUSAGE_SELF, &graham_start);
        clock_gettime(CLOCK_MONOTONIC, &graham_start_clock);

        int numConvexHullPointsGrahamMergeSort = grahamScan(points, numPoints, &convexHull, i);

        getrusage(RUSAGE_SELF, &graham_end);
        clock_gettime(CLOCK_MONOTONIC, &graham_end_clock);

        timeElapsed[i - 1] = (graham_end_clock.tv_sec - graham_start_clock.tv_sec) + (graham_end_clock.tv_nsec - graham_start_clock.tv_nsec) / 10e9;
        // timeElapsed[i - 1] = ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    // // Graham Scan com InsertionSort
    // startgi = clock();
    // int numConvexHullPointsGrahamInsertionSort = grahamScan(points, numPoints, &convexHull, 2);
    // endgi = clock();
    // timeElapsed = ((double)(endgi - startgi)) / CLOCKS_PER_SEC;
    // printf("GRAHAM+INSERTIONSORT: %.3fs\n", timeElapsed);
    // fout << timeElapsed << ",";

    // // Graham Scan com BucketSort
    // startgb = clock();
    // int numConvexHullPointsGrahamBucketSort = grahamScan(points, numPoints, &convexHull, 3);
    // endgb = clock();
    // timeElapsed = ((double)(endgb - startgb)) / CLOCKS_PER_SEC;
    // printf("GRAHAM+BUCKETSORT: %.3fs\n", timeElapsed);
    // fout << timeElapsed << ",";

    printf("GRAHAM+MERGESORT: %.3fs\n", timeElapsed[1]);
    printf("GRAHAM+INSERTIONSORT: %.3fs\n", timeElapsed[0]);
    printf("GRAHAM+BUCKETSORT: %.3fs\n", timeElapsed[2]);
    fout << timeElapsed[1] << "," << timeElapsed[0] << "," << timeElapsed[2] << ",";

    // Jarvis March
    getrusage(RUSAGE_SELF, &jarvis_start);
    clock_gettime(CLOCK_MONOTONIC, &jarvis_start_clock);

    // int numConvexHullPointsJarvisMergeSort = jarvisMarch(points, numPoints, &convexHull);
    jarvisMarch(points, numPoints, &convexHull);

    getrusage(RUSAGE_SELF, &jarvis_end);
    clock_gettime(CLOCK_MONOTONIC, &jarvis_end_clock);

    timeElapsed[3] = (jarvis_end_clock.tv_sec - jarvis_start_clock.tv_sec) + (jarvis_end_clock.tv_nsec - jarvis_start_clock.tv_nsec) / 10e9;

    printf("JARVIS: %.3fs\n", timeElapsed[3]);
    fout << timeElapsed[3];

    // Liberar a memória alocada para os pontos
    free(points);

    fout << endl;

    return 0;
}