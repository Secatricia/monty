#include "monty.h"

/**
 * get_instruction - Prints all elements of a stack_t list.
 * @h: struc stack_t
 *
 * Return: Number of nodes
 */

void (*get_instruction(char *str))(stack_t **stack, unsigned int line_number)
{
	int i = 0, j = 0;
	char new[20];
	char number[20];

	instruction_t instructions[] = {
	    {"push", push_stack},
	    {"pall", pall},
	    {NULL, NULL},
	};

	while (str[i] != '\0') /*while file*/
	{
		if (str[i] == ' ') /*if space*/
			break;
		new[i] = str[i];
		i++;
	}

	while (str[i] != '\0') 
	{
		if ((str[i] < 58) && (str[i] > 47)) /*if it's number*/
		{
			number[j] = str[i];
		}
		j++;
		i++;
	}
	VALUE = atoi(number);
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
