#include "header.h"

/**
 * shell_fork - function fork shell
 * @argv: pointeur of array argumend ask by user
 * Return: 0
 */
int shell_fork(char *argv[])
{
	pid_t id;
	char *cmd = argv[1];
	size_t len = strlen(cmd);

	id = fork();
	if (id == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (strcmp(argv[0], "env") == 0)
		{
			_print_env(0);
			exit(1);
		}
		else
		{
			execve(argv[0], argv, environ);
			if (cmd[0] == '"' && cmd[len - 1] == '"')
			{
				cmd[len - 1] = '\0';
				fprintf(stderr, "%s: 1: %s: not found\n", argv[3], cmd + 1);
			}
			else
				fprintf(stderr, "%s: 1: %s: not found\n", argv[3], argv[1]);
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
