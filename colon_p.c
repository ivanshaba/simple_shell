#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Split the script into a list of commands, using the `;` character as the delimiter.
    char *commands[1024];
    int num_commands = 0;
    char *command = strtok(argv[1], ";");
    while (command != NULL) {
        commands[num_commands++] = command;
        command = strtok(NULL, ";");
    }

    // Iterate over the list of commands and execute each command.
    for (int i = 0; i < num_commands; i++) {
        system(commands[i]);
    }

    return 0;
}
