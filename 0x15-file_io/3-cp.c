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
	int file_from, file_to, close_from, close_to;
	ssize_t readByte, writeByte;
	char buffer[BUF_TO_READ_FROM_INPUT];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
			exit(98);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	do {
		readByte = read(file_from, buffer, BUF_TO_READ_FROM_INPUT);
		if (readByte == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]),
				exit(98);

		writeByte = write(file_to, buffer, readByte);
		if (writeByte == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	} while (readByte > 0);

	close_from = close(file_from);
	if (close_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	close_to = close(file_to);
	if (close_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}
