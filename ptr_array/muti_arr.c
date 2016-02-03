#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char m_day[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31},
};


int day_of_year( int year, int m, int d )
{
	//判断失败条件
	//mounth也要判断，是否有那么多天
	
	//int day ;
	int leaf;
	int i;

#if 0	
	//又是忘记初始化造成的错误，导致打印出来的数字很大
	day = 0;
	leaf = ( year%4 == 0 && year %100 != 0) || ( year%400 == 0 );
	if ( d > m_day[leaf][m] ){
		printf("err day\n");
		return -1;
	}
	for ( i = 1; i < m; i++ );
		day += m_day[leaf][i-1];
	
	day += d;
#endif

	//这样就可以不用重新定义一个变量
	leaf = ( year%4 == 0 && year %100 != 0) || ( year%400 == 0 );
	
	if ( d > m_day[leaf][m] ){
		printf("err day\n");
		return -1;
	}

	for ( i = 1; i < m; i++ );
		d += m_day[leaf][i];
	
	return d; 
}

int mounth_day( int year, int day, int *m, int *d ) 
{
	int leaf;	
	int i;
	
	leaf = ( year%4 == 0 && year %100 != 0) || ( year%400 == 0 );
	
	if ( (leaf && day > 366) ||( !leaf && day > 365) )		return -1;
	
	//只是实现功能， 这肯定是自己的思路，
	//判断停止条件时，用day >0 来判断，
	//太傻了，怪不得写不出代码来。 
	for ( i = 1; day > 0 ; i++ )
		day -= m_day[leaf][i];
	*m = i - 1 ;
	*d = day + m_day[leaf][i-1] ;

	return 0;
} 

int main( void )
{
	int day;
	int m, d;
	day = day_of_year( 2000, 2, 23 );
	printf("%d\n", day);	
	//mounth_day( 1999, 60,&m, &d );
	mounth_day( 2000, 60,&m, &d );
	
	printf("m:%d\tday:%d\n", m, d);
	return 0;
}
