#include "main.h"
/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int i, m, strlong;

	strlong = 0;

	for (i = 0; str[i] != '\0'; i++)
		strlong++;

	m = (strlong / 2);

	if ((strlong % 2) == 1)
		m = ((strlong + 1) / 2);

	for (i = m; str[i] != '\0'; i++)
		_putchar(str[a]);
	_putchar('\n');
}
