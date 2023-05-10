#include "main.h"
#include <fcntl.h>

/**
 * create_file - creates a file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len = 0;

    if (!filename)
        return (-1);

    /* open file with write-only, create if not exist, truncate if exist */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        /* find length of text_content */
        while (text_content[len])
            len++;

        /* write text_content to file */
        if (write(fd, text_content, len) == -1)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

