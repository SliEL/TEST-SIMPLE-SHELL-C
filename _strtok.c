#include "shell.h"

/**
 * _strtok - tokenize a str based on a del
 * @str: string to tokenize
 * @del: delimiters to check for
 * Return: tokens one by one or NULL;
 */

char *_strtok(char *str, char *del)
{
	char *start, *end;
	static char *token;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);

	start = token;
	while (*start != '\0' && _strchr(del, *start) != NULL)
		start++;
	end = start;
	while (*end != '\0' && _strchr(del, *end) == NULL)
		end++;

	if (start == end)
	{
		token = NULL;
		return (NULL);
	}

	if (*end != '\0')
	{
		*end = '\0';
		token = end + 1;
	}
	else
		token = NULL;

	return (start);
}
