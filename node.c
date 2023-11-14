#include "simple_shell.h"

/**
 * Delim_ - counts number of  ':' delimiters
 * @str: string
 *
 * Return: Number of delimiters
 */

int Delim_(char *str)
{
	int i, count;

	i = 0;
	count = 0;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == ':')
		{
			count++;
		}
	}
	return (count);
}