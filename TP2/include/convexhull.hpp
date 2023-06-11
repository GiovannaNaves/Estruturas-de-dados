#include <bits/stdc++.h>

#include "point.hpp"

#ifndef CONVEXHULL_H
#define CONVEXHULL_H
class ConvexHull {
    public: 
        // Função para imprimir o fecho convexo
        void printConvexHull(Point *convexHull, int numPoints);

        // Algoritmo de fecho convexo - Jarvis March
        int jarvisMarch(Point *points, int numPoints, Point **convexHull);

        // Algoritmo de fecho convexo - Graham Scan
        int grahamScan(Point *points, int numPoints, Point **convexHull, int sortType);

        // Implementação do algoritmo de ordenação MergeSort
        void merge(Point *points, int low, int mid, int high);

        void mergeSort(Point *points, int low, int high);

        //Implementação do algoritmo de ordenação InsertionSort
        void insertionSort(Point *points, int numPoints);

        // Função auxiliar para o BucketSort
        int digitCountOfMaxX(Point *points, int numPoints, int numBuckets);

        // Implementação do algoritmo de ordenação BucketSort
        void bucketSort(Point *points, int numPoints);

};

#endif
