#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
extern char **environ;
struct builtin {
	char *name;
	int (*func)(char **args);
};
void execute_builtins(char **args);
extern struct builtin builtins[];
char *getpath(char *command);
char **tokenize(char *line);
int main(int __attribute__((unused)) ac, char **av __attribute__((unused)));
char *read_input();
void execmd(char **argv);
int help(char **args);
int changedir(char **args);
int shell_exit(char **args);
int num_builtins();
void executeChildProcess(char **argv);
void handleParentProcess(pid_t child);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void non_interactive(void);
void interactive(void);
#endif
