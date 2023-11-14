#include "simple_shell.h"
#include <stdlib.h>

/**
 * sfree_ - Frees array
 * @arr: array of pointers
 *
 * Return: nothing
 *
 */

void sfree_(char *arr)
{
	if (!arr)
		return;
	free(arr);
}