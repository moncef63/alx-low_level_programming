#include "main.h"
/**
 * _strlen - length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int slong = 0;

	while (*s != '\0')
	{
		slong++;
		s++;
	}

	return (slong);
}
