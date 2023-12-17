#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *args;
	int push_val = 0;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	args = strtok(NULL, "\n ");
	if (isnumber(args) == 1 && args != NULL)
	{
		push_val = atoi(args);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_val);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_val);
	}

}
/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (tmp == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", tmp->n);
}
/**
 * _swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	i = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = i;
}
/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}
