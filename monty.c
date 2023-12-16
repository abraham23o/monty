i#include "monty.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments passed
 * Return: 0 - success, 1 failure
 */
int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	exit_status = file_run(fptr);
	fclose(fptr);
	return (exit_status);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	file_run(fptr);
	exit(EXIT_SUCCESS);
	return (0);
}
