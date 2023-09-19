#include <stdio.h>
#include <stdlib.h>

// Static buffer used to store the input line.
static char *buffer;
// Static buffer size.
static size_t buffer_size;

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    // If the buffer is not initialized, allocate a new buffer.
    if (buffer == NULL) {
        buffer_size = 1024;
        buffer = malloc(buffer_size);
        if (buffer == NULL) {
            return -1;
        }
    }

    // Read a line of input into the buffer.
    ssize_t bytes_read = fread(buffer, 1, buffer_size, stream);
    if (bytes_read == 0) {
        // End of file.
        return -1;
    }

    // Find the newline character in the buffer.
    char *newline = strchr(buffer, '\n');
    if (newline != NULL) {
        // Replace the newline character with a null terminator.
        *newline = '\0';

        // Set the line pointer to the buffer.
        *lineptr = buffer;

        // Set the number of bytes in the line.
        *n = newline - buffer + 1;

        // Move the buffer to the next line.
        buffer += *n;

        return *n;
    }

    // If the newline character was not found in the buffer, the line is longer than the buffer.
    // Reallocate the buffer to be twice as large.
    buffer_size *= 2;
    buffer = realloc(buffer, buffer_size);
    if (buffer == NULL) {
        return -1;
    }

    // Read the rest of the line into the buffer.
    bytes_read += fread(buffer + bytes_read, 1, buffer_size - bytes_read, stream);
    if (bytes_read == 0) {
        // End of file.
        return -1;
    }

    // Recursively call getline() to read the rest of the line.
    return getline(lineptr, n, stream);
}
