#include "monty.h"

/**
 * exec - function to check opcode and execute
 * its respective function
 * @token: contains opcode and func to execute
 * @stack: doubly linked list representation of a stack
 * @lines: line_number opcode was found
 * Return: EXIT_SUCCESS, success
 */
int exec(char **token, stack_t **stack, unsigned int lines)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	for (; i < 10; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, lines);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", lines, token[0];
	return (EXIT_FAILURE);

}


/**
 * _push - function that adds elements to a stack
 * @stack: pointer to the top of the stack
 * @token: pointer to the command
 * @lines: the number of the line
 * Return: EXIT_SUCCESS, success
 */
int _push(stack_t **stack, char **token, unsigned int lines)
{
	stack_t *new;
	int i = 0;

	if (token[1] == NULL)
		return (ferrors(0, lines));

	while (token[1][i])
	{
		if (token[1][i] == '-')
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (ferrors(0, lines));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));

	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;

	return (EXIT_SUCCESS);
}


/**
 * _pushq - function that adds elements to a stack
 * @stack: pointer to the top of the stack
 * @token: pointer to the command
 * @lines: the number of the line
 * Return: EXIT_SUCCESS, success
 */
int _pushq(stack_t **stack, char **token, unsigned int lines)
{
	stack_t *new, *tmp = NULL;
	int i = 0;

	if (token[1] == NULL)
		return (ferrors(0, lines));

	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (ferrors(0, lines));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));

	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(token[1]);

	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}


/**
 * _pall - function that prints the values of a stack
 * @stack: pointer to the top of the stack
 * @lines: number of line
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int lines)
{
	stack_t *temp = *stack;

	void(lines);

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
