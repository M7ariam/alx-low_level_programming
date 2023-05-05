#include "main.h"
/**
 * flip_bits - Returns the number of bits you would need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bit
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	int i = 0;

	while (flip)
	{
		i++;
		flip &= (flip - 1);
	}

	return (i);
}
