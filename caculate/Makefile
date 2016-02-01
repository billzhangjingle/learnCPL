all:main
FLAGS 	= -g -Wall
CC 		= gcc
INCLUDE = -I./


main: getch.c  getop.c  main.c  stack.c
	$(CC) $(FLAGS) $^ -o $@ $(INCLUDE)

clean:
	rm *.o *.swp main -rf
