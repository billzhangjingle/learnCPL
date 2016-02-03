all:main
FLAGS 	= -g -Wall
CC 		= gcc
INCLUDE = -I./


#main:  readwrite.c  atof.c allocbuf.c qsort.c
main: grep.c atof.c
	$(CC) $(FLAGS) $^ -o $@ $(INCLUDE)

clean:
	rm *.o *.swp main -rf
