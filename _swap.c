#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	 stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}
