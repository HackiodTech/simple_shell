#include "simple_shell.h"

/**
 * _strlen - returns length of string
 * @s: variable holding string
 * Return: length of string
 */
int _strlen(char *s)
{
int cnt;

for (cnt = 0; *(s + cnt) != '\0'; cnt++)
{

}
return (cnt);
}
/**
 * _strcpy - copies string to buffer
 * @dest: to be copied to
 * @src: to be copied
 * Return: Always pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; *(src + i) != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
/**
 * _strcat - appends string to another string (concatenates)
 * @dest: string to be extended in length
 * @src: string
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: string
 * @s2: string
 * Return: work exactly like strcmp
 */

int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && j == 0)
	{
		j = s1[i] - s2[i];
		i++;
	}
	return (j);
}
/**
 * _strdup - pointer to newly allocated space in memeory
 * @str: string to be duplicatd in new memory
 * Return: NULL if insufficient memory or pointer
 */
char *_strdup(char *str)
{
	unsigned int i, j;
	char *ar;

	if (str == NULL)
	{
		return (0);
	}
	for (j = 0; str[j] != '\0'; j++)
	{
	}
	ar = malloc(sizeof(char) * (j + 1));
	if (ar == NULL)
	{
		return (0);
	}
	for (i = 0; i < j; i++)
	{
		ar[i] = str[i];
	}
	ar[i] = '\0';
	free(ar);
	return (ar);
}