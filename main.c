#include <sys/types.h>
#include <stdio.h>
#include </home/leo/myshell/include/buildneed.h>

int main()
{
  char *command  = NULL;
  char *prompt  = NULL;
  char **args   = NULL;
  int status, count = 0;
  
  #ifdef RELEASE
  printf("REALEASE Version 0.0\n");
  while(TRUE) {
    if((prompt = type_prompt()) == NULL){
        continue;
    }
    count = read_command( &command, &args, prompt);
    
    if(fork()!=0) {
         waitpid(-1, &status, 0); 
    } else {
         execvp(command, args); 
    }
  }
  #endif

  #ifdef DEBUG
  printf("DEBUG Version 0.0\n");
  prompt = type_prompt();
  count = read_command( &command, &args, prompt);
  printf("count : %d\n", count);
  for( int i = 0; i < count; i++) {
	printf("This word is : %s\n", args[i]);
  }
  #endif
  
  return 0;
}

