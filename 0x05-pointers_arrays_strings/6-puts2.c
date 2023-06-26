#include "main.h"
/**
 * puts2 - function print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int strlong = 0;
	int m = 0;
	char *p = str;
	int i;

	while (*p != '\0')
	{
		p++;
		strlong++;
	}
	m = strlong - 1;
	for (i = 0 ; i <= m ; i++)
	{
		if (i % 2 == 0)
	{
		_putchar(str[i]);
	}
	}
	_putchar('\n');
}
