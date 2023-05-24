#include "shell.h"

/**
 * costum_setenv - it adds a new variable to env
 * @name: varaible name
 * @value: value to set for the variable
 * @overwrite: flag to see if the variable already exists
 * Return: 0 on success, -1 on failure.
 */

int custom_setenv(char *name, char *value, int overwrite)
{
	size_t nameLen = _strlen(name);
	size_t valueLen = _strlen(value);
	size_t bufferSize = nameLen + valueLen + 2;
	int result;
	char *buffer;

	if (name == NULL || value == NULL)
		return (-1);

	if (!overwrite && getenv(name) != NULL)
		return (0);

	buffer = (char *)malloc(bufferSize);

	if (buffer == NULL)
		return -1;

	_strcpy(buffer, name);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	result = putenv(buffer);

	if (result != 0)
	{
		free(buffer);
		return -1;
	}

	return (0);
}
