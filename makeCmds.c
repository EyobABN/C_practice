#include "main.h"
#include <stdio.h>

/**
 * isOperator - checks if a command is either AND or OR
 * @s: the start of the check
 * @op: the operator
 *
 * Return: 1 if a match, 0 if not
 */
int isOperator(char *s, char *op)
{
	while (*op)
	{
		if (*s++ != *op++)
		       return (0);	
	}
	if (*s)
		return (1);
	return (0);
}
/**
 * count_commands - counts the number of commands in a string
 * @str: the string
 *
 * Return: the wordcount
 */
int count_commands(char *str)
{
	int i = 0, and, or, sc, hash, command_count = 1;

	while (str[i])
	{
		and = isOperator(&(str[i]), "&&");
		or = isOperator(&(str[i]), "||");
		sc = isOperator(&(str[i]), ";");
		hash = isOperator(&(str[i]), " #");
		if (and || or || sc || hash)
		{
			command_count += 2;
			if (and || or || hash)
				i++;
			i++;
		}
		else
			i++;
	}
	return (command_count);
}


/**
 * free_array - frees an array of strings
 * @arr: the array
 * @j: free all elements upto and includeing j
 *
 * Return: a void pointer
 */
/*void *free_array(char **arr, int j)
{
	int i;

	for (i = 0; i < j; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}*/

/**
 * makeCmd - splits a string into words
 * @str: the string
 *
 * Return: an array of the words
 */

/*char **makeCmd(char *str)
{
	char **cmd;
	int i, j, k = 0, l, m, word_count, letter_count;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str);
	cmd = malloc(sizeof(char *) * (word_count + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			continue;
		}
		j = i;
		letter_count = 0;
		while (str[i] != ' ' && str[i])
		{
			i++;
			letter_count++;
		}
		cmd[k] = malloc(sizeof(char) * (letter_count + 1));
		if (cmd[k] == NULL)
			return (free_array(cmd, k - 1));
		for (m = 0, l = j; l < i; l++, m++)
			cmd[k][m] = str[l];
		cmd[k][m] = '\0';
		k++;
	}
	cmd[k] = NULL;
	return (cmd);
}*/

int main(void)
{
	int count;
	char *cmd = "";

	count = count_commands(cmd);
	printf("Command:		[[%s]]\n", cmd);
	printf("Number of commands:	%d\n", count);
	return (0);
}
