#include <stdlib.h>
#include <stdio.h>

#define MAX_ITERATIONS 100 // Maximum number of iterations before exiting the loop


int main(void)
{
        int *p;
        int i = 0;
        while(i<MAX_ITERATIONS)
        {
                p = malloc(128);
                printf("%ld\n", (long)p);       
                free(p);
                i++;
        }
        return (0);
}
