#include <readline/readline.h>
#include <readline/history.h>
#include </home/leo/myshell/include/buildneed.h>
#include <stdlib.h>

int read_command(char **command, char*** args, char *prompt)
{
    int i = 0, length = 0, count = 0, flag = 1;
	char *buffer;

	if(*command != NULL){
		free(*command);
	}
    
    buffer = readline(prompt);
    length = strlen(buffer);
	*args = (char**)malloc(sizeof(char*) * 255);
	for( i = length - 1; i >= 0; i--) {
		if(buffer[i] == ' ') {
			buffer[i] = '\0';
		} else {
			break;
		}
	}
    for( i = 0; i < length; i++) {
		for(int k = 0; i + k < length; k++){
			if( buffer[i+k] == ' ') {
				buffer[i+k] = '\0';
				flag = 1;
			}
			if( buffer[i+k] != '\0' && flag) {
				*(*args + count) = buffer + i + k;
				count++;
				flag = 0;
				break;
			}
		}
	}
    *command = buffer;
	if(prompt != NULL) {
		free(prompt);
	}
	return count;
}

    
