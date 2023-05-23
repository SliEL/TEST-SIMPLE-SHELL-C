#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @first: first string
 * @second: second string
 * Return: concateated string (firstsecond)
 */

char *_strcat(char *first, char *second)
{
	int first_len = 0, i = 0;

	while (first[first_len] != '\0')
		first_len++;

	while (second[i] != '\0')
	{
		first[first_len + i] = second[i];
		i++;
	}

	first[first_len + i] = '\0';

	return (first);
}
