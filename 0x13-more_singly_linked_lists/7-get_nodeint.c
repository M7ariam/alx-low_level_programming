#include "lists.h"
/**
 *get_nodeint_at_index - returns the nth node of a listint_t linked list
 *@head: node
 *@index: index
 *Return: returns the nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (head != NULL && index)
	{
		head = head->next;
		index--;
	}
	return (head);
}
