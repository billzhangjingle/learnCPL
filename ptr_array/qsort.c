#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void swap( char *lineptr[], int x, int y)
{
	char *tmp;
	tmp			= lineptr[x];
	lineptr[x] 	= lineptr[y];
	lineptr[y]	= tmp;
}

//快速排序算法 现在我貌似的确是写不出来啊 2016-2-2 bill
void  qsort_( char *lineptr[],int left,  int right )
{
	int i, last;
	
	void swap( char *v[], int ,int );
	
	if ( left >= right)
		return ;
	
	swap( lineptr, left, (left + right)/2 );
	
	last = left;
	
	for ( i= left + 1; i <= right; i++ ){
		if ( strcmp_( lineptr[i], lineptr[left]) < 0)
				swap( lineptr, ++last, i );	
	}
	
	swap( lineptr, left, last);
	qsort_( lineptr , left, last - 1 );	
	qsort_ ( lineptr, last + 1, right);	
}




