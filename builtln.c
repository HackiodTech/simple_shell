#include "simple_shell.h"
#include <string.h>
#include <stddef.h>

/**
 * builtin - Handles shell built in fucntions
 * @segments: an array of pointers
 *
 * Return: 0 on success
 */
int builtin(char **segments)
{
	sf strct[] = {
		{"exit", exitin},
		{"env", _printenv},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (strct[i].s != NULL)
	{
		if (_strcmp(segments[0], strct[i].s) == 0)
		{
			strct[i].f(segments);
			return (0);
		}
		i++;
	}
	return (1);
}