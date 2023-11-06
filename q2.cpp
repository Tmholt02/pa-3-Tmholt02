#include <stdio.h>
#include <time.h>
#include <unistd.h>

void getpidWithOverhead() {
    // getpid();
}

int main() {

    const int n = 1000000;
    double avgFunc = 0.0;
    double avgSysC = 0.0;

    for (int i = 0; i < n; i++) {

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

        avgFunc += functionCallTime / (double)n;
        avgSysC += systemCallTime / (double)n;
    }

    // Output the results
    printf("Function calls take %.2f ns on average.\n", avgFunc);
    printf("GetPID system call takes %.2f ns on average.\n", avgSysC);
    printf("Syscall is %.2f ns slower on average.\n", avgSysC - avgFunc);

    return 0;
}