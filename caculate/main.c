#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#define MAXOP  100
int main(void)
{
	char buff[MAXOP];
	int type ;
	int op2;
	while( ( type = getop(buff ) ) != EOF){
	
		switch (type){
		case NUMBER:
			push(atof(buff));
			break;
		case '+':
			push( pop() + pop() );
			break;
		case '*':
			push( pop()  * pop() );
			break;	
		case '/':
		 	op2 = pop();
		 	push( pop() / op2);
			break;
		case '-':
		 	op2 = pop();
		 	push( pop() - op2);
			break;
		case '\n':
			printf("the val :%0.2f\n", pop());
			break;
		default:
			break;
		}
	

	}
	return 0;
}
