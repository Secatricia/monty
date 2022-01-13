#include "monty.h"

/**
 * str_trim - Trim the spaces of a string
 * @str: str to trim
 *
 * Return: Str trimmed or NULL if str = NULL
 *
 */

char *str_trim(char *str)
{
	size_t len = strlen(str);
	char *dup;

	if (str == NULL)
		return (NULL);
	if (len == 0)
		return (str);

	while (isspace(str[len - 1])) /*delete space after*/
	{
		len--;
	}

	while (*str && isspace(*str)) /*delete spaces before*/
	{
		str++;
		len--;
	}
	dup = strndup(str, len);
	return (dup);
}
