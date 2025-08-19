#include "header.h"

/**
*_getenv - get the environment we want
*@name: the name of the environment
*Return: the environment or NULL
*/
char *_getenv(const char *name)
{
	int i = 0, len = strlen(name);

	if (name == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0
			&& environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

/**
*add_node - adds a new node at the beginning of a linked list
*@head: the list
*@str: the new node
*Return: NULL or the adress of the new element
*/


list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (str == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

/**
*free_list - free a linked list
*@head: the list
*/
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free((char *)tmp->str);
		free(tmp);
	}
}

/**
*list_env - make all the directories of the environment in a list
*Return: Nothing
*/
list_t *list_env(void)
{
	char *path = _getenv("PATH");
	char *path_dup, *next;
	list_t *head = NULL;

	if (path == NULL)
		return (NULL);

	path_dup = strdup(path);
	if (path_dup == NULL)
		return (NULL);

	next = strtok(path_dup, ":");
	while (next != NULL)
	{
		add_node(&head, next);
		next = strtok(NULL, ":");
	}
	free(path_dup);
	return (head);
}










