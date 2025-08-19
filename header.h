#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stddef.h>
#include <fcntl.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str);
char *_getenv(const char *name);
list_t *list_env(void);
extern char **environ;
int shell(char *argv[], list_t *head);
int shell_fork(char *argv[], list_t *head);
int _print_env(void);
void free_list(list_t *head);

#endif
