#include "monty.h"

/**
 * get_instruction - Prints all elements of a stack_t list.
 * @str: string
 *
 * Return: Number of nodes
 */

void (*get_instruction(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0, number;
	char *tok, **arg;
	static int line = 1;

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {NULL, NULL},
	};

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

	if (strcmp(arg[0], "push") == 0)
	{
		if (arg[1] == NULL)
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line++);
			exit(EXIT_FAILURE);
		}
		else
		{
			number = atoi(arg[1]);
			printf("--%d\n", number);
		}
	}

	i = 0;
	while (instructions[i].f)
	{
		if (strcmp(arg[0], instructions[i].opcode) == 0)
		{
			free(arg);
			return (instructions[i].f);
		}
		i++;
	}
	free(arg);
	return (NULL);
}
