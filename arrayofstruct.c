#include "monty.h"

/**
 * get_instruction - Prints all elements of a stack_t list.
 * @str: string
 *
 * Return: Number of nodes
 */

void (*get_instruction(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char **args;
	static int line = 1;

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {"pint", pint},
	    {NULL, NULL},
	};

	args = splitArgs(str);

	if (strcmp(args[0], "push") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line++);
			exit(EXIT_FAILURE);
		}
	}

	i = 0;
	while (instructions[i].f)
	{
		if (strcmp(args[0], instructions[i].opcode) == 0)
		{
			free(args);
			return (instructions[i].f);
		}
		i++;
	}
	free(args);
	return (NULL);
}

char **splitArgs(char *str)
{
	char **arg;
	char *tok;
	int i = 0;

	arg = malloc(sizeof(char *) * 2);
	if (arg == NULL)
		return (NULL);
	tok = strtok(str, " ");
	while (tok)
	{
		arg[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}

	return (arg);
}
