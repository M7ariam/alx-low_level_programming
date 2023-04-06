#include "main.h"

/**
 * factorial - fac
 * @n: int
 * Return: results
 */
int factorial(int n)
{
	int sum = n;

	if (n < 0)
	{
		return (-1);
	}
	else if (n == 1)
	{
		return (1);
	}
	else
	{
		sum *= factorial(n - 1);
	}
	return (sum);
}
