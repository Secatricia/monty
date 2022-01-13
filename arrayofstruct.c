#include "monty.h"

/**
 * get_instruction - Prints all elements of a stack_t list.
 * @str: string
 *
 * Return: Number of nodes
 */

void (*get_instruction(int numberline))(stack_t **stack, unsigned int line_number)
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

	fprintf(stderr, "L%d: unknown instruction %s\n", numberline, arguments[0]);
	free(arguments);
	exit(EXIT_FAILURE);
}

char **splitArgs(char *str)
{
	char **arg;
	char *tok;
	int i = 0;

	arg = malloc(sizeof(char *) * 3);
	if (arg == NULL)
		return (NULL);
	tok = strtok(str, " \t\n");
	while (i < 2)
	{
		arg[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
	}

	arguments[i] = NULL;

	return (arg);
}
