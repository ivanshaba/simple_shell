#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_variables(char *string) {
    // Split the string into a list of words, using the whitespace character as the delimiter.
    char **words = malloc(sizeof(char *) * 1024);
    if (words == NULL) {
        return NULL;
    }

    int num_words = 0;
    char *word = strtok(string, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Iterate over the list of words and replace any variables with their values.
    for (int i = 0; i < num_words; i++) {
        char *variable = words[i];
        char *value = getenv(variable);

        if (value != NULL) {
            // Replace the variable with its value.
            words[i] = value;
        }
    }

    // Concatenate the list of words back into a string.
    char *result = malloc(sizeof(char) * 1024);
    if (result == NULL) {
        free(words);
        return NULL;
    }

    int result_length = 0;
    for (int i = 0; i < num_words; i++) {
        int word_length = strlen(words[i]);
        memcpy(result + result_length, words[i], word_length);
        result_length += word_length;
        result[result_length++] = ' ';
    }

    // Remove the trailing space.
    result[result_length - 1] = '\0';

    // Free the allocated memory.
    free(words);

    return result;
}
