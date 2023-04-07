#include <stdlib.h>
#include <stdio.h>

#define MAX 100 


int main(void)
{
        int *p;
        int i = 0;
        while(i<MAX)
        {
                p = malloc(128);
                printf("%ld\n", (long)p);       
                free(p);
                i++;
        }
        return (0);
}
