#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", (*stack)->n);
}
