#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A sample memory-intensive function
void memoryIntensiveTask() {
    const int num_elements = 1000000;
    int *array = (int *)malloc(num_elements * sizeof(int));

    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Access and modify the allocated memory
    for (int i = 0; i < num_elements; i++) {
        array[i] = i;
    }

    free(array); // Release the allocated memory
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Record the starting time

    // Perform memory-intensive task
    memoryIntensiveTask();

    end = clock(); // Record the ending time

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate CPU time used

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
