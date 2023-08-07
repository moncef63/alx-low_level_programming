#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include
#include
char *create_buffer(char *file); void close_file(int fd);
/**
 * create_buffer - Allocates memory for a buffer to store characters from a file.
 *
 * @file: The name of the file the buffer will be used for.
 *
 * Return: A pointer to the newly-allocated buffer, or NULL if memory allocation fails.
 */
char *create_buffer(char *file)
{
	char *bf;

	bf = malloc(sizeof(char) * 1024);

	if (bf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bf);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int cn;

	cn = close(fd);

	if (cn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, otherwise appropriate exit codes:
 *     97: Incorrect argument count.
 *     98: Unable to read from file_from or file_from does not exist.
 *     99: Unable to create or write to file_to.
 *    100: Unable to close file_to or file_from.
 *
 * Description: This program copies the contents of a file specified by file_from
 *     to another file specified by file_to. It ensures proper error handling and
 *     displays corresponding error messages on the standard error stream (stderr).
 */
int main(int argc, char *argv[])
{
	int fm, t, rd, wt;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	fm = open(argv[1], O_RDONLY);
	rd = read(fm, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fm == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wt = write(t, buffer, rd);
		if (t == -1 || wt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rd = read(fm, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buffer);
	close_file(fm);
	close_file(t);

	return (0);
}
