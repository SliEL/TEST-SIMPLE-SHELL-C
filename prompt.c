#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char **envp = environ, **parsed_cmd;
	size_t cmd_len = 30;
	int num_char_read;
	char *lineptr = NULL, *full_path, *cmd;

	while (true)
	{
		isatty_check();
		num_char_read = _getline(&lineptr, &cmd_len, stdin);
		if (num_char_read == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			parsed_cmd = split_cmd(lineptr);
			cmd = parsed_cmd[0];
			if (handle_biultins(cmd, parsed_cmd[1]))
			{
				free(lineptr);
				lineptr = NULL;
				continue;
			}
			full_path = file_check(cmd);
			if (full_path)
			{
				parsed_cmd[0] = full_path;
				_execute(parsed_cmd, envp);
			}
		}
		free(lineptr);
		lineptr = NULL;
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (0);
}
