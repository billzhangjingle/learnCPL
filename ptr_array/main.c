/*对输入的文本进行排序，这个是之前的那个功能*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define MAXLINES 5000
char *lineptr[MAXLINES];

#define LINESIZE   1000
// 读文本，保存


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
