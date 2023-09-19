#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the command is `setenv` or `unsetenv`.
    if (strcmp(argv[1], "setenv") == 0) {
        // Set an environment variable.
        if (argc != 4) {
            printf("Usage: setenv VARIABLE VALUE\n");
            exit(1);
        }

        if (setenv(argv[2], argv[3], 1) != 0) {
            printf("Failed to set environment variable %s.\n", argv[2]);
            exit(1);
        }
    } else if (strcmp(argv[1], "unsetenv") == 0) {
        // Unset an environment variable.
        if (argc != 3) {
            printf("Usage: unsetenv VARIABLE\n");
            exit(1);
        }

        if (unsetenv(argv[2]) != 0) {
            printf("Failed to unset environment variable %s.\n", argv[2]);
            exit(1);
        }
    } else {
        // The command is not `setenv` or `unsetenv`.
        printf("Unknown command: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}
