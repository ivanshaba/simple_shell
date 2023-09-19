#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the command is `exit`.
    if (strcmp(argv[1], "exit") == 0) {
        // Exit the program.
        exit(0);
    }

    // The command is not `exit`. Print an error message and exit the program.
    printf("Unknown command: %s\n", argv[1]);
    exit(1);
}
