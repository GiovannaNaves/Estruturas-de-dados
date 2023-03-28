#include "fat.h"

using namespace std;


int main( int argc, char ** argv) { 
    struct timespec t1, t2, res;
    int n = atoi(argv[1]); 
    cout << argc << argv[0] << argv[1] << endl;
    clock_gettime(CLOCK_MONOTONIC,&t1);
    cout << fatr(n) << endl; 
    clock_gettime(CLOCK_MONOTONIC,&t2);
    if ()
     
}