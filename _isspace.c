#include "shell.h"

/**
 * _isspace - checks if char is space or not
 * Return int
 */

int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}
