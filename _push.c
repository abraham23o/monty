#include "monty.h"
/**
 * _push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *args;
	int push_val;

	args = strtok(NULL, "\n ");
	if (isnumber(args) == 1 && args != NULL)
	{
		push_val = atoi(args);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_val);
	}
	else
	{
		add_dnodeint(stack, push_val);
	}
}
