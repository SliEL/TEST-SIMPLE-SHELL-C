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
	/*Check if the line is empty (contains no characters)*/
	if (*lineptr == '\0')
		return (true);

	/* Iterate over the characters and check if they are all spaces or tabs*/
	while (*lineptr != '\0')
	{
		if (!(_isspace(*lineptr)))
			return (false);
		lineptr++;
	}

	return (true);
}
