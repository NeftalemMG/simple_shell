#include "simpleshellmain.h"

/**
 * main - Main function for the simple shell
 *
 * Description: This function serves as the main loop for the simple shell.
 * It reads input, processes commands, and executes child processes.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	struct stat filestatus;
	struct mainVariables mV;
	memset(&filestatus, 0, sizeof(filestatus));

	while (TRUE)
	{
		receptionist(STDIN_FILENO, filestatus);
		mV.line = customGETLINE(stdin);
		if (stringCompare(mV.line, "\n", 1) == 0)
		{
			free(mV.line);
			continue;
		}
		mV.tokens = stringChoppedUp(mV.line);
		if (mV.tokens[0] == NULL)
		{
			continue;
		}
		mV.soweto = doOIs(mV.tokens);
		if (mV.soweto == 0 || mV.soweto == -1)
		{
			free(mV.tokens);
			free(mV.line);
		}
		if (mV.soweto == 0)
		{
			continue;
		}
		if (mV.soweto == -1)
		{
			_exit(EXIT_SUCCESS);
		}
		mV.idibtgog = 0; 
		mV.path = envWYA("PATH");
		mV.allait = getExecutablePath(mV.tokens[0], mV.allait, mV.path);
		if (mV.allait == NULL)
		{
			mV.allait = mV.tokens[0];
		}
		else
		{
			mV.idibtgog = 1; 
		}
		mV.ready = executeChildProcess(mV.allait, mV.tokens);
		if (mV.ready == -1)
		{
			perror("Error");
		}		
		adiosMuchachos(mV.tokens, mV.path, mV.line, mV.allait, mV.idibtgog);
	}
	return (0);
}

