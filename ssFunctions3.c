#include "simpleshellmain.h"

/*
 * limitedStringCopy - Copy a string with size limitation
 * @destBuffer: Destination buffer to store the copied string
 * @sourceStr: Source string to be copied
 * @maxSize: Size of the destination buffer
 *
 * Description: This function copies at most (maxSize - 1) characters from the
 * source string to the destination buffer and ensures null-termination.
 * If maxSize is 0, no characters are copied, and the function returns 0.
 * The destination buffer must be large enough to accommodate the copied string.
 *
 * Return: The length of the source string (excluding null-terminator).
 */
size_t limitedStringCopy(char *destBuffer, const char *sourceStr, size_t maxSize)
{
    size_t i;
    
    i = 0;

    if (maxSize != 0)
    {
        while (sourceStr[i] != '\0' && i < maxSize - 1)
        {
            destBuffer[i] = sourceStr[i];
            i++;
        }
        destBuffer[i] = '\0';
    }
    return (string_length(sourceStr));
}

/*
 * find_last_occurrence - Find the last occurrence of a character in a string
 * @str: The input string
 * @c: The character to find
 *
 * Description: This function searches for the last occurrence of the specified
 * character 'c' in the given string 'str'.
 *
 * Return: A pointer to the last occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *find_last_occurrence(const char *str, int c)
{
    int i;

    i = string_length(str);
    while (i >= 0)
    {
        if (str[i] == (char)c)
            return ((char *)&str[i]);
        i--;
    }
    return (NULL);
}

/*
 * trimString - Trim leading and trailing characters from a string
 * @str: The input string to be trimmed
 * @cs: The set of characters to be trimmed from the input string
 *
 * Description: This function trims the leading and trailing characters specified
 *              in the set from the str and returns the trimmed string.
 *
 * Return: A dynamically allocated string containing the trimmed result.
 */
char *trimString(const char *str, const char *cs)
{
    size_t l;
    size_t r;

    if (!(str) || !(cs))
    {
        return (NULL);
    }

    l = 0;
    r = string_length(str) - 1;

    while (str[l] && find_char_in_string(cs, str[l]))
    {
        l++;
    }

    while (str[r] && find_char_in_string(cs, str[r]) && (r > l))
    {
        r--;
    }
    return (substring(str, l, r - l + 1));
}

/*
 *substring - Extracts a substring from a given string
 *@s: The input string
 *@begin: The starting index of the substring
 *@l: The length of the substring to extract
 *
 *Description: This function extracts a substring from the input string 's' starting
 *at the index 'start' and with a length specified by 'len'. If 'len' exceeds the
 *remaining characters in the string, the resulting substring will be truncated.
 *
 *Return: A dynamically allocated string containing the extracted substring.
 *         It is the caller's responsibility to free the memory.
 */
char *substring(char const *s, unsigned int begin, size_t l)
{
    char *result;
    size_t i;
    size_t slen;

    if (!s)
    {
        return (NULL);
    }
    i = 0;
    slen = strlen(s);

    if (slen < l)
    {
        result = (char *)malloc(slen + 1);
    }
    else
    {
        result = (char *)malloc(l + 1);
    }
    if (!result)
    {
        return (NULL);
    }

    while ((begin < slen) && (i < l && i < slen))
    {
        result[i] = s[begin];
        i++;
        begin++;
    }
    result[i] = '\0';
    return (result);
}

/*
 * duplicateString - Duplicates a given string
 * @originalString: The string to be duplicated
 *
 * Description: This function takes a string as input and creates a duplicate
 *              copy of it using dynamic memory allocation.
 *
 * Return: A pointer to the duplicated string, or NULL if memory allocation fails.
 */
char *duplicateString(char *originalString)
{
    char *duplicate;
    unsigned int i;
    unsigned int length;

    i = 0;
    length = 0;

    if (originalString == NULL)
    {
        return (NULL);
    }

    while (originalString[length] != '\0')
    {
        length++;
    }

    duplicate = (char *)malloc(sizeof(char) * (length + 1));
    if (duplicate == NULL)
    {
        return (NULL);
    }

    while (i < length)
    {
        *(duplicate + i) = originalString[i];
        i++;
    }
    *(duplicate + length) = '\0';

    return (duplicate);
}

