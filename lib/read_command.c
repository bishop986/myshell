#include <readline/readline.h>
#include <readline/history.h>
#include </home/leo/myshell/include/buildneed.h>
#include <stdlib.h>

int read_command(char **command, char*** args, char *prompt)
{
    int i = 0, length = 0, count = 1;
	char *buffer;
    
    buffer = readline(prompt);
    length = strlen(buffer);
	*args = (char**)malloc(sizeof(char*) * 255);
	**args = buffer;
    for( i = 0; i < length; i++) {
        if ( buffer[i] == ' ') {
			buffer[i] = '\0';
			*(*args + count) = buffer + i + 1;
			count++;
		}
	}
    *command = buffer;
	return count;
    
}

    
