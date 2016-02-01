#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop( char s[] )
{
	int c  ;
	int i;
	while( isdigit( s[0] = c = getch()) || c == '\t' ) ;
	s[1] = '\0';
	
	if( !isdigit(c) && c != '.' )
		return c;
	i = 0;
	if( isdigit(c) )
		while ( isdigit(s[++i] = c = getch()));
	
	if( c == '.'){
		while ( isdigit(s[++i] = c =  getch()));
	}
	
	if ( !isdigit(c))
		ungetch(c);
		
		return NUMBER;

}
