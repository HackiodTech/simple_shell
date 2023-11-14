#include "simple_shell.h"

/**
 * getfullpath - is a which linux command implementation
 * gets the absolute path for a shortened command
 * @segments: an array of pointers to command and args
 * Return: pointer to fullpath if exists or NULL
 */

char *getfullpath(char **segments)
{
	char *path = NULL;
	char *token = NULL;
	char *fullpath = NULL;
	int cmd_len;
	struct stat statbuf;

	if (stat(segments[0], &statbuf) == 0)
	{
		return (_strdup(segments[0]));
	}
	path = _strdup(_getenv("PATH"));
	cmd_len = _strlen(segments[0]);
	token = strtok(path, ":");
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * ((_strlen(token)) + cmd_len + 2));
		if (fullpath == 0)
		{
			return (0);
		}
		_strcpy(fullpath, token);
		_strcat(fullpath, "/");
		_strcat(fullpath, segments[0]);
		if (stat(fullpath, &statbuf) == 0)
		{
			free(path);
			return (fullpath);
		}
		token = strtok(NULL, ":");
		free(fullpath);
	}
	free(path);
	return (NULL);
}
/**
 * _getenv - impliments the getenv function
 * @str: variable to find (PATH)
 *
 * Return: pointer to contents of variable
 */

char *_getenv(char *str)
{
	char **temp;
	char *s;

	temp = environ;
	while (*temp)
	{
		s = _strstr(*temp, str);
		if (s != NULL && **temp == str[0])
			break;
		temp = temp + 1;
	}
	return (&s[5]);
}
/**
 * _strstr - locates a substring
 * @haystack: string to be searched
 * @needle: string to search
 * Return: to beginning of substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int len1 = 0, len2 = 0, i, j;

	while (haystack[len1] != '\0')
	{
		len1++;
	}
	for (; needle[len2] != '\0'; len2++)
	{
	}
	for (i = 0; i < len1; i++)
	{
	for (j = 0; j < len2; j++)
	{
		if (haystack[i + j] != needle[j])
		{
			break;
		}
	}
	if (j == len2)
	{
		return (haystack + i);
	}
	}
	return (NULL);
}