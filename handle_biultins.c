#include "shell.h"

/**
 * handle_biultins - handle biult in cmds *exit
 * @cmd: the cmd to check
 * @param: second parameter
 * Return: bool true or false
 */

bool handle_biultins(char *cmd, char *param)
{
	char *Exit = "exit", *cd = "cd";

	if (_strcmp(cmd, Exit) == 0)
	{
		exit_shell(param);
	}
	else if (_strcmp(cmd, cd) == 0)
	{
		if (param == NULL)
		{
			change_directory(NULL);
		}
		else
		{
			change_directory(param);
		}
	}
	else
		return (false);
	return (true);
}
