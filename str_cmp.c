#include "shell.h"

/**
 * _strcmp - compares two strings
 * @fstr: first string
 * @sstr: second string
 * Return: 0 if they match != 0 if not.
 */

int _strcmp(char *fstr, char *sstr)
{
	int i = 0;

	while (fstr[i] != '\0' && sstr[i] != '\0')
	{
		if (fstr[i] != sstr[i])
		{
			return (fstr[i] - sstr[i]);
		}
		i++;
	}
	return (0);
}
