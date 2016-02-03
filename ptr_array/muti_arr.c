#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char m_day[2][12] = {
{31,28,31,30,31,30,31,31,30,31,30,31},
{31,29,31,30,31,30,31,31,30,31,30,31},
};


int day_of_year( int year, int m, int d )
{
	//判断失败条件
	//mounth也要判断，是否有那么多天
	
	int day ;
	int leaf;
	int i;
	
	//又是忘记初始化造成的错误，导致打印出来的数字很大
	//day = 0;
	leaf = ( year%4 == 0 && year %100 != 0) || ( year%400 == 0 );
	
	if ( d > m_day[leaf][m] ){
		printf("err day\n");
		return -1;
	}
	for ( i = 1; i < m; i++ );
		day += m_day[leaf][i-1];
	
	day += d;
	return day; 
}

int mounth_day()
{
	
} 

int main( void )
{
	int day;
	day = day_of_year( 2000, 2, 23 );
	printf("%d\n", day);	
	return 0;
}
