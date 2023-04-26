#include "shell.h"

/**
 *execute - executes command with execve
 *
 *@command: the inputted command
 *@args: the comand's arguments
 *
 *Return: void
 */

void execute(char *command, char **args)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (strcmp(command, "/usr/bin/env") == 0)
	{
		command = "env";
	}
}
