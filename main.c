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
	char *dup = strdup(argv[0]);;

	if (dup == NULL)
		return (0);
	(void)argc;
	while (1)
	{
		head = list_env();
		argv[0] = dup;
		if (shell(argv, head) == 1)
		{
			free_list(head);
			break;
		}
		free_list(head);
	}
	free(dup);
	return (0);
}
