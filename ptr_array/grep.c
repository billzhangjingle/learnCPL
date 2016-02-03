/*要实现grep 函数的功能：可以加参数 -x -n 等 -xn -nx 等
 * 一年前的实现思路： 把-x -n 保存到一个数组中， 打印的时候再根据数组中有没有那个字段进行判断
 *wireshark中有这种参数进行比较的，利用一个函数， man 3 getopt 函数来实现
* 用来某个字段置为1 ，或者是置为0等操作
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define MAXLINE 1000

//*++argv是指向参数字符串的指针
//(*++argv)[0] 是指针的第一个字符
//*++argv[0],则是指向的是 后面的字符
int main( int argc, char *argv[] )
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	
	
	//目前只能处理-r -n  -rn -nr 命令
	while ( --argc > 0 && (*++argv)[0] == '-' )
		// nx等内容
		while ( (c = *++argv[0]) )
			switch(c){
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find :illegal option %c\n",c);
				argc = 0;
				found = -1;
				break;
			}

		if ( argc != 1 )
			printf(" usage :find -x -n pattern\n");
		else {
			while (getline_( line,MAXLINE ) > 0){
				lineno++;
				//以前没有见过这么写的
				//argv 是属于要匹配的字符串
				if ((strstr(line , *argv) != NULL) != except){
					if(number)
						printf("%ld:",lineno);
						printf("%s",line);
						found++;
				}
			}
		}
	return found;
}
