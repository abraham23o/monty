#include "monty.h"

/**
 * parse_line - Parses a line of Monty bytecode, extracting the opcode
 * @line: Line of Monty bytecode
 *
 * Return: The extracted opcode (or NULL if the line is a comment)
 */
char *parse_line(char *line)
{
	char *opcode;

	if (line[0] == '#') /* Ignore lines starting with '#' as comments */
		return (NULL);
	opcode = strtok(line, "\n ");
	return (opcode);
}
