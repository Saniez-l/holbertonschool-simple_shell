#include "header.h"

/**
 * shell_fork - function fork shell
 * @argv: pointeur of array argumend ask by user
 * Return: 0
 */
int shell_fork(char *argv[])
{
	pid_t id;

	id = fork();
	if (id == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (strcmp(argv[0], "env") == 0)
			_print_env(0);
		else
		{
			execve(argv[0], argv, environ);
			perror("execve");
			exit(1);
		}
	}
	else
	{
		int status;

		if ((waitpid(id, &status, 0) == -1))
			perror("waitpid");
	}
	return (0);
}
