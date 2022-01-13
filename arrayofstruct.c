#include "monty.h"

/**
 * get_instruction - Gets correct function
 * @nline: int
 *
 * Return: Void
 */

void (*get_instruction(int nline, FILE *file, char *copy))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {"pint", pint},
	    {NULL, NULL},
	};

	while (instructions[i].f)
	{
		if (strcmp(arguments[0], instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", nline, arguments[0]);
	fclose(file);
	free(copy);
	free(arguments);
	exit(EXIT_FAILURE);
}

/**
 * splitArgs - Split the argument into an array
 * @str: string
 *
 * Return: pointer of pointer
 */

char **splitArgs(char *str)
{
	char *tok;
	int i = 0;

	arguments = malloc(sizeof(char *) * 3);
	if (arguments == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(str, " \t\n");
	while (i < 2)
	{
		arguments[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
	}
	arguments[i] = NULL;

	return (arguments);
}
