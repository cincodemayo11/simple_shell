#include "shell.h"

/**
 *split - splits the commands and its arguments
 *
 *@command: the inputted command
 *
 *Return: void
 */

void split(char *command)
{
	char *token;
	char **args;
	int i = 0;
	char *fullpath;

	args = malloc(64 * sizeof(char *));

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	fullpath = path(args[0]);

	if (fullpath == NULL)
	{
		perror("./shell");

		free(fullpath);
		free(args);
	}
	else
	{
		execute(fullpath, args);
		free(args);
		free(fullpath);
	}
	free(args);
}
