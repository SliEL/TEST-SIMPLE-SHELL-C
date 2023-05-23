#include "shell.h"
#include <dirent.h>

char *search_in_directory(char *directory, char *command);
char *add_trailing_slash(char *path);

/**
 * search_in_path - search for the exe/cmd file in the PATH variable
 * @command: ptr to the cmd file name that we look for
 * Return: full path that we will give to the execve function. /bin/
 */

char *search_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *path_item, *full_path;
	char *delimiter = ":";

	if (!path)
	{
		perror("Failed to get value of PATH");
		exit(EXIT_FAILURE);
	}
	path_copy = strdup(path);
	token = _strtok(path_copy, delimiter);

	while (token)
	{
		path_item = add_trailing_slash(token);
		full_path = search_in_directory(path_item, command);
		if (full_path != NULL)
		{
			free(path_copy);
			free(path_item);
			return (full_path);
		}
		free(path_item);
		token = _strtok(NULL, delimiter);
	}

	free(path_copy);
	return (NULL);
}

/**
 * add_trailing_slash - adds the / to items of PATH
 * @path: pointer to path item from PATH list
 * Return: new path
 */

char *add_trailing_slash(char *path)
{
	size_t path_len = _strlen(path);
	char *new_path = malloc(path_len + 2);
	char *trailing_slash = "/";

	if (!new_path)
	{
		perror("FAILED TO ALLOCATE MEMORY!");
		exit(EXIT_FAILURE);
	}
	_strcpy(new_path, path);
	_strcat(new_path, trailing_slash);
	return (new_path);
}

/**
 * search_in_directory - searchs for the cmd file in each path/dir
 * item of the PATHS
 * @directory: pointer to the path to check
 * @command: ptr to the cmd file name that we look for
 * Return: pointer to the ful path.
 */

char *search_in_directory(char *directory, char *command)
{
	DIR *dir = opendir(directory);
	struct dirent *entry;
	size_t full_path_len;
	char *full_path;

	if (!dir)
	{
		perror("FAILED TO OPEN THE DIRECTORY!");
		exit(EXIT_FAILURE);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, command) == 0)
		{
			full_path_len = _strlen(directory) + _strlen(command) + 2;
			full_path = malloc(full_path_len);

			if (!full_path)
			{
				perror("FAILED TO ALLOCATE MEMORY!");
				exit(EXIT_FAILURE);
			}
			_strcpy(full_path, directory);
			_strcat(full_path, command);
			closedir(dir);
			return (full_path);
		}
	}
	closedir(dir);
	return (NULL);
}
