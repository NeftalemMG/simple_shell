#include "simpleshellmain.h"

/**
  * byeDoublePointers - Frees the memory allocated for a double pointer array.
  * @array: The double pointer array to be freed.
  * @length: The length of the array.
  *
  * Description: This function frees the memory allocated for each string in
  * the array and then frees the memory allocated for the array itself.
  *
  * Return: No return value.
  */

void byeDoublePointers(char **arr, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
/**
 * stringChoppedUp - Tokenizes input string.
 * @inputString: Input string to be tokenized.
 *
 * Description: This function tokenizes the input string based on whitespace
 * characters and returns an array of tokens.
 *
 * Return: Pointer to an array of tokens.
 */
char **stringChoppedUp(char *inputString)
{
	char **wholeBody;
	char *limbs;
	unsigned int i;

	wholeBody = malloc(sizeof(char) * 1024);
	if (wholeBody == NULL)
	{
		write(STDERR_FILENO, "Malloc Failed \n", stringLength("Malloc Failed \n"));
		exit(EXIT_FAILURE);
	}
	limbs = strtok(inputString, "\n\t\r ");
	i = 0;
	while (limbs != NULL)
	{
		wholeBody[i] = limbs;
		limbs = strtok(NULL, "\n\t\r ");
		i++;
	}
	wholeBody[i] = NULL;
	return (wholeBody);
}

/**
  * adiosMuchachos - Free allocated memory for tokens and related variables
  * @tokens: The array of strings (tokens) to be freed
  * @path: The path string to be freed
  * @line: The line string to be freed
  * @fullpath: The full path string to be freed (optional)
  * @flag: An integer flag indicating whether to
  * free fullpath (1 for yes, 0 for no)
  *
  * Description: This function frees the memory allocated for various strings
  * and the tokens array. If the flag is set to 1,
  * it also frees the fullpath string.
  *
  * Return: No return value.
  */

void adiosMuchachos(char **tokens, char *path, char *line, char *fullpath, int idibtgog)
{
	free(path);
	free(tokens);
	free(line);
	if (idibtgog == 1)
		free(fullpath);
}

