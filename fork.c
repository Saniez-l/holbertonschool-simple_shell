#include "header.h"

/**
*exe_path -  execute a path commande
*@argv: the commande to execute
*@head: the list with the PATH directories
*Return: always 0
*/
int exe_path(char *argv[], list_t *head)
{
	DIR *op = NULL;
	struct dirent *_read = NULL;
	char buffer[64];
	int i, j, len = 0, len2 = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		op = opendir(head->str);
		if (op == NULL)
		{
			head = head->next;
			continue; }
		while ((_read = readdir(op)) != NULL)
		{
			if ((strcmp(_read->d_name, argv[0]) == 0) && head->str[0] == '/')
			{
				i = 0;
				j = 0;
				len = strlen(head->str);
				len2 = strlen(_read->d_name);
				while (i < len)
				{
					buffer[i] = head->str[i];
					i++; }
				if (i > 0 && buffer[i - 1] != '/')
				{
					buffer[i] = '/';
					i++; }
				while (i < (len + len2 + 1))
				{ buffer[i] = _read->d_name[j];
					i++;
					j++; }
				buffer[i] = '\0';
				execve(buffer, argv, environ); }
		} closedir(op);
		head = head->next; }
		closedir(op);
	return (0);
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
			perror("exepath");
			exit(1);
		}
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
