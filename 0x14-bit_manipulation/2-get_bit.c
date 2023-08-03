#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a 10 number
 * @n: to search
 * @index: the  index of the bit
 *
 * Return:the value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bv;

	if (index > 63)
		return (-1);

	bv = (n >> index) & 1;

	return (bv);
}
