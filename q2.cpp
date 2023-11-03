#include <stdio.h>
#include <time.h>
#include <unistd.h>

// A simple function that does very little work.
void simpleFunction() {
    // This function intentionally does almost nothing.
}

int main() {
    struct timespec start, end;
    long long functionCallTime, systemCallTime;

    // Measure time taken for the simple function call
    clock_gettime(CLOCK_MONOTONIC, &start);
    simpleFunction();
    clock_gettime(CLOCK_MONOTONIC, &end);
    functionCallTime = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    // Measure time taken for the getpid system call
    clock_gettime(CLOCK_MONOTONIC, &start);
    getpid();
    clock_gettime(CLOCK_MONOTONIC, &end);
    systemCallTime = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    // Output the results
    printf("Function call time: %lld ns\n", functionCallTime);
    printf("System call time: %lld ns\n", systemCallTime);

    return 0;
}