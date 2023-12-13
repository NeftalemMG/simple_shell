#include "simpleshellmain.h"

/*
 * get_executable_path - Retrieves the full path of an executable file
 * @filename: The name of the executable file
 *
 * Description: This function searches for the specified executable file
 *              in the directories listed in the PATH environment variable.
 *              If found, it returns the full path; otherwise, it returns NULL.
 *
 * Return: A dynamically allocated string containing the full path,
 *         or NULL if the file is not found or if memory allocation fails.
 */

char *get_executable_path(char *filename)
{
    char *token, *path, *path_duplicate, *delimiters, *full_path, **path_array;
    int path_count, i, j;

    path = getEnvironmentVariable("PATH");
    path_duplicate = strdup(path);
    delimiters = ":";
    path_count = 0, i = 0, j = 0;
    token = strtok(path_duplicate, delimiters);
    while (token)
    {
        token = strtok(NULL, delimiters);
        path_count++;
    }
    free(path_duplicate);
    path_array = malloc((sizeof(char *) * (path_count + 1)));
    if (path_array == NULL)
    {
        return (NULL);
    }
    token = strtok(path, delimiters);
    while (token)
    {
        path_array[i] = token;
        token = strtok(NULL, delimiters);
        i++;
    }
    path_array[i] = NULL;
    while (path_array[j] != NULL)
    {
        full_path = malloc(sizeof(char) * (strlen(path_array[j]) + strlen(filename) + 2));
        if (full_path == NULL)
        {
            free(path_array);
            return (NULL);
        }
        sprintf(full_path, "%s/%s", path_array[j], filename);
        if (access(full_path, F_OK) == 0)
        {
            return (full_path);
        }
        free(full_path);
        j++;
    }
    free(path_array);
    return (NULL);
}

/*
 * find_char_in_string - Find the first occurrence of a character in a string
 * @str: The input string to search
 * @c: The character to find
 *
 * Description: This function searches for the first occurrence of the character
 * 'c' in the string 'str'.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char *find_char_in_string(const char *str, int c)
{
    char *result;

    result = find_byte_in_memory(str, c, string_length(str) + 1);
    return (result);
}

/*
 * find_byte_in_memory - Find the first occurrence of a byte in a block of memory
 * @ptr: The pointer to the memory block
 * @c: The byte to find
 * @n: The number of bytes to search
 *
 * Description: This function searches for the first occurrence of the byte 'c'
 * in the memory block starting at the address 'ptr' for 'n' bytes.
 *
 * Return: A pointer to the first occurrence of the byte in the memory block,
 * or NULL if the byte is not found.
 */
void *find_byte_in_memory(const void *ptr, int c, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
    {
        return (NULL);
    }
    while (i < n)
    {
        if (((unsigned char *)ptr)[i] == (unsigned char)c)
        {
            return (((unsigned char *)ptr) + i);
        }
        i++;
    }
    return (NULL);
}

/*
 * string_length - Calculate the length of a string
 * @str: Pointer to the input string
 *
 * Description: This function iterates through the characters of the given string
 *              until it encounters the null terminator, calculating the length.
 *
 * Return: Size of the input string (excluding the null terminator)
 */
size_t string_length(const char *str)
{
    size_t length;

    length = 0;

    while (str && str[length] != '\0')
    {
        length++;
    }

    return (length);
}

/*
 * compareStrings - Compares two strings lexicographically
 * @str1: First string to compare
 * @str2: Second string to compare
 *
 * Description: This function compares the characters of two strings
 * lexicographically until a difference is found or the end of both strings
 * is reached.
 *
 * Return: 0 if the strings are equal, a positive value if str1 is greater,
 * or a negative value if str2 is greater.
 */
int compareStrings(char *str1, char *str2)
{
    int index;

    index = 0;

    while (str1[index] != '\0' && str2[index] != '\0')
    {
        if (str1[index] != str2[index])
        {
            return (str1[index] - str2[index]);
        }
        ++index;
    }
    return (str1[index] - str2[index]);
}

