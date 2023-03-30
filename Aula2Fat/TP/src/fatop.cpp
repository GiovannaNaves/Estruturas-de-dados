#include "fat.h"
//#include <sys/time.h>
//#include <sys/resource.h>


using namespace std;


int main( int argc, char ** argv) { 
    //struct timespec t1, t2, res;
    int n = atoi(argv[1]); 
    cout << argc << argv[0] << argv[1] << endl;
    //clock_gettime(CLOCK_MONOTONIC,&t1);
    cout << fatr(n) << endl; 
    /*clock_gettime(CLOCK_MONOTONIC,&t2);
        if (t2.tv_nsec < t1.tv_nsec){
        // ajuste necessario, utilizando um segundo de tv_sec
        res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
        res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
    } else {
        // nao e necessario ajuste
        res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
        res-> tv_sec = t2.tv_sec-t1.tv_sec;
    } */
    
    cout << fati(n) << endl; 

}