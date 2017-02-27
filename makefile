INCLUDE = /home/leo/myshell/include
LIB = /home/leo/myshell/lib
OBJ = dhsh


$(OBJ) : main.o type_prompt.o read_command.o
	cc -o $(OBJ) *.o  -I /usr/include -lreadline -ltermcap
main.o : main.c $(INCLUDE)/buildneed.h
	cc -c main.c -D RELEASE -g
type_prompt.o : $(LIB)/type_prompt.c $(INCLUDE)/buildneed.h
	cc -c $(LIB)/type_prompt.c -g
read_command.o : $(LIB)/read_command.c $(INCLUDE)/buildneed.h
	cc -c $(LIB)/read_command.c -g
clean :
	rm *.o
