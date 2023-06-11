#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include <sys/resource.h>

#include "convexhull.hpp"
#include "point.hpp"

using namespace std;

Point points[100];

int main(int argc, char *argv[])
{

    ofstream fout("graph.csv", ios::app);
    const char *filename;

    for(int i=1; i<argc; i++){
        char n = argv[i][0];
        switch(n){
            case 'f':
            filename = argv[i+1];
            break;
        }
    }

    Point *points = nullptr;
    int numPoints = readPointsFromFile(filename, &points);
    if (numPoints == 0)
    {
        return 1;
    }

    // Executar os algoritmos de fecho convexo com os diferentes métodos de ordenação
    Point *convexHull;
    clock_t start, end; 
    struct rusage graham_start, graham_end, jarvis_start, jarvis_end;
    struct timespec graham_start_clock, graham_end_clock, jarvis_start_clock, jarvis_end_clock;
    double timeElapsed[4];

    ConvexHull jarvis;
    int numConvexHullPointsJarvisMergeSort = jarvis.jarvisMarch(points, numPoints, &convexHull);
    jarvis.printConvexHull(convexHull, numConvexHullPointsJarvisMergeSort);

    // 1 - insertion, 2 - merge, 3 - bucket
    for (int i = 1; i <= 3; i++)
    {
        getrusage(RUSAGE_SELF, &graham_start);
        clock_gettime(CLOCK_MONOTONIC, &graham_start_clock);

        ConvexHull graham;
        int numConvexHullPointsGrahamMergeSort = graham.grahamScan(points, numPoints, &convexHull, i);

        getrusage(RUSAGE_SELF, &graham_end);
        clock_gettime(CLOCK_MONOTONIC, &graham_end_clock);

        timeElapsed[i - 1] = (graham_end_clock.tv_sec - graham_start_clock.tv_sec) + (graham_end_clock.tv_nsec - graham_start_clock.tv_nsec) / 10e9;
    }
    cout << fixed << setprecision(3);
    cout << "GRAHAM+MERGESORT: " << timeElapsed[1] << "s" << endl;
    cout << "GRAHAM+INSERTIONSORT: " << timeElapsed[0] << "s" << endl;
    cout << "GRAHAM+BUCKETSORT: " << timeElapsed[2] << "s" << endl;
    fout << timeElapsed[1] << "," << timeElapsed[0] << "," << timeElapsed[2] << ",";

    // Jarvis March
    getrusage(RUSAGE_SELF, &jarvis_start);
    clock_gettime(CLOCK_MONOTONIC, &jarvis_start_clock);
    
    jarvis.jarvisMarch(points, numPoints, &convexHull);

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