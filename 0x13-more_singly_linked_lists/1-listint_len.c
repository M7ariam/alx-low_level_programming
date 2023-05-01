#include "lists.h"

/**
 * listint_len - Count the length of a linked list
 * @h: Pointer to head of list
 * Return: The length of the linked list
 */
size_t listint_len(const listint_t *h)
{
	int count = 0;

	for (; h; h = h->next, count++)
		;

	return (count);
}
