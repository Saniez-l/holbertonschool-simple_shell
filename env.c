#include "header.h"

/**
*_print_env - print the environement
*Return: 0
*/

int _print_env(void)
{
	char **s = environ;
	int i = 0;

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	return (0);
}
