#include "simple_shell.h"

/**
 * no_delim - counts number of  ':' delimiters
 * @str: string
 *
 * Return: Number of delimiters
 */

int no_delim(char *str)
{
	int i, count;

	i = 0;
	count = 0;
	for ( ; str[i] != '\0'; i++)
	{
		if (str[i] == ':')
		{
			count++;
		}
	}
	return (count);
}