#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define MAXLINES 5000
char *lineptr[MAXLINES];

#define LINESIZE   1000
// 读文本，保存
int readlines( char *lineptr[], int maxline );

//排序

//输出
int writelines( char *lineptr[], int num );


int main(void)
{
	int nline;
	
	if ( (nline = readlines( lineptr, MAXLINES )) > 0){
			qsort_( lineptr, 0, nline - 1 );
			writelines ( lineptr, nline);	
	}else {
		printf("error\n");
	}	
	return 0;
}

int readlines( char *lineptr[], int maxline )
{
	int 	nline;
	int 	len;
	nline 	= 0;
	
	char 	*p ;
	char 	linebuf[LINESIZE];
	//想想需不需要读到一个buf 里面，然后再保存起来
	while( ( len = getline_(linebuf, LINESIZE)) > 0){
	//读一行的时候，判断失败条件， 有什么呢？ 1. 最大函数超过maxline , 2. 分配内存失败
	if ( nline >=MAXLINES || ( p = alloc_(len) ) == NULL ){
				return -1;
	}else {
			//我会这样写
			//strncpy( p, line, len );
			//p[len -1] = '\0';	
			
			//牛人这么写
			linebuf[len-1] = '\0';
			strcpy( p,linebuf );
			lineptr[nline++] = p;		
	}
	} 	 	
	return nline ;
}


//输出
int writelines( char *lineptr[], int num )
{
#if 0
太low 了
	int i;
	for ( i = 0; i < num; i++){
		printf("[%d]:%s\n", i, lineptr[i]);
	}
	return 0;
#endif
	while( num-- > 0)
		printf(" %s \n", *lineptr++ );
	return 0;
}



