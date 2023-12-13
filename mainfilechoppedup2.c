#include "simpleshellmain.h"

/*
 * buildCommandArraySubSection1 - Build the command array subsection 1
 * @ssV: Pointer to struct shellsimplementVariables
 *
 * Description: This function allocates memory and builds a subsection of
 * the command array used in the shell. It concatenates the binAdded
 * string with the arguments and stores the result in ssV->letsgoo.
 *
 * Return: This function does not return a value.
 */
void buildCommandArraySubSection1(struct shellsimplementVariables *ssV)
{
    ssV->x = 1;
    ssV->letsgoo = malloc(((ssV->ic + 1) * sizeof(char *)) + strlen(ssV->binAdded2));

    if (ssV->letsgoo == NULL)
    {
        perror("Malloc Failed!");
    }
    else
    {
        ssV->y = 0;
        ssV->letsgoo[0] = ssV->binAdded2;

        while (ssV->nateyarguments[ssV->x] != NULL)
        {
            ssV->letsgoo[ssV->x] = ssV->nateyarguments[ssV->x];
            ssV->x++;
        }
        ssV->letsgoo[ssV->x] = NULL;
    }
}

/*
 * buildCommandArraySubSection2 - Build the command array subsection 2
 * @ssV: Pointer to the shellsimplementVariables structure
 *
 * Description: This function builds the second subsection of the command
 * array by copying elements from the nateyarguments array to the letsgoo
 * array.
 *
 * Return: None
 */
void buildCommandArraySubSection2(struct shellsimplementVariables *ssV)
{
    ssV->y = 0;
    ssV->letsgoo = malloc(((ssV->ic + 1) * sizeof(char *)));
    if (ssV->letsgoo == NULL)
    {
        perror("Malloc Failed!");
    }
    else
    {
        while (ssV->nateyarguments[ssV->y] != NULL)
        {
            ssV->letsgoo[ssV->y] = ssV->nateyarguments[ssV->y];
            ssV->y++;
        }
        ssV->letsgoo[ssV->y] = NULL;
    }
}

/*
 * buildCommandArray - Build command array for execution
 * @ssV: Pointer to struct shellsimplementVariables containing program state
 *
 * Description: This function builds the command array for execution based on
 * the input arguments and executable path. It also handles cases where the
 * executable is not found, printing an error message in such cases.
 *
 * Return: No explicit return value. The command array is stored in ssV->letsgoo.
 */

void buildCommandArray(struct shellsimplementVariables *ssV, char **envp)
{
    if (strncmp(ssV->nateyarguments[0], "/bin", 4) != 0)
    {
        ssV->binAdded = get_executable_path(ssV->nateyarguments[0]);
    }

    ssV->letsgoo = NULL;

    if (access(ssV->nateyarguments[0], F_OK) == -1 && ssV->binAdded == NULL)
    {
        printErrorMsg(ssV->nateyarguments[0]);
    }
    else
    {
        if (access(ssV->nateyarguments[0], F_OK) == -1)
        {
            if (strncmp(ssV->nateyarguments[0], "/bin", 4) != 0)
            {
                ssV->binAdded2 = get_executable_path(ssV->nateyarguments[0]);
                if (ssV->binAdded2 == NULL)
                {
                    printErrorMsg(ssV->nateyarguments[0]);
                }
                else
                {
                    buildCommandArraySubSection1(ssV);
                    executeCommand(ssV, envp);
                }
            }
            else
            {
                printErrorMsg(ssV->nateyarguments[0]);
            }
        }
        else
        {
            buildCommandArraySubSection2(ssV);
            executeCommand(ssV, envp);
        }
    }
}

