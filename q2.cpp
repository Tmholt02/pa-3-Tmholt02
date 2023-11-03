#include <stdio.h>
#include <time.h>
#include <unistd.h>

void getpidWithOverhead() {
    getpid();
}

long long getTimeDiff() {
    struct timespec start, end;
    long long functionCallTime, systemCallTime;

    // Measure time taken for the simple function call
    clock_gettime(CLOCK_MONOTONIC, &start);
    getpidWithOverhead();
    clock_gettime(CLOCK_MONOTONIC, &end);
    functionCallTime = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    // Measure time taken for the getpid system call
    clock_gettime(CLOCK_MONOTONIC, &start);
    getpid();
    clock_gettime(CLOCK_MONOTONIC, &end);
    systemCallTime = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

    return functionCallTime - systemCallTime;
}

int main() {
    int n = 100000;
    double avgDiff = 0.0;
    for (int i = 0; i < n; i++) {
        avgDiff += getTimeDiff() / (double)n;
    }


    // Output the results
    printf("Function overhead adds %2f ns on average.\n", avgDiff);

    return 0;
}