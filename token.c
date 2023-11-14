#include "simple_shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * tokenize - tokenizes the string in the buffer
 * @buf: buffer containing text from stdin
 * Return: Pointer to tokenized strings
 */

char **tokenize(char *buf)
{
	int seg_count = 0;
	char *b = _strdup(buf);
	char *token = NULL;
	char **segments = NULL;
	char dl[] = " \n\t\r";

	segments = malloc(sizeof(char *) * BUFFER);
	if (segments == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(b, dl);
	while (token != NULL)
	{
		segments[seg_count] = _strdup(token);
		seg_count++;
		token = strtok(NULL, dl);
	}
	segments[seg_count] = NULL;
	free(segments);
	return (segments);
}