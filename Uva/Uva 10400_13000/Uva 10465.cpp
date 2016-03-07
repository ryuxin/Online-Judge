/*基础题。动规。无限制背包。主体思想就是给定的物品能否恰好装满背包，
  若能，求出物品个数最多的方案。f[i, j]表示用前i个物品，背包容量为
  j时，-1表示不能装满，其余表示装满时最多的物品数。当给定的背包不
  能装满时，就依次枚举，直到找到满足条件的解。
  应该可以转化为不定方程求解，或者线性规划。不知复杂度如何。。。。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10005
#define LEN 35
int re[NUM];
int main()
{
	int m, n, t, i;
	while(scanf("%d %d %d", &m, &n, &t)>0) {
		memset(re, -1, sizeof(int)*NUM);
		for(i=0; i*m<NUM; i++) re[i*m] = i;
		for(i=n; i<=t; i++) if (re[i-n]>=0)	re[i] = max(re[i-n]+1, re[i]);
		if (re[t]>=0) printf("%d\n", re[t]);
		else {
			for(i=t-1; i>=0; i--) if (re[i] != -1) break;
			printf("%d %d\n", re[i], t-i);
		}
	}
	return 0;
}