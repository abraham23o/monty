#include "monty.h"

/**
 * usage_error - function that prints usage error message
 * @i: type of error; 0, malloc failed 1, usage error
 * Return: EXIT_FAILURE
 */
int usage_error(int i)
{
	char *errs[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errs[i])
	return (EXIT_FAILURE);
}


/**
 * open_error - function that prints the error message when file fails to open
 * @filename: file to be opened
 * Return: EXIT_FAILURE
 */
int open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * ferrors - function that prints error messages
 * @i: iterator through errors
 * @lines: the number of line with error
 * Return: EXIT_FAILURE
 */
int ferrors(int i, unsigned int lines)
{
	char *errs[] = {"usage: push integer", "can\'t pint , stack empty",
			"can\'t pop an empty stack", can\'t swap, stack too short",
			"can\'t add, stack too short", can\'t sub, stack too short",
			"can\'t div, stack too short", "division by zero",
			"can\'t mul, stack too short", can\'t mod, stack too short",
		};

	fprintf(stderr, "L%d: %s\n", lines, errs[i]);
	return (EXIT_FAILURE);
}
