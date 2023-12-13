#include "simpleshellmain.h"

/*
  * initializeVariables - Initialize shell implementation variables
  * @ssV: Pointer to the struct shellsimplementVariables to be initialized
  * 
  * Description: This function initializes the members of the struct 
  * shellsimplementVariables to their default values. It is
  * typically called at the beginning of the program.
  * 
  * Return: None
  */
void initializeVariables(struct shellsimplementVariables *ssV)
{
	ssV->i = 0;
	ssV->reading = -1;
	ssV->package = NULL;
	ssV->wasitPipped = 27;
}

/*
 * readInput - Reads input from the user or a piped source
 * @ssV: Pointer to the struct containing shell implementation variables
 * 
 * Description: This function reads input from the user or a piped source,
 * checking if the input is coming from a terminal or a pipe. It prints a prompt
 * and reads a line of input using the getline function.
 * 
 * Return: None
 */
void readInput(struct shellsimplementVariables *ssV)
{
    ssV->theline = NULL;
    ssV->holderSize = 0;

    if (isatty(STDIN_FILENO) == 0) {
        ssV->wasitPipped = 28;
    }

    printStringToFD(";) ", 2);
    ssV->reading = getline(&ssV->theline, &ssV->holderSize, stdin);
}

/*
  * tokenizeInput - Tokenizes the input string
  * @ssV: Pointer to struct shellsimplementVariables containing variables
  * 
  * Description: This function tokenizes the input string contained in ssV->package,
  * counting the number of tokens and storing them in ssV->nateyarguments.
  * 
  * Return: No explicit return value. Updates ssV->nateyarguments and ssV->i.
  */
void tokenizeInput(struct shellsimplementVariables *ssV)
{
	ssV->package2 = duplicateString(ssV->package);
	ssV->tokenizedVar = strtok(ssV->package2, " \t\r");
	while (ssV->tokenizedVar != NULL)
	{
		ssV->i++;
		ssV->tokenizedVar = strtok(NULL, " \t\r");
	}
	free(ssV->package2);

	ssV->package2 = duplicateString(ssV->package);
	ssV->tokenizedVar = strtok(ssV->package2, " \t\r");
	ssV->nateyarguments = malloc(sizeof(char *) * (ssV->i + 1));
	ssV->ic = 0;

	while (ssV->tokenizedVar != NULL)
	{
		ssV->nateyarguments[ssV->ic] = duplicateString(ssV->tokenizedVar);
		ssV->ic++;
		ssV->tokenizedVar = strtok(NULL, " \t\r");
	}
	ssV->nateyarguments[ssV->i] = NULL;
	free(ssV->package2);
}

/*
 * executeCommand - Execute a shell command
 * @ssV: Pointer to the shellsimplementVariables struct
 * @envp: Pointer to the environment variables
 * 
 * Description: This function creates a child process using fork() and executes
 * the specified command using execve(). It also waits for the child process
 * to complete using waitpid().
 * 
 * Return: No return value.
 */
void executeCommand(struct shellsimplementVariables *ssV, char **envp)
{
	ssV->id = fork();
	if (ssV->id == 0)
	{
		if (execve(ssV->letsgoo[0], ssV->letsgoo, envp) == -1)
		{
			printErrorMsg(ssV->nateyarguments[0]);
			freeDoublePointerArray(ssV->nateyarguments);
			free(ssV->package);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do
		{
			waitpid(ssV->id, &ssV->status, WUNTRACED);
		} while (!WIFEXITED(ssV->status) && !WIFSIGNALED(ssV->status));
	}
	freeDoublePointerArray(ssV->nateyarguments);
	free(ssV->package);
}

