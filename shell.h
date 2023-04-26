#ifndef _SHELL_
#define _SHELL_

#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void parse(void);
extern char **environ;
void execute_builtin(char *command);
char *path(char *command);
void execute(char *command, char **args);
void prompt(void);
void split(char *command);
void parse(void);

#endif
