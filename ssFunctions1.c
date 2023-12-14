#include "simpleshellmain.h"

/**
  * copyString - copies a string from source to destination
  * @destination: the destination string
  * @source: the source string
  *
  * Description: This function copies the string pointed by `src` to the
  * string pointed by `dest`, including the null terminator.
  *
  * Return: The pointer to the destination string (`dest`).
  */
char *copyString(char *destination, char *source)
{
	int index;
	int length;

	length = stringLength(source);

	for (index = 0; index <= length; index++)
	{
		destination[index] = source[index];
	}
	return (destination);
}

/**
 * stringlength - Calculate the length of a string
 * @str: The input string
 *
 * Description: This function calculates the length of the given string.
 *
 * Return: The length of the string.
 */
int stringLength(char *str)
{
	int length;

	length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * stringCompare - compares two strings
 * to find out if they are exactly the same
 * @userInput: user input supplied to search for
 * @compareString: string to compare against
 * @inputLength: length of userInput
 *
 * Description: This function compares
 * two strings and returns 1 if they are equal,
 * -1 if they are not, and 0 if their lengths are different.
 *
 * Return: Returns 1 if the strings are identical,
 * -1 if they differ, and 0 if their lengths are not the same
 */
int stringCompare(char *userInput, char *compareString, unsigned int inputLength)
{
	unsigned int compareLength;
	unsigned int i;

	compareLength = stringLength(compareString);
	if (compareLength != inputLength)
	{
		return (-1);
	}
	i = 0;

	while (userInput[i] != '\0' && compareString[i] != '\0')
	{
		if (userInput[i] != compareString[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
  * stringCompareN - compare two strings up to a specified length
  * @str1: first string
  * @str2: second string
  * @length: number of characters to compare
  *
  * Description: This function compares two strings up to a specified length.
  *
  * Return: Returns 1 if the strings are identical, and -1 otherwise.
  */
int stringCompareN(char *str1, char *str2, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
	if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

/**
 * weOut_Deuces - Exits the shell program.
 *
 * Description: This function is responsible for terminating the shell program
 * and returning an exit status of -1.
 * Return: Returns -1 to indicate shell exit.
 *
 */
int weOut_Deuces(void)
{
	return (-1);
}

