#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the user specified a filename.
    if (argc != 2) {
        printf("Usage: simple_shell filename\n");
        exit(1);
    }

    // Open the file for reading.
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file %s.\n", argv[1]);
        exit(1);
    }

    // Read each line from the file and execute the command.
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Remove the newline character from the end of the line.
        line[strlen(line) - 1] = '\0';

        // Execute the command.
        system(line);
    }

    // Close the file.
    fclose(fp);

    return 0;
}
