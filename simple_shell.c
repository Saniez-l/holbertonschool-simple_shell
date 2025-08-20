#include "header.h"

/**
 * main - Entry point
 *
 * @argc: argc (void)
 * @argv: pointeur of array argumend ask by user
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	list_t *head;

	int isatty(int fd);


	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		head = list_env();
		if (shell(argv, head) == 1)
		{
			free_list(head);
			break;
		}
		free_list(head);
	}
	return (0);
}
