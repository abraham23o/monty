#include "monty.h"
/**
 * _nop - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _nop(__attribute__ ((unused))stack_t **stack,
	  __attribute__ ((unused))unsigned int line_number)
{
	;
}
/**
 * _pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int val;

	if (*stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		error_exit(stack);
	}

	tmp = *stack;
	val = tmp->n;

	if (!isprint(val))
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		error_exit(stack);
	}

	putchar(val);
	putchar('\n');
}
/**
 * _pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void _pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp;
	int val;

	tmp = *stack;

	while (tmp != NULL)
	{
		val = tmp->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * _stack - sets sq_flag to stack
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void _stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	sq_flag = 0;
}
/**
 * _queue - sets sq_flag to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void _queue(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number)
{
	sq_flag = 1;
}
