#include "monty.h"

/**
 * add_dnodeint_end - function adds a new node at the end of a
 * doubly linked list
 * @head: head of list
 * @n: value of new node
 *
 * Return: address of new element, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		malloc_fail();
	new->n = n;
	if (!*head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	return (new);
}
