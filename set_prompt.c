#include "shell.h"

/**
 * set_promot - sets the prompts to cwd
 * Return: prompt
 */

char *set_prompt()
{
	char current_dir[PATH_MAX];
	static char prompt[PATH_MAX + 4];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	_strcpy(prompt, current_dir);
	_strcat(prompt, ">> ");
	return (prompt);
}
