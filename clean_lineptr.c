#include "shell.h"

/**
 * clean_lineptr - frees the lineptr and sets it to NULL
 * Return: nothing
 */

void clean_lineptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
