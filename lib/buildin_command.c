#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/buildneed.h"

int buildin_command(char *command, char **args, int count)
{
	int status = 1;
	struct passwd *user_info = NULL; 
	if(strlen(command) == 2 && command[0] == 'c' && command[1] == 'd') {
		if(count == 1) {
			chdir(".");
			return 1;
		} else if(args[1][0] == '~') {
			printf("%s\n", args[1]);
			user_info = getpwuid(getuid());
			status = chdir(user_info->pw_dir);
		} else {
			chdir(args[1]);
		}

		if(status == -1) {
			perror(args[1]);
		}
		return 1;
	} else if(strlen(command) == 4 && command[0] == 'e' && command[1] == 'x') {
		exit(0);
	}
	return 0;
}
		
