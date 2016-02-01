#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double atof_( char s[] )
{
	double val, power;
	int i, sign;
	
	for ( i  = 0; isspace(s[i]); i++ );
	
	sign = ( s[i] == '-') ? -1 : 1;
	
	if ( s[i] == '-' || s[i] == '+' )
		i++;
	
	for ( val = 0.0; isdigit(s[i]); i++ )
		val = val * 10.0 + s[i] - '0';
	
	if ( s[i] == '.' )
		i++;
	for ( power = 1.0 ; isdigit(s[i]); i++ ){
		val = val * 10.0 + s[i] - '0';
		power *= 10.0;
	}
	
	return sign * val / power;
} 

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

int main(void)
{
	//char s[] = "2233432.23242";
	double  sum, atof_( char []);
	
	char line[MAXLINE];
	int getline_(char line[], int max);
	
	sum = 0;
	while (getline_( line, MAXLINE ) > 0 ){
		printf("\t%g\n",sum += atof_(line));
	}

	return 0;
}