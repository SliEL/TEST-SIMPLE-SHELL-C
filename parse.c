#include "shell.h"

/**
 * parse - parses the lineptr and execute
 * @lineptr: line of the command
 * @envp: env variable
 * Return: Nothing
 */

void parse(char *lineptr, char **envp)
{
	char **parsed_cmd;
	char *setenv_cmd = "setenv";
	char *full_path, *cmd;

	remove_comment(lineptr);
	if (is_empty_line(lineptr))
	{
		clean_lineptr(lineptr);
		return;
	}
	parsed_cmd = split_cmd(lineptr);
	cmd = parsed_cmd[0];
	if (_strcmp(cmd, setenv_cmd) == 0)
	{
		_setenv(parsed_cmd[1], parsed_cmd[2]);
		/*clean_lineptr(lineptr);*/
		return;
	}
	if (handle_biultins(cmd, parsed_cmd[1]))
	{
		/*clean_lineptr(lineptr);*/
		return;
	}
	full_path = file_check(cmd);
	if (full_path)
	{
		parsed_cmd[0] = full_path;
		_execute(parsed_cmd, envp);
	}
	/*clean_lineptr(lineptr);*/
}
