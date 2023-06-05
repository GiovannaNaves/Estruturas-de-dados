#include <bits/stdc++.h>
#include <time.h>

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
