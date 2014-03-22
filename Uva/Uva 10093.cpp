/*基础题。数学题，简单数论。若一个数是N进制，其十进制为
  n = Sum{ai*N^i}。对任意i，N^i = (N-1+1)^i，由二项式展开，
  N^i 与 1 模N-1同余，所以n 与 Sum{ai}模N-1同余。若要使
  n能整除N-1，只需其各个位的数字之和能整除N-1。
  边界情况：n = 0，基数是2；输入字符中，可能有非法字符*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int c2i(char c)
{
	if ('0'<=c && c<='9')
		return c-'0';
	if ('A'<=c && c<='Z')
		return 10+c-'A';
	if ('a'<=c && c<='z')
		return 36+c-'a';
	return 0;
}
int main()
{
	int i, m, s, t;
	bool c = true;
	char n;
	m = s = 0;
	while(n = getchar()) {
		if (n == EOF) 
			break;
		if (n == '\n') {
			if (m == 0) {
				printf("2\n");
				m = s = 0;
				continue;
			}
			for(i=m+1; i<63; i++)      //基数一定大于所出现的数字
				if (s%(i-1) == 0) {
					printf("%d\n", i);
					break;
				}
			if (i == 63)
				printf("such number is impossible!\n");
			m = s = 0;
		}
		else {         //计算各个位数字之和
			t = c2i(n);
			s = s+t;
			if(t>m)
				m = t;
		}
	}
	return 0;
}