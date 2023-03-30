#include "fib.h"
#include <sys/time.h>
#include <sys/resource.h>
#define _POSIX_MONOTONIC_CLOCK 200112L
#include <time.h>


int main( int argc, char ** argv) { 
    struct rusage it_start, it_end, rec_start, rec_end;
    struct timespec it_start_clock, it_end_clock, rec_start_clock, rec_end_clock;
    int out_it, out_rec, max = 5;
    double total_rec_sys_time, total_rec_user_time, total_rec_clock_time, total_it_sys_time, total_it_user_time, total_it_clock_time;

    for (int n = 5; n <= max; n++){
        getrusage(RUSAGE_SELF, &it_start);
        clock_gettime(CLOCK_MONOTONIC, &it_start_clock);

        out_it = fibi(n);

        getrusage(RUSAGE_SELF, &it_end);
        clock_gettime(CLOCK_MONOTONIC, &it_end_clock);

        double it_sys_time = (it_end.ru_stime.tv_sec - it_start.ru_stime.tv_sec) + (it_end.ru_stime.tv_usec - it_start.ru_stime.tv_usec) / 10e6;
        double it_user_time = (it_end.ru_utime.tv_usec - it_start.ru_utime.tv_usec) + (it_end.ru_utime.tv_sec - it_start.ru_utime.tv_sec) / 10e6;
        double it_clock_time = (it_end_clock.tv_sec - it_start_clock.tv_sec) + (it_end_clock.tv_nsec - it_start_clock.tv_nsec) / 10e9;

        getrusage(RUSAGE_SELF, &rec_start);
        clock_gettime(CLOCK_MONOTONIC, &rec_start_clock);

        out_rec = fibr(n);

        getrusage(RUSAGE_SELF, &rec_end);
        clock_gettime(CLOCK_MONOTONIC, &rec_end_clock);

        double rec_sys_time = (rec_end.ru_stime.tv_sec - rec_start.ru_stime.tv_sec) + (rec_end.ru_stime.tv_usec - rec_start.ru_stime.tv_usec) / 10e6;
        double rec_user_time = (rec_end.ru_utime.tv_sec - rec_start.ru_utime.tv_sec) + ((rec_end.ru_utime.tv_usec - rec_start.ru_utime.tv_usec) / 10e6);
        double rec_clock_time =  (rec_end_clock.tv_sec - rec_start_clock.tv_sec) + (rec_end_clock.tv_nsec - rec_start_clock.tv_nsec) / 10e9;
        
        total_rec_clock_time += rec_clock_time;
        total_rec_user_time += rec_user_time;
        total_rec_sys_time += rec_sys_time;
        total_it_clock_time += it_clock_time; 
        total_it_user_time += it_user_time;
        total_it_sys_time += it_sys_time;
        
        printf("Fibonacci de %d: %d.\n", n, fibi(n));
        printf("Fibonacci iterativo de %d: executou em %fs de usuario, em %fs de sistema e %f de relogio.\n", n, it_user_time, it_sys_time, it_clock_time);
        printf("Fibonacci recursivo de %d: executou em %fs de usuario, em %fs de sistema e %f de relogio.\n", n, rec_user_time, rec_sys_time, rec_clock_time);
    }

}