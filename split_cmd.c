#include "shell.h"

/**
 * split_cmd - splits the cmd to get the path/flags
 * @line: the ptr to the cmd entered by the user
 *
 * Return: array of tokens (path/flags)
 * Description: we use the built in strtok function
 * to get the tokens from the command line.
 */

char **split_cmd(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Failed to reallocate memory");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " ");
	}

	tokens[position] = NULL;
	return (tokens);
}
