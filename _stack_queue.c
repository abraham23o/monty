#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	sq_flag = 0;
	(void)stack;
}

/**
 * _queue - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	sq_flag = 1;
	(void)stack;
}
