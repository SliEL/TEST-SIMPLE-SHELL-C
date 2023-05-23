#include "shell.h"

/**
 * is_pipeline_command - checks if cmd coming from pipe or not
 * Return: true if from pipeline otherwise false.
 */

bool is_pipeline_command(const char *cmd)
{
	/*Check if the command contains the pipeline character | */
	return (strchr(cmd, '|') != NULL);
}
