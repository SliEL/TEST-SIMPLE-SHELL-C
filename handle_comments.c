#include "shell.h"

/**
 * remove_comment - removes the comment part from the lineptr
 * @lineptr: the command line entered by the user
 * Return: void - nothing.
 * fjhfoeheo \0 fekhfeokj
 */

void remove_comment(char *lineptr)
{
	char *comment_pos = _strchr(lineptr, '#');

	if (comment_pos != NULL)
		*comment_pos = '\0';
}

/**
 * is_empty_line - checks if the command line is empty
 * @lineptr: the command line entered by the user
 * Return: true if empty, false otherwise
 */

bool is_empty_line(char *lineptr)
{
	size_t i, len = _strlen(lineptr);

	for (i = 0; i < len; i++)
	{
		if (lineptr[i] != ' ' && lineptr[i] != '\t')
			return (false);
	}
	return (true);
}
