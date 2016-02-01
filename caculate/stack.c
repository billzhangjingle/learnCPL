#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define STACKSZIE   100
double stack[STACKSZIE];
int stap = 0;

void push( double val )
{
	if( stap > STACKSZIE){
		printf("stack is full");	
	}else{
		stack[stap ++] = val; 
		}

}
double pop( void )
{
	if ( stap > 0)
		return stack[--stap];
	else{
		printf("stack is empty =======");
		}
	return 0;
}

