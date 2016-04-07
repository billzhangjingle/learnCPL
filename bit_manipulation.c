/*位操作总结
 * 判断奇数偶数
 * 交换两数
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap( int *a, int *b)
{
	if( *a != *b){
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	
	}
}

int signreversal( int a)
{
	return ~a + 1;
}
/*绝对值*/
int abs( int a)
{
	int i = a>>31;

	return i == 0 ? a:( ~a + 1);
}
/*与0 异或 是本身，与0xffffffff 是取反*/
int my_abs( int a)
{
	int i = a>>31;

	return ( (a^i) - i);
}
int main(void)
{
	int i;
#if 0	
	for( i = 0; i < 100; i++ ){
		if( i&1){
			printf("%d ",i);
		}
	}
	putchar('\n');
#endif
#if 0
	int a = 1;
	int b = 2;
	swap( &a, &b);
	printf("%d %d \n", a, b);
#endif	
	int a =7, b = -12345;

	printf("%d %d\n", abs(a), abs(b));
	return 0;
}
