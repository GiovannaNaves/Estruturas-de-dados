#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * buf;

int sum_to_n(int num)
{
    int i,sum=0;
    for(i=1;i<=num;i++)
        sum+=i;
    return sum;
}

void printSum()
{
    char line[100];
    printf("enter a number:\n");
    fgets(line, 100, stdin);
    line[strcspn(line, "\n")] = '\0'; 
    sprintf(buf,"sum=%d",sum_to_n(atoi(line)));
    printf("%s\n",buf);
}

int main(void)
{
     buf = malloc(100);
    printSum();
    free(buf);
    return 0;
}
