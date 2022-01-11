#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arrays of arguments
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *current, line[80] = {0};
	FILE *file;
	stack_t *head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 80, file))
	{
		current = str_trim(line);
		get_instruction(current)(&head, 3);
		free(current);
	}

	fclose(file);

	return (0);
}
