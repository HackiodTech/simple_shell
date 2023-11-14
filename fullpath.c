#include "simple_shell.h"

/**
 * fullpath - is a which linux command implementation
 * gets the absolute path for a shortened command
 * @segments: an array of pointers to command and args
 * Return: pointer to fullpath if exists or NULL
 */

char *fullpath(char **segments)
{
	char *path = NULL;
	char *token = NULL;
	char *fullpath = NULL;
	int cmd_len;
	struct stat statbuf;

	if (stat(segments[0], &statbuf) == 0)
	{
		return (strdup_(segments[0]));
	}
	path = strdup_(GetEnv("PATH"));
	cmd_len = strlen_(segments[0]);
	token = strtok(path, ":");
	while (token != NULL)
	{
		fullpath = malloc(sizeof(char) * ((strlen_(token)) + cmd_len + 2));
		if (fullpath == 0)
		{
			return (0);
		}
		strcpy_(fullpath, token);
		StrCat_(fullpath, "/");
		StrCat_(fullpath, segments[0]);
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
 * GetEnv - impliments the getenv function
 * @str: variable to find (PATH)
 *
 * Return: pointer to contents of variable
 */

char *GetEnv(char *str)
{
	char **temp;
	char *s;

	temp = environ;
	while (*temp)
	{
		s = _str_(*temp, str);
		if (s != NULL && **temp == str[0])
			break;
		temp = temp + 1;
	}
	return (&s[5]);
}
/**
 * _str_ - locates a substring
 * @haystack: string to be searched
 * @needle: string to search
 * Return: to beginning of substring or NULL
 */
char *_str_(char *haystack, char *needle)
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