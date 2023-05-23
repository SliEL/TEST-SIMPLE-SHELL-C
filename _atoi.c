#include "shell.h"

/**
 * _atoi - convert a string representation of an integer to its
 * corresponding integer value.
 * @str: ptr to the string representation of the int
 * Return: int value of the number
 */

int _atoi(const char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	/* skip leading whitespace characters */
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	/* Check for a sign */
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	/* Convert digits to integer */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}
