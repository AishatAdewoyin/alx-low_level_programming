#include "main.h"

/**
 * read_textfile - This function reads a textfile and prints to
 * POSIX standard output.
 * @filename: The file to be read.
 * @letters: The number of characters to read from the file.
 * Return: The actual number of bytes read and printed to standard output.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t rbytes, wbytes;
	char *buffer;
	int fd;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	rbytes = read(fd, buffer, letters);
	if (rbytes == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	wbytes = write(STDOUT_FILENO, buffer, rbytes);
	if (wbytes == -1 || wbytes != rbytes)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (wbytes);
}
