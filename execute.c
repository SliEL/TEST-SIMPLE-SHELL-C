#include "shell.h"
#include <sys/wait.h>

/**
 * _execute - execute the cmd with the execve sys function
 * @argv: array of tokens we got from spliting the cmd
 * @envp: env variables from the parent process
 *
 * Return: nothing (void)
 *
 * Description: calls the fork to create a child process
 * Then it handles the cases for fork return
 * if fork returns a negative value - raise error
 * else if fork return 0 => execute the command
 * else wait () to return to parent process.
 */

void _execute(char **argv, char **envp)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	/* check the value returned from the child process */
	if (child_pid == -1)
	{
		perror("Fork Error: no child process was created");
		return;
	}
	/* sucess for fork - child process on */
	else if (child_pid == 0)
	{
		execve(argv[0], argv, envp);
		/*on success this won't be applied*/
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	/* wait for the child process to finish */
	else
		wait(&status);
}
