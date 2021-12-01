#include "monty.h"

help_t *main_s = NULL;

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: exit status
 */
int main(int ac, char **av)
{
	instruction_t coms[] = {
		{"push", push_o},
		{"pall", pall_o},
		{"pint", pint_o},
		{"pop", pop_o},
		{"swap", swap_o},
		{"add", add_o},
		{"nop", nop_o},
		{"sub", sub_o},
		{"div", div_o},
		{"mul", mul_o},
		{"mod", mod_o},
		{"pstr", pstr_o},
		{"rotl", rotl_o},
		{"pchar", pchar_o},
		{"rotr", rotr_o},
		{"stack", stack_o},
		{"queue", queue_o},
		{NULL, NULL}
	};

	if (ac != 2)
		file_err(NULL);
	main_s = malloc(sizeof(help_t));
	if (!main_s)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	main_s->fp = fopen(av[1], "r");
	if (!main_s->fp)
		file_err(av[1]);
	main_s->push_n = NULL;
	main_s->buff = NULL;
	main_s->stack_s = NULL;
	main_s->data = 1;
	main_loop(coms);
	return (0);
}
