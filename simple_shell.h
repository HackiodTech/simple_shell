#ifndef _SIMPLE_SHELL
#define _SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stddef.h>
#include <signal.h>


#define BUFFER 10
extern char **environ;

/**
 * struct shell_func - Handles the shell functions in our simple shell
 * @s: function
 * @f: function pointer
 *
 */
typedef struct shell_func
{
	char *s;
	int (*f)(char **seg);
} sf;
int _putchar(char c);
int main(int ac __attribute__((unused)), char **av, char **env);
int prompt(void);
int _strlen(char *s);
char **tokenize(char *buf);
void dfree(char **arr);
void sfree(char *arr);
int runlcmd(char *cmd, char **tokens, char **envt);
char *getfullpath(char **segments);
int no_delim(char *str);
int Builtin_(char **segments);
int  exitin(char **segments);
int _printenv(char **segments);
char *_getenv(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strstr(char *haystack, char *needle);
void signal_handler(int signal);
int _atoi(char *s);

#endif