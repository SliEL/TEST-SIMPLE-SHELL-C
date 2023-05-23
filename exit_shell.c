#include "shell.h"
#include <stdbool.h>

bool is_valid_integer(const char *str);

/**
 * exit_shell - exits the shell
 * @code: str representation of the code to exit with
 * Return: nothing;
 */

void exit_shell(const char *code)
{
	int int_code;

	if (code && is_valid_integer(code))
	{
		int_code = _atoi(code);

		exit(int_code);
	}
	else if (code)
	{
		perror("Invalid Exit Code");
	}

	exit(EXIT_SUCCESS);
}

/**
 * is_valid_integer - checks if code is digit or not
 * @str: code to check
 * Return: bool true or false!
 */

bool is_valid_integer(const char *str)
{
	int i;

	/* Check if the string is empty */
	if (str[0] == '\0')
		return (false);

	/*Check if each character is a digit*/
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}

	return (true);
}
