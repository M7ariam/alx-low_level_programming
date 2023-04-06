#include "main.h"

/**
 * _pow_recursion - pow
 * @x: int
 * @y: int
 * Return: results
 */
int _pow_recursion(int x, int y)
{
	int sum = x;

	if (y > 0)
	{
		sum *= _pow_recursion(x, y - 1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
	return (sum);
}
