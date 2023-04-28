#include "lists.h"
/**
 * list_len - returns the number of elements in a list_t list
 * @h: pointer to the head of the list_t list
 * Return: the number of elements in the list_t list
 */
size_t list_len(const list_t *h)
{
	int nbr = 0;

	while (h != NULL)
	{
		nbr++;
		h = h->next;
	}
	return (nbr);
}
