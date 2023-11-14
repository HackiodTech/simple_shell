#include "simple_shell.h"

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *buf = NULL;
	char **segments = NULL;
	char *fullpath = NULL;
	size_t n = 0;
	int imode = isatty(STDIN_FILENO);
	int flag = 1;

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
		dfree(segments);
		segments = tokenize(buf);
		if (builtin(segments) == 0)
			continue;
		dfree(fullpath);
		fullpath = getfullpath(segments);
		if (fullpath == NULL)
		{
			perror(av[0]);
			dfree(segments);
			continue;
		}
		runlcmd(fullpath, segments, env);
		if (flag)
			sfree(fullpath);
	}

	free(buf);
	dfree(segments);
	dfree(fullpath);

	return (0);
}