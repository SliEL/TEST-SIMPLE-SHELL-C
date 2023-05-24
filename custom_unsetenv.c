#include "shell.h"

/**
 * costum_unsetenv - custom unsetenv
 * @name: variable name to unset
 * Return: 0 onsucess and -1 on failure
 */

int custom_unsetenv(char *name)
{
	extern char **environ;
	char **env = environ;
	char **curr, **next;

	if (name == NULL || strlen(name) == 0 || strchr(name, '=') != NULL)
		return (-1);

	/*Iterate through the environment variables*/
	while (*env != NULL)
	{
		if (strncmp(*env, name, _strlen(name)) == 0 && (*env)[_strlen(name)] == '=')
		{
			/*Match found, remove the variable by shifting the rest of the array*/
			curr = env;
			next = env + 1;

			while (*curr != NULL)
			{
				*curr = *next;
				curr++;
				next++;
			}

			return (0);
		}

		env++;
	}

	return (-1);
}
