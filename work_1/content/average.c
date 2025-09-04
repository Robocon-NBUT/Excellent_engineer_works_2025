#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *input_file, *output_file;
    int num;
    double sum = 0.0, mean;

    input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        num = rand() % 100;
        fprintf(input_file, "%d\n", num);
        sum += num;
    }
    fclose(input_file);

    mean = sum / 5.0;

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }
    fprintf(output_file, "Average: %.2f\n", mean);
    fclose(output_file);

    return 0;
}