#include "main.h"

/**
 * _isdigit - check if a character is a digit
 * @c: char to be checked
 *
 * Return: 1 for a character that will ba a digit or 0 for any else
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	return (1);
	else
	return (0);
}
