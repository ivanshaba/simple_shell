#include <stdlib.h>
#include <string.h>

char **split(char *string, char *delimiter) {
    // Allocate an array to store the split strings.
    char **split_strings = malloc(sizeof(char *) * 1024);
    if (split_strings == NULL) {
        return NULL;
    }

    // Initialize the number of split strings.
    size_t num_split_strings = 0;

    // Iterate over the string and split it into substrings at the delimiter.
    char *substring = strtok(string, delimiter);
    while (substring != NULL) {
        // Allocate a string to store the substring.
        char *substring_string = malloc(strlen(substring) + 1);
        if (substring_string == NULL) {
            // Free the allocated memory and return NULL.
            for (size_t i = 0; i < num_split_strings; i++) {
                free(split_strings[i]);
            }
            free(split_strings);
            return NULL;
        }

        // Copy the substring to the new string.
        strcpy(substring_string, substring);

        // Add the new string to the array of split strings.
        split_strings[num_split_strings++] = substring_string;

        // Get the next substring.
        substring = strtok(NULL, delimiter);
    }

    // Add a NULL pointer to the end of the array to indicate the end of the list.
    split_strings[num_split_strings] = NULL;

    return split_strings;
}
