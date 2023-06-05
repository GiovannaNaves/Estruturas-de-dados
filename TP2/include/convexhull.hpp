#include <bits/stdc++.h>
#include <time.h>

#include "point.hpp"

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

// Bucket Sort for the given array of points
void bucketSort(Point *points, int numPoints);