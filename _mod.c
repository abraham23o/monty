#include "monty.h"

/**
 * _mod - Computes the rest of the division of the second top element
 *        of the stack by the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
