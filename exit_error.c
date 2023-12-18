#include "monty.h"

/**
 * error_exit - Print an error message and exit with failure status
 * @stack: Pointer to the stack
 */
void error_exit(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
}
