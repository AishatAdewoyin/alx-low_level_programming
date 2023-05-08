#include "main.h"
#define BUF_TO_READ_FROM_INPUT 1024

/**
 * main - This program copies the content of a file to another file
 * @argc: Argument count parameter
 * @argv: argument vector parameter
 * Return: 0 when successful otherwise, an exit status
 */
int main(int argc, char *argv[])
{
	int fileFro, fileTo, closeFro, closeTo;
	ssize_t readByte, writeByte;
	char buffer[BUF_TO_READ_FROM_INPUT];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(EXIT_FAILURE);
	}
	fileFro = open(argv[1], O_RDONLY);
	if (fileFro == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fileTo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	do {
		readByte = read(fileFro, buffer, BUF_TO_READ_FROM_INPUT);
		if (readByte == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		writeByte = write(fileTo, buffer, readByte);
		if (writeByte == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
	} while (readByte > 0);

closeFro = close(fileFro);
if (closeFro == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFro);
	exit(EXIT_FAILURE);
}
	closeTo = close(fileTo);
if (closeTo == -1)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileTo);
	exit(EXIT_FAILURE);
}
	return (0);
}
