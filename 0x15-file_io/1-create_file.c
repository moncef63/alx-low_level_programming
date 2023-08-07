#include "main.h"
/**
 * create_file - Creates a file and writes the provided text content to it.
 *
 * @filename: Pointer to the name of the file to create.
 * @text_content: Pointer to the string to write to the file.
 *
 * Return: On success, returns 1.
 *         On failure, returns -1.
 */
int create_file(const char *filename, char *text_content)
{
	int f, v, le = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (le = 0; text_content[le];)
			le++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	v = write(f, text_content, le);

	if (f == -1 || v == -1)
		return (-1);

	close(f);

	return (1);
}
