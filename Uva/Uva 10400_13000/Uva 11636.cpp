/*入门题。基本的位操作。求1的个数，判断是不是2的次幂，求对数。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 100005
#define LEN 160
static inline int ones(int n)
{
	n = (n & 0x55555555)+((n>>1) & 0x55555555);
	n = (n & 0x33333333)+((n>>2) & 0x33333333);
	n = (n & 0x0f0f0f0f)+((n>>4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff)+((n>>8) & 0x00ff00ff);
	n = (n & 0xffff)+((n>>16) & 0xffff);
	return n;
}
static inline int ispow2(int n)
{
	return !(n & (n-1));
}
static inline int mylog(int n)
{
	int a, b;
	a = ispow2(n);
	n = n | (n>>1);
	n = n | (n>>2);
	n = n | (n>>4);
	n = n | (n>>8);
	n = n | (n>>16);
	b = ones(n);
	return b-a;
}
int main()
{
	int n, c=0, r;
	while(scanf("%d", &n)) {
		if (n<0) break;
		c++;
		r = mylog(n);
		printf("Case %d: %d\n", c, r);
	}
	return 0;
}