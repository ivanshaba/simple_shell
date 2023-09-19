#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the command is `exit`.
    if (strcmp(argv[1], "exit") == 0) {
        // Check if there are any arguments.
        if (argc == 2) {
            // If there are no arguments, exit the shell with status code 0.
            exit(0);
        } else if (argc == 3) {
            // If there is one argument, and it is a valid integer, exit the shell with the specified status code.
            int status = atoi(argv[2]);
            if (status >= 0 && status <= 255) {
                exit(status);
            }
        } else {
            // Otherwise, print an error message and exit the shell with status code 1.
            printf("Usage: exit status, where status is an integer used to exit the shell.\n");
            exit(1);
        }
    }

    // The command is not `exit`. Print an error message and exit the shell.
    printf("Unknown command: %s\n", argv[1]);
    exit(1);
}
