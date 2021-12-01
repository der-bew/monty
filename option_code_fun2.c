#include "monty.h"

/**
 * mod_o - Function implements the 'mod' opcode
 * @stack: Head of stack
 * @line_number: Current line number in file
 */
void mod_o(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	delete_dnodeint_head(stack);
}

/**
 *  pstr_o - function implements the 'pstr' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void pstr_o(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_o - function implements the 'rotl' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void rotl_o(stack_t **stack, unsigned int line_number)
{
	int first;
	stack_t *tmp;

	if (!stack)
		return;
	if (dlistint_len(*stack) < 2)
		return;
	else if (dlistint_len(*stack) == 2)
	{
		swap_o(stack, line_number);
		return;
	}
	tmp = *stack;
	first = tmp->n;
	while (tmp->next)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = first;
}

/**
 * rotr_o - function implements the 'rotr' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void rotr_o(stack_t **stack, unsigned int line_number)
{
	int first;
	stack_t *tmp;

	if (!stack)
		return;
	if (dlistint_len(*stack) < 2)
		return;
	else if (dlistint_len(*stack) == 2)
	{
		swap_o(stack, line_number);
		return;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	first = tmp->n;
	while (tmp->prev)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	tmp->n = first;
}
