#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/**
 * struct path_s - a struct of a directory in path
 * @dir: the directory
 * @next: the next node in the list
 *
 * Description: this struct shall constitute
 * a node in the linked list of directories in
 * the PATH environment variable
 */
typedef struct path_s
{
	char *dir;
	struct path_s *next;
} path_t;

int _putchar(char c);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
void _puts(char *str);
int _strlen(const char *s);
path_t *add_node_end(path_t **head, char *str);
void free_list(path_t *head);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char **makeCmd(char *str);

#endif /* MAIN_H */
