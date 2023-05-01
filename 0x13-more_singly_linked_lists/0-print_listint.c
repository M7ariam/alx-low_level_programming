#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	int count = 0;

	for (; h; h = h->next, count++)
		printf("%d\n", h->n);

	return (count);
}
