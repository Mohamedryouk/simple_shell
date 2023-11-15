#include "main.h"
/**
 * non_interactive- non interactive mode
 */
void non_interactive(void)
{
	char **tokens, *line;

	while (1)
	{
		line = read_input();
		if (line == NULL)
		{
			break;
		}
		tokens = tokenize(line);
		if (tokens[0] != NULL)
		{
			execmd(tokens);
			execute_builtins(tokens);
		}
		free(tokens);
		free(line);
	}
	write(STDOUT_FILENO, "\n", 1);
}
/**
 * main- shell main processes
 * @ac: unused
 * @av: unused
 * Return: return status
 */
int main(int __attribute__((unused)) ac, char **av __attribute__((unused)))
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
/**
 * interactive- function in interactive mode
 */
void interactive(void)
{
	char **tokens, *line, *prompt = " ~$ ";

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		line = read_input();
		if (line == NULL)
		{
			break;
		}
		tokens = tokenize(line);
		if (tokens[0] != NULL)
		{
			execmd(tokens);
			execute_builtins(tokens);
		}
		free(tokens);
		free(line);
	}
	write(STDOUT_FILENO, "\n", 1);
}
