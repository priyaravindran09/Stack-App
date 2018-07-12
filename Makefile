all:	stack.o main.o
	gcc stack.o main.o -o stackApp

stack.o:stack.c	
	gcc -Wall -g -c stack.c

main.o:main.c
	gcc -Wall -g -c main.c

clean: 
	rm -rf *o stack main stackApp 
