#include "monty.h"

/**
 * isnumber - Check if a string is a valid number
 * @str: The string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	if (!str || *str == '\0')

		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}
