#include "main.h"
/**
 * execmd- execute command
 * @argv: args
 */
void execmd(char **argv)
{
	pid_t child = fork();

	if (child == 0)
	{
		executeChildProcess(argv);
	}
	else if (child > 0)
	{
		handleParentProcess(child);
	}
}
/**
 * executeChildProcess- execute
 * @argv: args
 */
void executeChildProcess(char **argv)
{
	if (argv[0][0] == '/')
	{
		execve(argv[0], argv, environ);
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	else
	{
		char *token = getpath(argv[0]);

		if (token != NULL)
		{
			execve(token, argv, environ);
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	exit(0);
}
/**
 * handleParentProcess- child process handle
 * @child: child
 */
void handleParentProcess(pid_t child)
{
	int status, exitstatus, signal;
	pid_t wapid = waitpid(child, &status, 0);

	if (wapid == -1)
	{
		return;
	}
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		return;
	}
	else if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		return;
	}
	else
	{
		return;
	}
}
