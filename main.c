#include <sys/types.h>
#include <stdio.h>
#include "./include/buildneed.h"

int main()
{
  char *command  = NULL;
  char *prompt  = NULL;
  char **args   = NULL;
  int status, count = 0;
  int exeres = 1;
  
  #ifdef RELEASE
  printf("REALEASE Version 0.0\n");
  while(TRUE) {
    if((prompt = type_prompt()) == NULL){
        continue;
    }
    count = read_command( &command, &args, prompt);
	if(count == 0) {
		continue;
	}

	if(buildin_command(command, args, count)) {
		continue;
	}
    
    if(fork()!=0) {
        waitpid(-1, &status, 0); 
    } else {
        exeres = execvp(command, args);
    }

	if(exeres != 1) {
		perror(command);
		exeres = 1;
	}
  }
  #endif

  #ifdef DEBUG
  printf("DEBUG Version 0.0\n");
  prompt = type_prompt();
  count = read_command( &command, &args, prompt);
  printf("count : %d\n", count);
  printf("command is : %s\n", command);
  for( int i = 0; i < count; i++) {
	printf("This word is : %s\n", args[i]);
  }
  #endif
  
  return 0;
}

