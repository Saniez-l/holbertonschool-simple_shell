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
	(void)argc;

	while (1)
	{
		if (shell(argv) == 1)
			break;
	}
	return (0);
}
