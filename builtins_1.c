#include "main.h"
/**
 * print_env- env
 * @args: unused
 * Return: return
 */
int print_env(__attribute__((unused)) char **args)
{
	int i;

	if (environ == NULL)
	{
		perror("Error: environ is not accessible");
		return (-1);
	}
	for (i = 0; environ[i]; i++)
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1)
		{
			perror("write");
			return (-1);
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("write");
			return (-1);
		}
	}
	return (-1);
}
/**
 * shell_exit- exit
 * @args: args
 * Return: return
 */
int shell_exit(char **args)
{
	int exitstatus;

	if (args[1] != NULL)
	{
		exitstatus = atoi(args[1]);
		exit(exitstatus);
	}
	else
	{
		exit(0);
	}
}
/**
 * changedir- chng dir
 * @args: args
 * Return: return 0
 */
int changedir(char **args)
{
	int state = -1;
	char cwd[1024];

	if (args[1] == NULL)
		state = chdir(getenv("HOME"));
	else if (_strcmp(args[1], "-") == 0)
	{
		state = chdir(getenv("OLDPWD"));
	}
	else
	{
		state = chdir(args[1]);
	}
	if (state == -1)
	{
		perror("shell");
		return (-1);
	}
	else
	{
		getcwd(cwd, sizeof(args));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (1);
}
/**
 * builtin- elements
 * @0: help
 * @1: exig
 * @2: cd
 * @3: env
 */
struct builtin builtins[] = {
	{"exit", shell_exit},
	{"-cd", changedir},
	{"-env", print_env},
};
/**
 * num_builtins- num
 * Return: 0
 */
int num_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}
