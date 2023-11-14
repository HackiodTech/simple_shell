#include "simple_shell.h"
#include <stdlib.h>

/**
 * dfree - Frees array of pointers
 * @arr: array of pointers
 *
 * Return: nothing
 *
 */

void dfree(char **arr)
{
	int i = 0;

	if (!arr || !(*arr))
		return;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
