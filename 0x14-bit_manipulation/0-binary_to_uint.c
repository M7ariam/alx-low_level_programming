#include "main.h"
/**
 *binary_to_uint - converts a binary number to an unsigned int
 *@b: pointing to a string of 0 and 1 chars
 *Return: the converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int a = 0;

	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b == '0')
			a = a << 1;
		else if (*b == '1')
			a = (a << 1) | 1;
		else
			return (0);
		b++;
	}
	return (a);
}
