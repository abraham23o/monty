#include "monty.h"
/**
 * _sub - Subtracts the top element of the stack from the second top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	/* Function implementation */
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}
