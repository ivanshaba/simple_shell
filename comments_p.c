#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *handle_comments(char *string) {
  // Split the string into a list of lines, using the newline character (\n) as the delimiter.
  char **lines = malloc(sizeof(char *) * 1024);
  if (lines == NULL) {
    return NULL;
  }

  int num_lines = 0;
  char *line = strtok(string, "\n");
  while (line != NULL) {
    lines[num_lines++] = line;
    line = strtok(NULL, "\n");
  }

  // Iterate over the list of lines and remove any lines that start with the # character.
  for (int i = 0; i < num_lines; i++) {
    if (lines[i][0] == '#') {
      lines[i] = NULL;
    }
  }

  // Join the list of lines back into a string.
  char *result = malloc(sizeof(char) * 1024);
  if (result == NULL) {
    return NULL;
  }

  int result_length = 0;
  for (int i = 0; i < num_lines; i++) {
    if (lines[i] != NULL) {
      int line_length = strlen(lines[i]);
      memcpy(result + result_length, lines[i], line_length);
      result_length += line_length;
      result[result_length++] = '\n';
    }
  }

  // Remove the trailing newline character.
  result[result_length - 1] = '\0';

  // Free the allocated memory.
  free(lines);

  return result;
}

int main() {
  // Get the string to handle comments for.
  char string[] = "This is a comment.\nHello, world!\n# This is another comment.\n";

  // Handle the comments in the string.
  char *new_string = handle_comments(string);

  // Print the string with the comments removed.
  printf("%s\n", new_string);

  // Free the allocated memory.
  free(new_string);

  return 0;
}
