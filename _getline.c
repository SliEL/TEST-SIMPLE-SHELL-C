#include "shell.h"

/**
 * _getline - our own getline func
 * @lineptr: A pointer to a pointer that will store the
 *  address of the dynamically allocated buffer
 *  where the line will be stored
 * @n: ptr to size_t var that stores the size of the allocated buffer
 * @stream: the file stream from which we read the data
 * Return: -1 on failure or num of chars read.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_chars_read = 0;
	ssize_t chars_read;
	char *newlineptr;
	char c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 0;
		*lineptr = malloc(*n);
		if (!(*lineptr))
			return (-1);
	}

	while ((chars_read = read(fileno(stream), &c, 1)) != -1)
	{
		if (num_chars_read >= (ssize_t)(*n) - 1)
		{
			*n += 64;
			newlineptr = realloc(*lineptr, *n);

			if (!newlineptr)
				return (-1);
			*lineptr = newlineptr;
		}

		(*lineptr)[num_chars_read++] = c;

		if (c == '\n')
			break;
	}

	if (num_chars_read == 0 && chars_read == -1)
		return (-1);

	(*lineptr)[num_chars_read] = '\0';
	return (num_chars_read);
}
