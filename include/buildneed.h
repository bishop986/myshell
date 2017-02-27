#ifndef BUILD_NEED
#define BUILD_NEED

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <unistd.h>

#define TRUE 1
#define MAXPATH 100

char * type_prompt();
int read_command( char**, char ***, char*);

char *prompt;
#endif
