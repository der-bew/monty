#include "monty.h"

/**
 * add_o - Function implements the 'add' opcode
 * @stack: Head of stack
 * @line_number: current line number in file
 */
void add_o(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	delete_dnodeint_head(stack);
}

/**
 * nop_o - function implements the 'nop' opcode (does nothing)
 * @stack: head of stack
 * @line_number: current line number in file
 */
void nop_o(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_o - function implements the 'sub' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void sub_o(stack_t **stack, unsigned int line_number)
{
	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	delete_dnodeint_head(stack);
}

/**
 * div_o - function implements the 'div' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void div_o(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	delete_dnodeint_head(stack);
}

/**
 * mul_o - function implements the 'mul' opcode
 * @stack: head of stack
 * @line_number: current line number in file
 */
void mul_o(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		return;
	if (dlistint_len(*stack) < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_stuff();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	delete_dnodeint_head(stack);
}
