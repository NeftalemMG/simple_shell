#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TRUE 1

extern char **environ;

struct executeChildProcessVariables
{
	int status; 
	int whatisgoingonwithexecve;
	pid_t daBabyPid;
	char **envp;
};

struct getExecutablePathVariables
{
	char *routeCopy; 
	char *extractedToken;
	unsigned int operationSize;
	unsigned int routeSize; 
	unsigned int originalRouteSize;
};

struct doOIsVariables
{
	int status;
	unsigned int t;
	unsigned int s;
	unsigned int i;
};

struct envWYAvariables
{
	char **cpyenv;
	char *chupapi;
	char *bargain, *route;
	int weigh;
	unsigned int routeSize, envSize, sz, i;

};

struct mainVariables
{
	char *line;
	char *path; 
	char *allait;
	char **tokens;
	int idibtgog, soweto, ready;

};

typedef struct ois
{
	char *name;
	int (*p)(void);
} ois;

int stringCompare(char *userInput, char *compareString, unsigned int inputLength);
int stringCompareN(char *str1, char *str2, unsigned int length);
int stringLength(char *str);
char *copyString(char *destination, char *source);
int weOut_Deuces(void);
int printEnvironments(void);
int executeChildProcess(char *executablePath, char **commandTokens);
char *getExecutablePath(char *targetCommand, char *result, char *searchPath);
int numberofOIs(ois oi[]);
int doOIs(char **tokens);
void customPuts(char *stringer);
char *customGETLINE(FILE *fil);
char *envWYA(const char *what);
void receptionist(int fileDescriptor, struct stat filestatus);
char **envDup(char **cpyenv, unsigned int envSize);
char **stringChoppedUp(char *inputString);
void adiosMuchachos(char **tokens, char *path, char *line, char *allait, int flag);
void byeDoublePointers(char **arr, unsigned int len);

#endif /*SHELL_H */

