#include "shell.h"

/**
 *execute_builtin - executes exit and env commands
 *
 *@command: exit or env
 *
 *Return: void
 */

void execute_builtin(char *command)
{
	char **env;

	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		printf("env not found\n");
	}
}
