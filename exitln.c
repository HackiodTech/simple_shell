#include "simple_shell.h"
#include <stdlib.h>

/**
 * exitin - calls the exit function
 * @segments: array of pointers
 *
 * Return: 0 on success
 */

int  exitin(char **segments)
{
	int status = 0;

	if (segments[1] != NULL)
		status = _atoi(segments[1]);
	dfree(segments);
	exit(status);
}
/**
 * _atoi - convert a string to an integer
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0, sign = -1, num = 0, skim = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		while ((s[i] >= '0' && s[i] <= '9') && s[i])
		{
			num = (num * 10) - (s[i] - '0');
			skim = 1;
			i++;
		}
		if (skim)
		{
			num *= sign;
			break;
		}
	}
	return (num);
}