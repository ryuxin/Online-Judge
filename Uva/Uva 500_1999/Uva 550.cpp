/*基础题。数学题。注意数字可以有前导0.也就是说05， 005, 5是不一样的。
  逐位相乘，直到没有进位，且结果等于第一个乘数的最低位。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 55
#define LEN 28
int Mul(int b, int l, int r, int o, int *p)
{
	int t = l*r+o;
	*p = t%b;
	return t/b;
}
int main()
{
	int base, first, mul, cur, next, re;
	int r, s;
	while(scanf("%d%d%d", &base, &first, &mul)>0) {
		re = 1;
		r = 0;
		cur = first;
		while(1) {
			s = Mul(base, cur, mul, r, &r);
			if (s == 0 && r == first) break;
			cur = r;
			r = s;
			re++;
		}
		printf("%d\n", re);
	}
}