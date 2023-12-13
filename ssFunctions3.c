#include "simpleshellmain.h"

/**
 * printEnvironments - Print the environment variables to standard output
 *
 * Description: This function iterates through the environment variables
 * and prints each one to the standard output followed by a newline.
 *
 * Return: Always returns 0.
 */
int printEnvironments(void)
{
    unsigned int index;

    index = 0;
    while (environ[index] != NULL)
    {
        write(STDOUT_FILENO, environ[index], stringLength(environ[index]));
        write(STDOUT_FILENO, "\n", 1);
        index++;
    }

    return (0);
}

/**
 * customPuts - Writes a string to standard output
 * @stringer: The string to be written
 *
 * Description: This function writes the given string to the standard output.
 *
 * Return: This function does not return a value.
 */
void customPuts(char *stringer)
{
    unsigned int str_length;

    str_length = stringLength(stringer);

    write(STDOUT_FILENO, stringer, str_length);
}

/**
 * envWYA - Get the value of an environment variable
 * @what: Name of the environment variable to retrieve
 *
 * Description: This function retrieves the value of the specified environment
 * variable. If the variable is not found, it returns NULL.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *envWYA(const char *what)
{
	struct envWYAvariables eWv;

	eWv.envSize = 0;
	while (environ[eWv.envSize] != NULL)
	{
		eWv.envSize++;
	}
	eWv.cpyenv = NULL;
	eWv.cpyenv = envDup(eWv.cpyenv, eWv.envSize);

	eWv.sz = stringLength((char *)what);
	eWv.i = 0;
	while (eWv.cpyenv[eWv.i] != NULL)
	{
		eWv.chupapi = eWv.cpyenv[eWv.i];
		eWv.weigh = stringCompareN((char *)what, eWv.chupapi, eWv.sz);
		if (eWv.weigh == 1)
		{
			eWv.bargain = strtok(eWv.chupapi, "=");
			eWv.bargain = strtok(NULL, "\n ");
			if (eWv.bargain == 0)
			{
				write(STDERR_FILENO, "No such file or directory \n", stringLength("No such file or directory \n"));
				exit(EXIT_FAILURE);
			}
			eWv.routeSize = stringLength(eWv.bargain);
			eWv.route = malloc(sizeof(char) * eWv.routeSize + 1);
			if (eWv.route == NULL)
			{
				write(STDERR_FILENO, "Malloc Failed\n", stringLength("Malloc Failed\n"));
				return (NULL);
			}
			eWv.route = copyString(eWv.route, eWv.bargain);
			byeDoublePointers(eWv.cpyenv, eWv.envSize);
			return (eWv.route);
		}
		eWv.i++;
	}
	return (NULL);
}

/**
  * receptionist - Displays a custom prompt based on file descriptor and file status
  * @fileDescriptor: The file descriptor to check
  * @fileStatus: The structure containing file status information
  *
  * Description: Checks the file status and displays a custom prompt if the file
  * is a character device.
  *
  * Return: None
  */
void receptionist(int fileDescriptor, struct stat filestatus)
{
	fstat(fileDescriptor, &filestatus);

	if (S_ISCHR(filestatus.st_mode))
		customPuts("pleasework :( ");
}

/**
  * envDup - Duplicate environment variables
  * @cpyenv: Array of environment variables to be duplicated
  * @envSize: Number of environment variables in the array
  *
  * Description: This function duplicates an array of environment variables
  * and returns the duplicated array.
  *
  * Return: Duplicated array of environment variables
  */ 
char **envDup(char **cpyenv, unsigned int envSize)
{
	char *mugagno;
	unsigned int mugagno_length;
	unsigned int i;

	cpyenv = malloc(sizeof(char **) * (envSize));
	if (cpyenv == NULL)
	{
		write(STDERR_FILENO, "Malloc Failed\n", stringLength("Malloc Failed\n"));
		return (NULL);
	}
	i = 0;
	while (i < envSize)
	{
		mugagno = environ[i];
		mugagno_length = stringLength(mugagno);

		cpyenv[i] = malloc(sizeof(char) * mugagno_length + 1);
		if (cpyenv[i] == NULL)
		{
			write(STDERR_FILENO, "Malloc Failed\n", stringLength("Malloc Failed\n"));
			return (NULL);
		}
		copyString(cpyenv[i], environ[i]);
		i++;
	}
	return (cpyenv);
}

