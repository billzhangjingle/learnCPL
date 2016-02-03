#ifndef __FUNC_H__
#define __FUNC_H__


double atof_( char s[] );

int getline_( char s[], int lim );

char *alloc_(int n );
int strcmp_( char *dst, char *src );
int numcmp ( char *s, char *j );


void qsort_( char *lineptr[],int low,  int high );
void qsort_2( void **lineptr,int low,  int high, int (*cmp)( void *, void *) );

int readlines( char *lineptr[], int maxline );

int writelines( char *lineptr[], int num );

#endif

