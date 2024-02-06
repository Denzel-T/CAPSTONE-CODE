#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A sample I/O intensive function (writes and reads from a file)
void ioIntensiveTask() {
    const char* filename = "iotestfile.txt";
    FILE* file;

    // Writing to a file
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    const char* data = "This is a sample I/O intensive task.";
    fprintf(file, "%s\n", data);
    fclose(file);

    // Reading from a file
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Process the read data (in this case, just printing)
        printf("%s", buffer);
    }

    fclose(file);

    // Remove the file
    remove(filename);
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Record the starting time

    // Perform I/O intensive task
    ioIntensiveTask();

    end = clock(); // Record the ending time

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate CPU time used

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
