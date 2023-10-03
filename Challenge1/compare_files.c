#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for arguments
    if(argc != 3) {
        printf("Usage: %s <originalFile> <AnswerFile>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    FILE *file3 = fopen("Compare_Output.txt", "w");

    char line1[1024];
    char line2[1024];
    int lineCount = 1;
    int lineDiff = 0;

    fgets(line1, sizeof(line1), file1);
    fgets(line2, sizeof(line2), file2);

    while (1) {
        if (fgets(line1, sizeof(line1), file1) == NULL || fgets(line2, sizeof(line2), file2) == NULL) {
            break;  // End of one of the files
        }

        if (strcmp(line1, line2) != 0) {
            fprintf(file3, "Files differ at line %d:\n", lineCount);
            fprintf(file3, "File %s: %s", argv[1], line1);
            fprintf(file3, "File %s: %s", argv[2], line2);
            fprintf(file3, "\n");
            lineDiff++;
        } 

        lineCount++;
    }    

    while(fgets(line1, sizeof(line1), file1) != NULL) {
        fprintf(file3, "Missing line at %d: %s\n", lineCount, line1);
        lineCount++;
        lineDiff++;
    }

    double percentage = ((lineCount-lineDiff)/(double)lineCount) * 100;
    printf("The file %s is %.2f%% similar to %s.\n", argv[2], percentage, argv[1]);

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}