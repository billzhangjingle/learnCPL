/*对输入的文本进行排序，这个是之前的那个功能*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define MAXLINES 5000
char *lineptr[MAXLINES];

#define LINESIZE   1000
// 读文本，保存


#if 0
// 之前的比较字符串的版本
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

#endif

int main( int argc, char *argv[] )
{
	int nline;
	int numberic = 0;

	if( argc > 1 && strcmp( argv[1], "-n") == 0 ){
			numberic = 1;
	}


	if ( (nline = readlines( lineptr, MAXLINES )) > 0){
			//void ** 和 后面的( int (*)(void *, void *))都是强转之含义 
			qsort_2( (void **)lineptr, 0, nline - 1, ( int (*)(void *, void *)) ( numberic ? numcmp : strcmp_) );
			writelines ( lineptr, nline);	
	}else {
		printf("error\n");
	}
	return 0;
}

#if 0
int numcmp( char *s, char *j )
{
	double x, y;
	x = atof_(s);
	y = atof_(j);

	if( x > y)
		return 1;
	else if( x < y )
		return -1;
	else 
		return 0;
}

#endif
