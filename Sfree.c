#include "simple_shell.h"
#include <stdlib.h>

/**
 * sfree - Frees array
 * @arr: array of pointers
 *
 * Return: nothing
 *
 */

void sfree(char *arr)
{
	if (!arr)
		return;
	free(arr);
}