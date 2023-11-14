#include "simple_shell.h"

/**
 * _printenv - implement the env built-in
 * that prints the current environment
 * @segments: command and its args
 *
 * Return: 0 on success
 */

int _printenv(char **segments)
{
	int i;
	char *str;
	char **temp = environ;

	while (*environ)
	{
		str = *environ;
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
		environ = environ + 1;
	}
	environ = temp;
	dfree(segments);
	return (0);
}