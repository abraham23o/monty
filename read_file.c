#include "monty.h"

/**
 * read_file - Read a Monty bytecode file and execute the instructions.
 * @filename: The name of the Monty bytecode file.
 * @stack: Pointer to the top of the stack.
 */
void read_file(char *filename, stack_t **stack)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode = parse_line(line);
		instruct_func op_func = get_op_func(opcode);

		line_number++;

		if (op_func)
			op_func(stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
}
