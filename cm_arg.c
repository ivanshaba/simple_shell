#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Declare an array of strings to store the command line arguments.
    char *commands[] = {"help", "quit"};

    // Iterate over the command line arguments array and process each argument.
    for (int i = 1; i < argc; i++) {
        // Compare the command line argument to the known commands.
        if (strcmp(argv[i], commands[0]) == 0) {
            // Print the help message.
            printf("Usage: program [help|quit]\n");
            exit(0);
        } else if (strcmp(argv[i], commands[1]) == 0) {
            // Quit the program.
            exit(0);
        }
    }

    // If no known command was found, print an error message and exit the program.
    printf("Unknown command: %s\n", argv[1]);
    exit(1);
}
