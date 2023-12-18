/* get_op_func.c */

#include "monty.h"

/**
 * get_op_func - selects the correct function to perform the operation
 * @str: opcode passed to the program
 *
 * Return: pointer to the function that corresponds to the opcode,
 * or NULL if opcode is not found
 */
instruct_func get_op_func(char *str)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		/* Add more opcodes as needed */
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
