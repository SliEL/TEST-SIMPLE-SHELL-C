#include "shell.h"

/**
 * _setenv - function to set new varaibles using the setenv
 * @variable: ptr to the variable
 * @value: value to set for the variable
 * Return: true if success, false otherwise
 */

void _setenv(char *variable, char *value)
{
	if (variable != NULL && value != NULL)
	{
		if (setenv(variable, value, 1) != 0)
		{
			perror("setenv failed!");
		}
	}
	else
		perror("setenv: Invalid command syntax!");
}

/*
	char *v = getenv(variable);
	if (v != NULL)
	{
		printf("Variable %s is set to %s\n", variable, v);
	}
	else
	{
		printf("Variable %s not found\n", variable);
	}
*/
