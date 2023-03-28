#include "fat.h"

using namespace std;


int fatr (int n) { 
    if (n<=0) 
        return 1; 
    else return n * fatr(n-1); 
}

int fati (int n) { 
    int f; 
    f = 1; 
    while(n > 0){ 
        f = f * n; 
        n--; 
    } 
    return f; 
}