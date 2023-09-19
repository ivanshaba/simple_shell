#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the command is `&&` or `||`.
    if (strcmp(argv[1], "&&") == 0) {
        // Execute the first command.
        int status = system(argv[2]);
        if (status == 0) {
            // Execute the second command.
            system(argv[3]);
        }
    } else if (strcmp(argv[1], "||") == 0) {
        // Execute the first command.
        int status = system(argv[2]);
        if (status != 0) {
            // Execute the second command.
            system(argv[3]);
        }
    } else {
        // The command is not `&&` or `||`.
        printf("Unknown command: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}
