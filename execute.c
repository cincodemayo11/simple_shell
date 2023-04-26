#include "shell.h"

/**
 * execute - executes command with execve
 *
 * @command: the inputted command
 * @args: the command's arguments
 *
 * Return: void
 */
void execute(char *command, char **args)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execve(command, args, NULL) == -1)
        {
            perror("./shell");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
}
