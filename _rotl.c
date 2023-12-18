#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		*stack = temp->next;
		(*stack)->prev = NULL;

		temp->next = NULL;
		temp->prev = last;
		last->next = temp;
	}
}
