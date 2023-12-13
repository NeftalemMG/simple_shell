#include "simpleshellmain.h"

/**
 * executeChildProcess - Execute a executeChildProcess process.
 * @executablePath: The full path of the executable.
 * @commandTokens: An array of tokens representing the command and its arguments.
 *
 * Description: This function forks a executeChildProcess process and executes the specified
 * command with the given arguments using the execve system call. It waits for
 * the executeChildProcess process to complete and returns the status.
 *
 * Return: 0 on success, -1 on failure.
 */
int executeChildProcess(char *executablePath, char **commandTokens)
{
	struct executeChildProcessVariables eCPV;
	eCPV.envp = environ;

	eCPV.daBabyPid = fork();
	if (eCPV.daBabyPid == -1)
	{
		write(STDERR_FILENO, "Forking Failed\n", stringLength("Forking Failed\n"));
		perror("Error");

		exit(EXIT_FAILURE);
	}
	if (eCPV.daBabyPid == 0)
	{   
		eCPV.whatisgoingonwithexecve = execve(executablePath, commandTokens, eCPV.envp);
		if (eCPV.whatisgoingonwithexecve == -1)
		{
			return (-1);
		}
			
	}
	else
		wait(&eCPV.status);

	return (0);
}

/**
 * getExecutablePath - Get the absolute path of an executable file in the search path
 * @targetCommand: The target executable command
 * @result: The buffer to store the result (should be pre-allocated by the caller)
 * @searchPath: The colon-separated search path
 *
 * Description: This function searches for the executable file specified by targetCommand
 * in the given searchPath. It returns the absolute path of the first occurrence found.
 *
 * Return: If found, returns the absolute path; otherwise, returns NULL.
 */
char *getExecutablePath(char *targetCommand, char *result, char *searchPath)
{
	struct getExecutablePathVariables gEPV;

	gEPV.operationSize = stringLength(targetCommand);
	gEPV.originalRouteSize = stringLength(searchPath);
	gEPV.routeCopy = malloc(sizeof(char) * gEPV.originalRouteSize + 1);
	if (gEPV.routeCopy == NULL)
	{
		write(STDERR_FILENO, "Malloc Failed", stringLength("Malloc Failed"));
		return (NULL);
	}
	copyString(gEPV.routeCopy, searchPath);
	gEPV.extractedToken = strtok(gEPV.routeCopy, ":");
	if (gEPV.extractedToken == NULL)
	{
		gEPV.extractedToken = strtok(NULL, ":");
	}
	while (gEPV.extractedToken != NULL)
	{
		gEPV.routeSize = stringLength(gEPV.extractedToken);
		result = malloc(sizeof(char) * (gEPV.routeSize + gEPV.operationSize) + 2);
		if (result == NULL)
		{
			write(STDERR_FILENO, "Malloc Failed", stringLength("Malloc Failed"));
			return (NULL);
		}
		copyString(result, gEPV.extractedToken);
		result[gEPV.routeSize] = '/';
		copyString(result + gEPV.routeSize + 1, targetCommand);
		result[gEPV.routeSize + gEPV.operationSize + 1] = '\0';
		if (access(result, X_OK) != 0)
		{
			free(result);
			result = NULL;
			gEPV.extractedToken = strtok(NULL, ":");
		}
		else
		{
			break;
		}
	}
	free(gEPV.routeCopy);
	return (result);
}

/**
  * customGetLine - Read a line from a file
  * @file: The file from which to read the line
  *
  * Description: This function reads a line from the specified file.
  * It allocates memory for the line and returns it.
  * If an error occurs or the end of the file is reached,
  * the program exits with success.
  *
  * Return: A pointer to the read line.
  */
char *customGETLINE(FILE *fil)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fil);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

/**
  * doOIs - Check and execute a built-in command.
  * @tokens: An array of strings representing the command and its arguments.
  *
  * Description: This function checks if the provided command is a built-in
  * command and executes the corresponding action. If the command is not a
  * built-in command, it returns 1.
  *
  * Return: 0 if the built-in command is executed successfully, 1 otherwise.
  */
int doOIs(char **tokens)
{
	struct doOIsVariables dOV;

	ois oii[] = {
		{"exit", weOut_Deuces},
		{"env", printEnvironments},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
	{
		return (1);
	}

	dOV.t = stringLength(tokens[0]);

	dOV.s = numberofOIs(oii);
	for (dOV.i = 0; dOV.i < dOV.s; dOV.i++)
	{
		if (stringCompare(tokens[0], oii[dOV.i].name, dOV.t) == 0)
		{
			dOV.status = (oii[dOV.i].p)();
			return (dOV.status);
		}
	}
	return (1);
}

/**
 * numberofOIs - Get the number of built-in commands.
 * @oi: An array of built-in commands.
 *
 * Description: This function counts the number of built-in commands
 * in the specified array.
 *
 * Return: The number of built-in commands.
 */
int numberofOIs(ois oi[])
{
    unsigned int count; 
	
	count= 0;

    while (oi[count].name != NULL)
	{
		count++;
	}
    return (count);
}

