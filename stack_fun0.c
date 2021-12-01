#include "monty.h"

/**
 * print_dlistint - function prints all the elements of a
 * dlistint_t list
 * @h: head of list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len;

	for (len = 0; h; len++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (len);
}

/**
 * add_dnodeint - function adds a new node at the beginning
 * of a dlistint_ t list
 * @head: head of list
 * @n: value of new node
 *
 * Return: address of new element, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

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
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * free_dlistint - function frees a dlistint_t list
 * @head: head of list
 *
 * Return: none
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp = head;

	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}

/**
 * delete_dnodeint_head - functions deletes node from head of list
 * @head: head of doubly linked list
 *
 * Return: 1 on success, 0 otherwise
 */
int delete_dnodeint_head(dlistint_t **head)
{
	dlistint_t *tmp = *head;

	if (!tmp)
		return (-1);
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
	return (1);
}

/**
 * dlistint_len - function returns the number of elements in a linked
 * dlistint_t list
 * @h: head of list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len;

	for (len = 0; h; len++)
		h = h->next;
	return (len);
}
