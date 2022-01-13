#include "monty.h"

/**
 * isNumber - check if arg[1] is a number
 * @str: string
 *
 * Return: int
 */

int isNumber(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (isdigit(str[i]))
		{
			i++;
			continue;
		}
		else
			return (1);
	}
	return (0);
}
