#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file to append to
 * @text_content: The content to be appended to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_count = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[write_count] != '\0')
			write_count++;
	}

	if (write(fd, text_content, write_count) == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
