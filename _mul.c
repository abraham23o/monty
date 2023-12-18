#include "monty.h"

/**
 * _mul - Multiplies the second top element of the stack with the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}
	temp->next->n *= temp->n;

	*stack = temp->next;

	temp->next->prev = NULL;
	free(temp);
}
