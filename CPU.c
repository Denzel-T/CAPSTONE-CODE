#include <stdio.h>
#include <time.h>

// A sample CPU-intensive function
void cpuIntensiveTask() {
    int i;
    double result = 0.0;
    for (i = 0; i < 1000000000; i++) {
        result += i * 2.0;
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Record the starting time

    // Perform CPU-intensive task
    cpuIntensiveTask();

    end = clock(); // Record the ending time

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate CPU time used

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
