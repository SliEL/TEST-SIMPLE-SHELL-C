#include "shell.h"
#include <dirent.h>

/**
 * file_check - checks on /bin/ to see if file exe exists
 * @command: file name // ls or mkdir etc -- ls will return /bin/ls
 * Return: full path to the file or NULL;
 */

char *file_check(char *command)
{
	char *full_path = search_in_path(command);

	if (full_path == NULL)
	{
		/* Command not found in any directory of PATH */
		return (command);
	}

	return (full_path);
}
