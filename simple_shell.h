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
int strlen_(char *s);
char **tokenize(char *buf);
void dfree_(char **arr);
void sfree_(char *arr);
int RunCmd(char *cmd, char **tokens, char **envt);
char *fullpath(char **segments);
int Delim_(char *str);
int Builtin_(char **segments);
int  exitin_(char **segments);
int PrintEnv(char **segments);
char *GetEnv(char *str);
char *strcpy_(char *dest, char *src);
char *StrCat_(char *dest, char *src);
int strcmp_(char *s1, char *s2);
char *strdup_(char *str);
char *_str_(char *haystack, char *needle);
void signal_handler(int signal);
int Atoi_(char *s);

#endif