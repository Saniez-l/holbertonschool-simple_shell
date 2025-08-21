#include "header.h"
/**
 * shell - program for enter command user
 * @argv: pointeur of array argumend ask by user
 *@head: a list with all path's directories
 * Return: 0
 */
int shell(char *argv[], list_t *head)

{
	char *buff = NULL, *next;
	size_t n = 0;
	char *buffer[128];
	int i = 0;

	(void)argv;
	if (head == NULL)
		return (0);
	if (getline(&buff, &n, stdin) == -1)
	{
		free(buff);
		return (1);
	}
	next = strtok(buff, " \t\n");
	while (next != NULL && i < 127)
	{
		buffer[i] = next;
		i++;
		next = strtok(NULL, " \t\n");
	}
	buffer[i] = NULL;
	if (buffer[0] == NULL)
	{
		free(buff);
		return (0);
	}
	if (strcmp(buffer[0], "exit") == 0)
	{
		free(buff);
		exit(EXIT_SUCCESS);
	}
	shell_fork(buffer, head, argv);
	free(buff);
	return (0);
}
