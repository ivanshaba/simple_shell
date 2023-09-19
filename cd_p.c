#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check if the `DIRECTORY` argument is empty.
    if (argc == 1) {
        // Set the directory to the user's home directory.
        char *home_dir = getenv("HOME");
        if (chdir(home_dir) != 0) {
            printf("Failed to change directory to %s.\n", home_dir);
            exit(1);
        }
    } else if (strcmp(argv[1], "-") == 0) {
        // Change to the previous working directory.
        if (chdir("..") != 0) {
            printf("Failed to change directory to the previous working directory.\n");
            exit(1);
        }
    } else {
        // Change the current directory to the specified directory.
        if (chdir(argv[1]) != 0) {
            printf("Failed to change directory to %s.\n", argv[1]);
            exit(1);
        }
    }

    // Update the `PWD` environment variable to the new current directory.
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("Failed to get the current working directory.\n");
        exit(1);
    }

    if (setenv("PWD", cwd, 1) != 0) {
        printf("Failed to set the PWD environment variable.\n");
        exit(1);
    }

    return 0;
}
