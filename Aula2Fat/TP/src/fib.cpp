#include "fib.h"

using namespace std;

int fibr(int n) { 
    if (n < 3) 
        return 1; 
    else 
        return Fib(n-1) + Fib(n-2);
}

int fibi(int n) { 
    int fn1 = 1, fn2 = 1; 
    int fn, i; 
    if (n < 3) 
        return 1; 
    for (i = 3; i <= n; i++) { 
        fn = fn2 + fn1; 
        fn2 = fn1; 
        fn1 = fn; 
    } 
    return fn;
}