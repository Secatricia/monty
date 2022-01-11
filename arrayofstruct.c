#include "monty.h"

void (*get_instruction(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char new[20];

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {NULL, NULL},
	};

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			break;
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';

	i = 0;
	while (instructions[i].f)
	{
		if (strcmp(new, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
