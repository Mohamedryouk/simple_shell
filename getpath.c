#include "main.h"
char *getpath(char *command)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("Failed to get PATH");
		exit(1);
	}
	char *token = strtok(path, ":");

	while (token != NULL)
	{

		char *full_path = (char *)malloc(strlen(token) + 1 + _strlen(command) + 1);

		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
