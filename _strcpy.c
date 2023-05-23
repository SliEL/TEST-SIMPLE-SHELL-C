#include "shell.h"

/**
 * _strcpy - copies from src to dest a string
 * @dest: ptr to dest
 * @src: ptr to the source str
 */

char *_strcpy(char *dest, char *src)
{
	char *saved_dest = dest;

	while ((*dest++ = *src++))
		;
	return (saved_dest);
}
