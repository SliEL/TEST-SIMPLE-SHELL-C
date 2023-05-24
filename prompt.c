#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char **envp = environ, **parsed_cmd;
	size_t cmd_len = 30;
	int num_char_read;
	char *lineptr = NULL, *setenv_cmd = "setenv", *full_path, *cmd;

	while (true)
	{
		isatty_check();
		num_char_read = _getline(&lineptr, &cmd_len, stdin);
		if (num_char_read == -1)
		{
			clean_lineptr(&lineptr);
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			remove_comment(lineptr);
			if (is_empty_line(lineptr))
			{
				clean_lineptr(&lineptr);
				continue;
			}
			parsed_cmd = split_cmd(lineptr);
			cmd = parsed_cmd[0];
			if (_strcmp(cmd, setenv_cmd) == 0)
			{
				_setenv(parsed_cmd[1], parsed_cmd[2]);
				clean_lineptr(&lineptr);
				continue;
			}
			if (handle_biultins(cmd, parsed_cmd[1]))
			{
				clean_lineptr(&lineptr);
				continue;
			}
			full_path = file_check(cmd);
			if (full_path)
			{
				parsed_cmd[0] = full_path;
				_execute(parsed_cmd, envp);
			}
		}
		clean_lineptr(&lineptr);
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (0);
}


/// function lineptr (commnd li kandkhlo f terminal cmd1; cmd2; cmd3
// function ==> [cmd1, cmd2, cmd3] == commands)
// for loop i=0; i<commands;
/// file.txt cmd1
