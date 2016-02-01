//反转
#include <string.h>
#include <stdio.h>
int reserve( char s[] )
{
	int c, i,j;
	
	for ( i = 0, j = strlen(s) - 1; i < j; i++,j-- ){
		c = s[i];
		s[i] = s[j];	
		s[j] = c;
	}
	
	return 0;
}
int main(void)
{
	char s[]= "1234567";
	reserve(s);
	printf("%s\n", s);
	return 0;
}
