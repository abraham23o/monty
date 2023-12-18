#include "monty.h"
/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	/* Function implementation */
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error_exit(stack);
	}

	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}
