#include "shell.h"

/**
 *prompt - prints the prompts, receives and parses input.
 *
 *return: void
 */

void prompt(void)
{
	char *command = NULL;
	ssize_t nread;
	size_t len = 0;
	int eractive = isatty(fileno(stdin));

	while (1)
	{
		if (eractive)
		{
			printf("#cisfun$ ");
		}

		nread = getline(&command, &len, stdin);
		if (nread == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if (nread == 1)
		{
			continue;
		}
		if (command[nread - 1] == '\n')
		{
			command[nread - 1] = '\0';
		}
		if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
		{
			execute_builtin(command);
			free(command);
		}
		split(command);

	}
	free(command);
}
