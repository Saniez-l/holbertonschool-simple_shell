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

	(void)argc;
	while (1)
	{
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
