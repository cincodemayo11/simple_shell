#include "shell.h"

/**
 * prompt - prints the prompt, receives and parses input.
 *
 * return: void
 */
void prompt(void)
{
    char *command = NULL;
    ssize_t nread;
    size_t len = 0;
    int interactive = isatty(fileno(stdin));
    char *args[64];

    while (1)
    {
	    if (interactive)
	    {
		    printf("#cisfun$ ");
	    }
	    else
	    {
		    printf("#cisfun$ ");
		    fflush(stdout);
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

	    args[0] = command;
	    args[1] = NULL;
	    execute(command, args);
    }
}