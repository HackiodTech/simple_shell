#include "simple_shell.h"
#include <stdio.h>

/**
 * prompt - prints a string to indicate request for input
 *
 * Return: size of prompt string
 */

int prompt(void)
{
	char p[] = "> ";
	int i, j;

	i = 0;
	j = 0;
	while (p[i])
	{
		j += _putchar(p[i]);
		i++;
	}
	return (j);
}
