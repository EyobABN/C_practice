#include "main.h"

/**
 * count_words - counts the number of words in a string
 * @str: the string
 *
 * Return: the wordcount
 */
int count_words(char *str)
{
	int i = 0, word_count = 0;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			continue;
		}
		while (str[i] != ' ' && str[i])
			i++;
		word_count++;
	}
	return (word_count);
}

/**
 * free_array - frees an array of strings
 * @arr: the array
 * @j: free all elements upto and includeing j
 *
 * Return: a void pointer
 */
void *free_array(char **arr, int j)
{
	int i;

	for (i = 0; i < j; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

/**
 * makeCmd - splits a string into words
 * @str: the string
 *
 * Return: an array of the words
 */

char **makeCmd(char *str)
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
}
