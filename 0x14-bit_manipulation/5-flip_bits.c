#include "main.h"

/**
 * flip_bits - counts the bits to change
 * to get from one number to another
 * @n: 1 number
 * @m: 2 number
 *
 * Return: the number of bits 
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, c = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			c++;
	}

	return (c);
}
