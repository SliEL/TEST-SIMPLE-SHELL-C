#include "shell.h"

/**
 * _strlen - return len of str
 * @str: the string
 * Return: len of the str
 */

size_t _strlen(const char *str)
{
	const char *end = str;

	while (*end)
		++end;
	return ((size_t)(end - str));
}
