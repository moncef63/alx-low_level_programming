#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints its content to STDOUT.
 *
 * @filename: The name of the text file being read.
 * @letters: The number of letters to be read from the file.
 *
 * Return: The actual number of bytes read and printed (w).
 *         Returns 0 when the function fails or when filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bu;
	ssize_t f;
	ssize_t v;
	ssize_t b;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	bu = malloc(sizeof(char) * letters);
	b = read(f, bu, letters);
	v = write(STDOUT_FILENO, bu, b);

	free(bu);
	close(f);
	return (v);
}
