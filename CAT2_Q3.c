




#include <stdio.h>

// 1. Create input.txt with 10 numbers
void createInputFile() {
    FILE *fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("ERROR: Cannot create input.txt\n");
        return;
    }
    printf("Enter 10 integers:\n");
    int num;
    int i;                                      // ? FIXED: declared outside
    for (i = 1; i <= 10; i++) {
        printf("%2d: ", i);
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);
    printf("=> input.txt created successfully!\n\n");
}

// 2. Read ? calculate sum & average ? output.txt
void processNumbers() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("ERROR: Cannot open input.txt\n");
        return;
    }
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("ERROR: Cannot create output.txt\n");
        fclose(in);
        return;
    }
    int num, sum = 0, count = 0;
    while (fscanf(in, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    float avg = (count > 0) ? (float)sum / count : 0;
    fprintf(out, "Sum = %d\n", sum);
    fprintf(out, "Average = %.2f\n", avg);
    fclose(in);
    fclose(out);
    printf("=> output.txt created with Sum & Average!\n\n");
}

// 3. Display both files
void displayFiles() {
    printf("=== input.txt ===\n");
    FILE *f1 = fopen("input.txt", "r");
    if (f1) {
        int n, i = 1;
        while (fscanf(f1, "%d", &n) == 1)
            printf("%2d: %d\n", i++, n);
        fclose(f1);
    } else printf("Not found!\n");

    printf("\n=== output.txt ===\n");
    FILE *f2 = fopen("output.txt", "r");
    if (f2) {
        char line[100];
        while (fgets(line, sizeof(line), f2))
            printf("%s", line);
        fclose(f2);
    } else printf("Not found!\n");
}

int main() {
    createInputFile();    // Task 1
    processNumbers();     // Task 2
    displayFiles();       // Task 3
    printf("\n* ALL TASKS COMPLETED – SUBMIT NOW! *\n");
    return 0;
}