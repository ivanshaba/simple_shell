#ifndef CUSTOM_GETLINE_H
#define CUSTOM_GETLINE_H

// Function prototype
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

#endif /* CUSTOM_GETLINE_H */

#ifndef STRING_SPLITTING_H
#define STRING_SPLITTING_H

// Function prototype
char **splitString(char *string, char *delimiter);

#endif /* STRING_SPLITTING_H */

#ifndef SHELL_COMMANDS_H
#define SHELL_COMMANDS_H

// Function prototypes
void processShellCommand(int argc, char *argv[]);

#endif /* SHELL_COMMANDS_H */

#ifndef ENV_VARIABLE_MANIPULATION_H
#define ENV_VARIABLE_MANIPULATION_H

// Function prototypes
void setEnvironmentVariable(int argc, char *argv[]);
void unsetEnvironmentVariable(int argc, char *argv[]);

#endif /* ENV_VARIABLE_MANIPULATION_H */

#ifndef CHANGE_DIRECTORY_H
#define CHANGE_DIRECTORY_H

// Function prototypes
void changeDirectory(int argc, char *argv[]);

#endif /* CHANGE_DIRECTORY_H */
