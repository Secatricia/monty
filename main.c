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
	int numline = 0;
	char line[80] = {0}; /*initialisation*/
	stack_t *head = NULL;

	if (argc != 2) /*if argc does not have the right number of arguments*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r"); /*open file*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 80, file))
	{
		numline++;
		copy = str_trim(line);
		if (strlen(copy) != 0)
		{
			arguments = splitArgs(line);
			getinst(numline)(&head, numline);
			free(arguments);
		}
		free(copy);
	}
	free_dlistint(head);
	fclose(file);

	return (0);
}
