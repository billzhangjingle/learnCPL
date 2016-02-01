#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAXLINE   1000

char pattern[] = "ould";
int getline_( char s[], int lim)
{
	int c, i;
	i = 0;
	while ( --lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if ( c == '\n' )
		s[i++] = c;
	s[i] = '\0';
	return i;
}
int strindex ( char s[], char pattern[] )
{
	int i,j, k;
	int found = 0;
	for ( i = 0; i < strlen(s) - 1 ; i++ ){
		for ( k = i, j = 0; ( s[i] == pattern[j] ) && ( pattern[j] != '\0'); i++,j++ );
		if ( k > 0 && pattern[j] == '\0')
			 return i;
	}
	if ( found == 0){
		return -1;
	}
	return  found;
}
/* int main(void)
{
	char line[MAXLINE];
	int found = 0;
	while (getline_( line, MAXLINE ) > 0 ){
		if (strindex( line, pattern ) >= 0 ){
			printf("%s\n",line);
		}
	}
	return 0;
} */