#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Pointer to name of file to read
 * @letters: Maximum number of letters to read
 * Return: The number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    char *buffer;
    ssize_t bytes_read, bytes_written;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return (0);
    }

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL) {
        close(fd);
        return (0);
    }

    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        free(buffer);
        close(fd);
        return (0);
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read) {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);
    return (bytes_written);
}

