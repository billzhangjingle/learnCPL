#include <stdio.h>
#include "calc.h"
#define BUFSIZE 100
char buf[BUFSIZE];

int bufp = 0;
int getch(void)
{
	return (  bufp > 0 )  ? buf[--bufp] : getchar();		
}

void ungetch( int val )
{
	if( bufp > BUFSIZE)	{
		printf("buff is full");
	}else {
		buf[bufp++] = val;		
	}
}
