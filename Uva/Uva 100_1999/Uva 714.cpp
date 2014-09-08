/*典型题。二分枚举+贪心。求最大值最小的主要方法。
  二分枚举可能的最大值，将题转化为判定问题。判定
  问题可能有高效算法。
  本题的可转化为，对于给定的n个数，是否存在一种
  k分割，使分割最大值<=a。
  贪心。从头开始扫描，使每个分割尽量大。k个分割
  都用完后，若还有剩余，则不可行。否则，可行。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 501
#define LEN 100
int data[NUM], n, k, sum[NUM];
int re[NUM*NUM], total;
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p1)-(*p2);
}
bool Test(int a)    //检测是否存在一种分割方式，使得最大值<=a
{
	int i, j, r = 0;
	for(i=1; i<=k; i++) {
		for(j=r+1; j<=n; j++)
			if (sum[r]-sum[j]>a)
				break;
		r = j-1;
		if (r >= n) return true;
	}
	return false;
}
void Print(int s, int a, int d)   //打印最大值<=a的分割方案
{
	int i, j;
	if (d == 1) {
		printf("%d", data[n-1]);
		for(i=n-2; i>=s; i--) printf(" %d", data[i]);
		return ;
	}
	if (n-s == d) {
		printf("%d", data[n-1]);
		for(i=n-2; i>=s; i--) printf(" / %d", data[i]);
		return ;
	}
	for(i=s+1; i<=n; i++)
		if (sum[s]-sum[i]>a || n-i<d-1)
			break;
	Print(i-1, a, d-1);
	printf(" /");
	for(i=i-2; i>=s; i--) printf(" %d", data[i]);
	return ;
}
void Solve(void)
{
	int l, r, m;
	l = 0;
	r = total-1;
	while(l<r) {
		m = (l+r)/2;
		if (Test(re[m])) r = m;
		else l = m+1;
	}
	Print(0, re[l], k);
	printf("\n");
	return ;
}
int main()
{
	int i, j, c;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &k);
		sum[n] = j = 0;
		for(i=n-1; i>=0; i--) {
			scanf("%d", &data[i]);
			if (data[i]>j) j = data[i];
			sum[i] = data[i]+sum[i+1];
		}
		total = 0;
		re[total++] = j;
		for(i=1; i<n; i++)
			for(j=0; j+i<n; j++)
				if (sum[j]-sum[j+i+1]>re[0])
					re[total++] = sum[j]-sum[j+i+1];
		qsort(re, total, sizeof(int), comp);
		Solve();
	}
	return 0;
}