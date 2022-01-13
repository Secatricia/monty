#include "monty.h"

/**
 * getinst - Gets correct function
 * @lin: int
 *
 * Return: Void
 */

void (*getinst(int lin))(stack_t **sck, unsigned int lin)
{
	int i = 0;

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"add", add},
	    {NULL, NULL},
	};

	while (instructions[i].f)
	{
		if (strcmp(arguments[0], instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lin, arguments[0]);
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
