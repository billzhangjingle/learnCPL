#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void swap( void **lineptr, int x, int y)
{
	void *tmp;
	tmp			= lineptr[x];
	lineptr[x] 	= lineptr[y];
	lineptr[y]	= tmp;
}
#if 0
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
#endif

void  qsort_2( void **lineptr,int left,  int right, int (*cmp)(void *, void *) )
{
	int i, last;
	
	void swap( void *v[], int  i ,int j);
	
	if ( left >= right)
		return ;
	
	swap( lineptr, left, (left + right)/2 );
	
	last = left;
	
	for ( i= left + 1; i <= right; i++ ){
	//	if ( strcmp_( lineptr[i], lineptr[left]) < 0)
		if ( (*cmp)(lineptr[i],lineptr[left]) < 0 )
			swap( lineptr, ++last, i );	
	}
	
	swap( lineptr, left, last);
	qsort_2( lineptr , left, last - 1, cmp );	
	qsort_2 ( lineptr, last + 1, right, cmp);	
}



