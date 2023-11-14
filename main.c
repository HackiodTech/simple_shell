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
		dfree_(segments);
		segments = tokenize(buf);
		if (Builtin_(segments) == 0)
			continue;
		dfree_(fullpath);
		fullpath = fullpath(segments);
		if (fullpath == NULL)
		{
			perror(av[0]);
			dfree_(segments);
			continue;
		}
		RunCmd(fullpath, segments, env);
		if (flag)
			sfree_(fullpath);
	}

	free(buf);
	dfree_(segments);
	dfree_(fullpath);

	return (0);
}