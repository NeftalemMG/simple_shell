#ifndef SIMPLESHELLMAIN_H
#define SIMPLESHELLMAIN_H


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <stdint.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

struct shellsimplementVariables{
    char *package;
    char *package2;
    char *theline;
    char *tokenizedVar;
    char *binAdded;
    char *binAdded2;
    char **nateyarguments;
    char **letsgoo;

    int i;
    int x;
    int y;
    int ic;
    int reading;
    int status;

    size_t holderSize;
    pid_t id;
    int wasitPipped;
};

int compareStrings(char *str1, char *str2);
void printErrorMsg(char *error);
void printEnvironment(char **envp);
void printStringToFD(char *s, int fdI);
void freeDoublePointerArray(char **array);
void printStringAndNewLineToFD(char *s, int fdI);
void *find_byte_in_memory(const void *ptr, int c, size_t n);
char *getEnvironmentVariable(char *name);
char *_str_find_char(char *str, char ch);
char *get_executable_path(char *filename);
char *duplicateString(char *originalString);
char *trimString(const char *str, const char *cs);
char *find_char_in_string(const char *str, int c);
char *find_last_occurrence(const char *str, int c);
char *substring(char const *s, unsigned int begin, size_t l);
char *customSTRTOK(char *stringtobetokenized, char *delimiters);
size_t string_length(const char *str);
size_t limitedStringCopy(char *destBuffer, const char *sourceStr, size_t maxSize);

/* main function functions */
void readInput(struct shellsimplementVariables *ssV);
void tokenizeInput(struct shellsimplementVariables *ssV);
void buildCommandArray(struct shellsimplementVariables *ssV, char **envp);
void initializeVariables(struct shellsimplementVariables *ssV);
void executeCommand(struct shellsimplementVariables *ssV, char **envp);
void buildCommandArraySubSection1(struct shellsimplementVariables *ssV);
void buildCommandArraySubSection2(struct shellsimplementVariables *ssV);

#endif /* SIMPLESHELLMAIN_H */

