#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <originalFile>\n", argv[0]);
        return 1;
    }

    int key = (int)time(NULL);
    printf("Time in seconds of when the file %s was encrypted: %ld\n", argv[1], key);


    FILE *file = fopen(argv[1], "r+");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int cur = fgetc(file);
    while (cur != EOF) {
        fseek(file, -1, SEEK_CUR);  // Move the file pointer back by one character
        char enc = (char)((cur + key) % 127);
        fputc(enc, file);
        fseek(file, 0, SEEK_CUR);   // Reset the file pointer to the current position
        cur = fgetc(file);
    }

    fclose(file);

    printf("File '%s' has been modified in place.\n", argv[1]);

    return 0;
}