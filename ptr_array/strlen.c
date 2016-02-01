#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen_( char s[])
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
