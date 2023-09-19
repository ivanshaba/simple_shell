#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    // Get the list of environment variables.
    char **environ_list = environ;

    // Iterate over the list of environment variables and print each variable and its value.
    while (*environ_list != NULL) {
        printf("%s\n", *environ_list);
        environ_list++;
    }

    return 0;
}
