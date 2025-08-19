#include "header.h"

/**
*exe_path -  execute a path commande
*@argv: the commande to execute
*@head: the list with the PATH directories
*Return: -1 if command not found
*/
int exe_path(char *argv[], list_t *head)
{
	char *full_path;
	int len;

	while (head != NULL)
	{
		len = strlen(head->str) + strlen(argv[0]) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
			return (-1);

		strcpy(fullpath, head->str);
		if (head->str[strlen(head->str) - 1] != '/')
			strcat(full_path, "/");
		strcat(full_path, argv[0]);

		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, argv, environ);
			perror("exepath");
			free(full_path);
			exit(126);
		}
		free(full_path);
		head = head->next;
	}
	return (-1);
}

/**
 * shell_fork - function fork shell
 * @argv: pointeur of array argumend ask by user
 *@head: a list with all path's directories
 * Return: 0
 */
int shell_fork(char *argv[], list_t *head)
{
	pid_t id;

	if (head == NULL)
		return (1);
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
			_print_env();
			exit(1);
		}
		else if (head != NULL && *argv[0] != '/')
		{
			exe_path(argv, head);
			fprintf(stderr, "%s: command not found\n", argv[0]);
			exit(127);
		}
		else
		{
			execve(argv[0], argv, environ);
			perror("execve");
			exit(126);
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
