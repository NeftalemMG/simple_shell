#include "simpleshellmain.h"

/*
 * printEnvironment - Print environment variables
 * @envp: Array of environment variables
 *
 * Description: This function prints the environment variables.
 *
 * Return: None
 */
void printEnvironment(char **envp)
{
    int i;

    i = 0;
    while (envp && envp[i])
    {
        printStringAndNewLineToFD(envp[i], 1);
        i++;
    }
}

/*
 * printStringToFD - Print string to a file descriptor
 * @s: String to be printed
 * @fdI: File descriptor
 *
 * Description: This function prints the given string to the specified
 * file descriptor.
 *
 * Return: None
 */
void printStringToFD(char *s, int fdI)
{
    size_t i;

    if (s)
    {
        i = 0;
        while (s[i])
        {
            write(fdI, &s[i], 1);
            i++;
        }
    }
}

/*
 * printStringAndNewLineToFD - Print string followed by a new line to a file descriptor
 * @s: String to be printed
 * @fdI: File descriptor
 *
 * Description: This function prints the given string to the specified file descriptor
 *              and adds a new line at the end.
 *
 * Return: None
 */
void printStringAndNewLineToFD(char *s, int fdI)
{
    size_t i;

    if (s)
    {
        i = 0;
        while (s[i])
        {
            write(fdI, &s[i], 1);
            i++;
        }
        write(fdI, "\n", 1);
    }
}

/*
 * printError - Print error message
 * @error: Error message
 *
 * Description: This function prints an error message, including the program name
 *              and the corresponding system error message.
 *
 * Return: None
 */
void printErrorMsg(char *error)
{
    (void)error;
    printStringToFD("./;)", 2);
    printStringToFD(": ", 2);
    printStringAndNewLineToFD(strerror(errno), 2);
}

/**
 * freeDoublePointerArray - frees memory of a double pointer array
 * @array: double pointer array to be freed
 *
 * Description: This function takes a double pointer array as input and frees
 *              the memory occupied by its elements and the array itself.
 *
 * Return: Nothing is returned.
 */
void freeDoublePointerArray(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}


