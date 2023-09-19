#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Get the PATH environment variable.
    char *path = getenv("PATH");

    // Split the PATH environment variable into a list of directories.
    char *directories[1024];
    int num_directories = 0;
    char *directory = strtok(path, ":");
    while (directory != NULL) {
        directories[num_directories] = directory;
        num_directories++;
        directory = strtok(NULL, ":");
    }

    // Iterate over the list of directories and check if the command exists in each directory.
    for (int i = 0; i < num_directories; i++) {
        char full_path[1024];
        sprintf(full_path, "%s/%s", directories[i], argv[1]);

        if (access(full_path, F_OK) == 0) {
            // The command exists. Execute it and return.
            execve(full_path, NULL, NULL);
            return 0;
        }
    }

    // The command does not exist in any of the directories. Print an error message and exit the program.
    printf("Command not found: %s\n", argv[1]);
    exit(1);
}
