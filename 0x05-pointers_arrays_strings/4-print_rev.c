#include "main.h"
/**
 * print_rev - imprime en reversa
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int slong = 0;
	int i;

	while (*s != '\0')
	{
		slong++;
		s++;
	}
	s--;
	for (i = slong; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
