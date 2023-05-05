#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index
 * @n: number
 * @index: index, starting from 0
 * Return: value of the bit at index index || -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int bit = n >> index;

	if (index >= sizeof(n) * 8)
		return (-1);
	return (bit & 1);
}
