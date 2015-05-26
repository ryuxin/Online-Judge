/*典型题。深搜回溯。设前k-1个邮票已选好面值，且其构成的最大的连续值为mc，能得到的最大值是ml。
  现在考虑第k个邮票。显然它要比k-1邮票的面值大，但最大是ml+1。如果再大，ml+1就肯定无法得到。
  枚举第k个邮票的所有可能值。对于一个总值，只需记录得到它的最少邮票数。所以用一个数组a，a[i]
  表示最少能用几个邮票得到总面值i。对于一个总面值i，将第k个邮票补在它的空位中，就可以得到一个
  新的面值。这样，对所有的i，依次填满它的空位，就能得到加入第k个邮票后的所有可能取值。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10
#define LEN 200
int back[NUM][LEN], best_re[NUM];
int h, k, re[NUM], best, cur, limit;
void Backtrace(int d)
{
	int i, j, l, old_cur, old_limit, temp, tem;
	if (d == k) {
		if (cur>best) {
			best = cur;
			memcpy(best_re, re, sizeof(int)*k);
		}
		return ;
	}
	old_cur = cur;
	old_limit = limit;
	for(i=re[d-1]+1; i<=old_cur+1; ++i) {
		limit = old_limit;
		cur = old_cur;
		re[d] = i;
		memcpy(back[d], back[d-1], LEN*sizeof(int));
		for(j=0; j<=old_limit; ++j) {
			temp = back[d][j];
			for(l = h-temp; l>=1; --l) {
				tem = j+i*l;
				if (back[d][tem]>temp+l) {
					back[d][tem] = temp+l;
					if (tem>limit) limit = tem;
				}
			}
		}
		for(j=old_cur+1; j<=limit; ++j) {
			if (back[d][j]<=h) ++cur;
			else break;
		}
		Backtrace(d+1);
	}
}
int main()
{
	int i, j;
	while(scanf("%d %d", &h, &k)>0) {
		if (h == 0 && k== 0) break;
		for(i=k-1; i>=0; --i)
			for(j=0; j<LEN; ++j)
				back[i][j] = h+1;
		re[0] = 1;
		for(i=h; i>=0; --i) back[0][i] = i;
		limit = cur = best = h;
		Backtrace(1);
		for(i=0; i<k; ++i) printf("%3d", best_re[i]);
		printf(" ->%3d\n", best);
	}
	return 0;
}