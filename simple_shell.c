#include "header.h"
/**
 * shell - program for print $ and enter command user
 * @argv: pointeur of array argumend ask by user
 * Return: 0
 */
int shell(char *argv[])

{
	char *buff = NULL, *next;
	size_t i = 0, n = 0;

	printf("$ ");
	if (getline(&buff, &n, stdin) == -1)
	{
		free(buff);
		return (1);
	}
	next = strtok(buff, " \t\n");
	while (next != NULL)
	{
		argv[i] = next;
		i++;
		next = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	if (strcmp(argv[0], "exit") == 0)
	{
		free(buff);
		return (1);
	}
	shell_fork(argv);
	free(buff);
	return (0);
}
