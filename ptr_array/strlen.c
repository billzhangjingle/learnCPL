#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen_( char s[])
{
	int n = 0;
	int i = 0 ;
	char *p = s;
	//for( n = 0; *s != '\0'; s++,n++); 1
	//for ( i = 0; s[i] != '\0'; i++);	2
	
	//for( ;*p != '\0'; p++); 3
	//	return p - s;

	//for ( i= 0 ; p[i] != '\0'; i++ ); 4
	//	return i;

	
	
	//while( *s++ && ++n ); 5
	
	//while( s[i++] ); 6
	//	return i - 1; 
	
		
	
	//return n;
	//return i;
}

int strlen_2( char s[])
{
	int n;
	for( n = 0; *s != '\0'; s++,n++);

	return n;
}


int main(void)
{
	int len;
	char s[] = "123456";
	len = strlen_(s);
	
	printf("len:%d\n",len);
	return 0;
} 
