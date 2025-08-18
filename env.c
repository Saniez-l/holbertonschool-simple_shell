#include "header.h"

/**
*_print_env - print the environement
*@i: the number of line
*Return: 0
*/

int _print_env(int i)
{
	char **s = environ;

	if (i != 0)
		return (-1);

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	return (0);
}
