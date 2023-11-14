#include "simple_shell.h"
#include <string.h>
#include <stddef.h>

/**
 * Builtin_ - Handles shell built in fucntions
 * @segments: an array of pointers
 *
 * Return: 0 on success
 */
int Builtin_(char **segments)
{
	sf strct[] = {
		{"exit", exitin_},
		{"env", PrintEnv},
		{NULL, NULL}};
	int q;

	q = 0;
	while (strct[q].s != NULL)
	{
		if (strcmp_(segments[0], strct[q].s) == 0)
		{
			strct[q].f(segments);
			return (0);
		}
		q++;
	}
	return (1);
}