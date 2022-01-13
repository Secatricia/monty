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
	char *copy;
	FILE *file;
	stack_t *head;

	if (argc != 2) /*if argc does not have the right number of arguments*/
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r"); /*open file*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}

	arguments = malloc(sizeof(char *) * 3);
	if (arguments == NULL)
		exit(EXIT_FAILURE);

	while (fgets(line, 80, file))
	{
		numline++;
		copy = str_trim(line);
		if (strlen(copy) != 0)
		{
			arguments = splitArgs(line);
			get_instruction(numline)(&head, numline);
			free(arguments);
		}
	}
	free_dlistint(head);
	fclose(file);

	return (0);
}
