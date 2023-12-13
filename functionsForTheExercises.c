#include "simpleshellmain.h"

extern char **environ;

/*
 * getEnvironmentVariable - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Description: This function retrieves the value of the specified
 * environment variable. It searches through the environment variables
 * until it finds a match for the given name, and returns
 * the corresponding value.
 *
 * Return: On success, returns a dynamically allocated string containing the
 * value of the environment variable. It is the responsibility of
 * the caller to free the memory allocated for the returned string.
 * If the environment variable is not found, returns NULL.
 */
char *getEnvironmentVariable(char *name)
{
    char *newname, *envvalue, **env;

    newname = duplicateString(name);
    env = environ;
    while (*env != NULL)
    {
        if (strncmp(*env, newname, strlen(newname)) == 0)
        {
            envvalue = malloc(strlen(*env) + 1 - strlen(newname));
            envvalue = substring(*env, strlen(newname) + 1, strlen(*env));
            return (envvalue);
        }
        env++;
    }
    return (NULL);
}

/**
 * _str_find_char - Find the first occurrence of a character in a string.
 * @str: The string to be searched.
 * @ch: The character to search for.
 *
 * Return: A pointer to the first occurrence of @ch in @str, or NULL if not found.
 */
char *_str_find_char(char *str, char ch)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            return (str + i);
        }
    }

    return (NULL);
}

/*
 * customSTRTOK - this function replicates all the functionalities
 * of the C function "strtok"
 *
 * @stringtobetokenized: the string that is going to be tokenized
 * @delimiters: these are the characters that are going to used
 * to tokenize the string "stringtobetokenized"
 *
 * Description: refer to the first commented out line
 *
 * Return: returns the tokenized string upon sucessful tokenization
 * (or)
 * returns NULL if tokenization fails
 */
char *customSTRTOK(char *stringtobetokenized, char *delimiters)
{
    char *wearehere, *weareattheend;
    static char *motnef;
    
    motnef = NULL;

    if (stringtobetokenized != NULL)
    {
        motnef = stringtobetokenized;
    }

    else if (motnef == NULL)
    {
        return (NULL);
    }

    wearehere = motnef;
    while (*motnef != '\0' && _str_find_char(delimiters, *motnef) != NULL)
    {
        motnef++;
    }

    if (*motnef == '\0')
    {
        motnef = NULL;
        return (NULL);
    }

    weareattheend = motnef + 1;
    while (*weareattheend != '\0' && _str_find_char(delimiters, *weareattheend) == NULL)
    {
        weareattheend++;
    }
    *weareattheend = '\0';
    return (wearehere);
}

