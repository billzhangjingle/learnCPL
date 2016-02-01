#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];

//下一个空闲的位置
//static char *allocp = allocbuf;
static char *allocp = &allocbuf[0];

//copy by bill
int strcpy_( char *dst, const char *src )
{
	int i;
	i = 0;
#if 0
	while( (dst[i] = src[i]) != '\0')	
		i++;

#endif
#if 0
	while( (*dst = *src)  != '\0'){
		dst++;
		src++;
	}
#endif

#if 0
	while( *dst ++ = *src++);

#endif

#if 1
	while( (*dst ++ = *src++) != '\0');

#endif

	return 0;

}

//strlen by bill
int strlen_( char *s)
{
	char *p = s;
	while( *p != '\0')
		p++;
	return p - s;
}	

//alloc by bill
char *alloc_(int n)
{
	if ( allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
		}
	
	return NULL;
}


void  afree_( char *p)
{
	if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
			allocp = p;
		
}

int strcmp( char *s, char *t)
{
	int i;
	for ( i = 0; s[i] == t[i]; i++);
		if( s[i] == '\0')
			return 0;
	return s[i] - t[i];
}




int main(void)
{
	char  *ptr = NULL;
	ptr = alloc_(100);

	strcpy_( ptr, "hello");	
	//strcpy(ptr, "hello");
	printf("%s\n", ptr);
	return 0;
}
