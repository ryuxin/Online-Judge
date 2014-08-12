/*基础题。模拟。简单模拟随机数生成的过程，当检查到产生重复的随机数的时候，
  即可判断出周期。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10005
#define LEN 105
int len, data[NUM];
int Contain(int k)
{
	int i;
	for(i=0; i<len; i++)
		if (data[i] == k)
			return i;
	return i;
}
int main()
{
	int z, i, m, l, r, c = 0;
	while(scanf("%d%d%d%d", &z, &i, &m, &l) > 0) {
		if (z+i+m+l == 0) break;
		c++;
		len = 1;
		data[0] = l;
		while(1) {
			l = (z*l+i)%m;
			r = Contain(l);
			if (r == len) data[len++] = l;
			else {
				printf("Case %d: %d\n", c, len-r);
				break;
			}
		}
	}
	return 0;
}