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

int strcmp_( char *s, char *t)
{
	int i;
#if 0
	//如果是加; 会导致到退出条件，然后再判断
	for ( i = 0; s[i] == t[i]; i++);
	
	//每次都进行判断
	for ( i = 0; s[i] == t[i]; i++)
		if( s[i] == '\0')
			return 0;
	return s[i] - t[i];
#endif

	//上面这样写是错误的，因为会导致 hello  和hellohh相等
	//for ( ; *s == *t; s++,t++);
	for ( ; *s == *t; s++,t++ )
		
		if ( *s == '\0')
			return 0;
		return *s  - *t;
}




int main(void)
{
	char  *ptr = NULL;
	int   ret;
	ptr = alloc_(100);

	strcpy_( ptr, "hello");	
	ret = strcmp_( ptr, "hellohhh");
	printf("ret:%d\n", ret );
	//strcpy(ptr, "hello");
	printf("%s\n", ptr);
	return 0;
}
