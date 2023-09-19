#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "simple_shell> "

int main(void)
{
    char command[1024];

    while (1)
    {
        // Display the prompt.
        printf(PROMPT);

        // Read the command line from the user.
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        // Remove the newline character from the end of the command line.
        command[strlen(command) - 1] = '\0';

        // Try to find the executable for the command.
        char *path = getenv("PATH");
        char *executable = strtok(path, ":");
        while (executable != NULL)
        {
            char full_path[1024];
            sprintf(full_path, "%s/%s", executable, command);

            if (access(full_path, F_OK) == 0)
            {
                // Found the executable.
                execve(full_path, NULL, NULL);
                break;
            }

            executable = strtok(NULL, ":");
        }

        // If the executable could not be found, print an error message.
        if (executable == NULL)
        {
            printf("Command not found: %s\n", command);
        }
    }

    return 0;
}
