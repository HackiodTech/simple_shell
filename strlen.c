#include "simple_shell.h"

/**
 * strlen_ - returns length of string
 * @s: variable holding string
 * Return: length of string
 */
int strlen_(char *s)
{
	int cnt;

	for (cnt = 0; *(s + cnt) != '\0'; cnt++)
	{
	}
	return (cnt);
}
/**
 * strcpy_ - copies string to buffer
 * @dest: to be copied to
 * @src: to be copied
 * Return: Always pointer to dest
 */

char *strcpy_(char *dest, char *src)
{
	int q;

	for (q = 0; *(src + q) != '\0'; q++)
	{
		dest[q] = src[q];
	}
	dest[q] = '\0';
	return (dest);
}
/**
 * StrCat_ - appends string to another string (concatenates)
 * @dest: string to be extended in length
 * @src: string
 * Return: pointer to the resulting string dest
 */

char *StrCat_(char *dest, char *src)
{
	int q, j;

	q = 0;
	while (dest[q] != '\0')
	{
		q++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[q] = src[j];
		q++;
		j++;
	}
	dest[q] = '\0';
	return (dest);
}
/**
 * strcmp_ - compares two strings
 * @s1: string
 * @s2: string
 * Return: work exactly like strcmp
 */

int strcmp_(char *s1, char *s2)
{
	int q, j;

	q = 0;
	j = 0;
	while (s1[q] != '\0' && j == 0)
	{
		j = s1[q] - s2[q];
		q++;
	}
	return (j);
}
/**
 * strdup_ - pointer to newly allocated space in memeory
 * @str: string to be duplicatd in new memory
 * Return: NULL if insufficient memory or pointer
 */
char *strdup_(char *str)
{
	unsigned int q, j;
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
	for (q = 0; q < j; q++)
	{
		ar[q] = str[q];
	}
	ar[q] = '\0';
	free(ar);
	return (ar);
}