#include "main.h"
/**
 * handle_errors - Handle errors and exit with error code
 * @error_code: Error code
 * @error_msg: Argument to print in error message
 * @fd: file descriptor value
 */
void handle_errors(int error_code, char *error_msg, int fd)
{
	switch (error_code)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		break;
	case 98:
		dprintf(STDERR_FILENO, READ_ERROR, error_msg);
		break;
	case 99:
		dprintf(STDERR_FILENO, WRITE_ERROR, error_msg);
		break;
	case 100:
		dprintf(STDERR_FILENO, CLOSE_ERROR, fd);
		break;
	}
	exit(error_code);
}
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, exit with error code otherwise
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_write;
	char buffer[BUFFER_SIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		handle_errors(97, NULL, 0);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		handle_errors(98, argv[1], 0);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		handle_errors(99, argv[2], 0);
		close(fd_from);
	}
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_write = write(fd_to, buffer, bytes_read);
		if (bytes_write == -1 || bytes_write != bytes_read)
		{
			if (close(fd_from) == -1)
				handle_errors(100, NULL, fd_from);
			if (close(fd_to) == -1)
				handle_errors(100, NULL, fd_to);
			handle_errors(99, argv[2], 0);
		}
	}

	if (close(fd_from) == -1)
		handle_errors(100, NULL, fd_from);

	if (close(fd_to) == -1)
		handle_errors(100, NULL, fd_to);

	if (bytes_read == -1)
		handle_errors(98, argv[1], 0);
	return (0);
}
