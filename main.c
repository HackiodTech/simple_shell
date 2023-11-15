#include "simple_shell.h"

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *buf = NULL;
	char **segments = NULL;
	char **fullPath = NULL;
	size_t n = 0;
	int imode = isatty(STDIN_FILENO);

	while (imode)
	{
		prompt();
		if (getline(&buf, &n, stdin) == -1) {
			perror("getline");
			break;
		}
		if (buf[0] == '\n')
		{
			continue;
		}
		dfree_(segments);
		segments = tokenize(buf);
		if (Builtin_(segments) == 0)
			continue;
		dfree_(fullPath);
		if (fullPath == NULL)
		{
			perror(av[0]);
			dfree_(segments);
			continue;
		}
		env ++;
	}

	free(buf);
	dfree_(segments);
	dfree_(fullPath);

	return (0);
}