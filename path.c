#include "shell.h"

/**
 *path - handles PATH
 *
 *@command: the inputted command
 *
 *Return: void
 */

char *path(char *command)
{
	char *path;
	char *fullpath;
	char *path_token;

	path = strdup(getenv("PATH"));
	fullpath = malloc(strlen(path) + strlen(command) + 2);

	if (command[0] == '/')
	{
		strcpy(fullpath, command);
		if (access(fullpath, X_OK) == 0)
		{
			return (strdup(fullpath));
		}
		else
		{
			free(fullpath);
			return (NULL);
		}
	}


	path_token = strtok(path, ":");

	while (path_token != NULL)
	{
		sprintf(fullpath, "%s/%s", path_token, command);
		if (access(fullpath, X_OK) == 0)
		{
			free(path);
			return (strdup(fullpath));
		}
		path_token = strtok(NULL, ":");
	}

	free(path);
	free(fullpath);
	return (NULL);
}
