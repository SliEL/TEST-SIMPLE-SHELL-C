#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char **envp = environ;
	size_t cmd_len = 30;
	int num_char_read;
	char *lineptr = NULL;

	while (true)
	{
		isatty_check();
		num_char_read = getline(&lineptr, &cmd_len, stdin);
		if (num_char_read == -1)
		{
			clean_lineptr(lineptr);
			exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			parse(lineptr, envp);
		}
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (0);
}
