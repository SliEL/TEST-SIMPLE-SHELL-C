#include "shell.h"

/**
 * isatty_check - checks if cmd from terminal
 * Return: nothing
 */

void isatty_check(void)
{
	char *prompt;
	if (isatty(STDIN_FILENO))
	{
		prompt = set_prompt();
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		fflush(stdout);
	}
}
