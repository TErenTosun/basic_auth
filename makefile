CC = gcc 

default: main.o basic_auth.o
	${CC} main.o basic_auth.o -o main

main.o: main.c basic_auth.h
	${CC} main.c -c

basic_auth.o: basic_auth.c basic_auth.h
	${CC} basic_auth.c -c

clean:
	del *.o *.exe