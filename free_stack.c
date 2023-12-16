#include "monty.h"

/**
 * free_stack - free memory allocated to a stack
 * @stack: pointer to the doubly linked list rep. of a stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
