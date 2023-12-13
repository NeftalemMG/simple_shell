#include "simpleshellmain.h"


/*
 * main - The main function for the simple shell program
 * @ac: Number of command-line arguments
 * @av: Array of command-line argument strings
 * @envp: Array of environment variable strings
 * 
 * Description: The main function of the simple shell program. It initializes variables,
 * checks for the number of command-line arguments, and then enters an infinite loop to
 * read and process user input.
 * 
 * Return: Always returns 0
 */
int main(int ac, char **av, char **envp)
{
	struct shellsimplementVariables ssV;
	initializeVariables(&ssV);

	(void)av; 

	if (ac != 1)
	{
		printStringAndNewLineToFD("ERROR: Invalid number of Arguments", 2);
		printStringAndNewLineToFD("Usage: ./;)", 2);
		return (0);
	}
	while (1 && ssV.wasitPipped == 27)
	{
		readInput(&ssV);
		if (ssV.theline == NULL)
		{
			return (1);
		}
		if (ssV.theline[0] == '\0')
		{
			return (printStringAndNewLineToFD("exit", 2), 1);
		}
		ssV.package = trimString(ssV.theline, "	\n");
		if (!compareStrings(ssV.package, "exit"))
		{
			return (1);
		}
		free(ssV.theline);
		if (!compareStrings(ssV.package, "env"))
		{
			printEnvironment(envp);
		}
		else
		{
			tokenizeInput(&ssV);
			buildCommandArray(&ssV, envp);
		}
	}
	return (0);
}

