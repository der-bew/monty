#include "monty.h"

/**
 * isnum - function checks if string contains only digits
 * @str: string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int isnum(char *str)
{
	int i;

	/* check if number is negative (begins with a dash) */
	if (str[0] == '-')
		str++;
	for (i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}
