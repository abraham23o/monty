#include "monty.h"

/**
 * _rotr - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
