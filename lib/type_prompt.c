#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </home/leo/myshell/include/buildneed.h>

char * type_prompt()
{
  struct passwd *user_info = NULL;
  char user_hostname[50];
  char user_dir[MAXPATH];
  char tmpbuffer[MAXPATH];
  int hostname_status = 0;
  int homedir = 1;
  
  prompt = (char*)malloc(sizeof(char)* 255);

  if(( user_info = getpwuid(getuid())) == NULL ||
     ( gethostname(user_hostname, 50)) == -1   ||
     ( getcwd(tmpbuffer, MAXPATH))      == NULL) {
     return NULL;
  }

  for(int i = 0; i < strlen(user_info->pw_dir); ++i) {
    if(i == 0 && strlen(user_info->pw_dir) > strlen(tmpbuffer)) {
        homedir = 0;
        strcpy(user_dir, tmpbuffer);
        break;
    }
    if(tmpbuffer[i] != user_info->pw_dir[i]) {
        homedir = 0;
        strcpy(user_dir, tmpbuffer);
        break;
    }
  }
  if(homedir) {
    user_dir[0] = '~';
    for(int i = strlen(user_info->pw_dir), j = 1; i < sizeof(tmpbuffer); i++, j++) {
    user_dir[j] = tmpbuffer[i];
    }
  }
  
  if(user_info->pw_uid == 0) {
     sprintf( prompt,"\033[1m\033[40;32m[dhsh]%s@%s:\033[0m\033[1m\033[40;34m%s\033[0m# \0"
        , user_info->pw_name, user_hostname, user_dir);
  } else {
     sprintf( prompt,"\033[1m\033[40;32m[dhsh]%s@%s:\033[0m\033[1m\033[40;34m%s\033[0m$ \0"
        , user_info->pw_name, user_hostname, user_dir);
  } 
  return prompt;
}
  
