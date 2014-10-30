/*典型题。动规。最长上升子序列。枚举中间顶点的位置。中间顶点位k时，满足要求的最长子
  序列长度是，[1,k]中以k结尾的最长上升子序列，和[k,n]中以k开头的最长下降子序列，两
  者中较小的一个。所以进行两遍动规分别求出以最长上升和下降的子序列。
  由于数据规模很大，要用nlgn的优化。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10005
#define LEN 15
#define MIN(a,b) (a>b ? b: a)
int data[NUM], dh[NUM], dl[NUM], n;
int ll[NUM];       //不要求具体的子序列，这里不必保存数组下标，直接保存序列中的值
inline int Binary_search(int l, int r, int k)
{
	int m;
	while(l<r) {
		m = (l+r+1)/2;
		if (ll[m]<k) l = m;
		else r = m-1;
	}
	if (l == r && ll[r]<k) return r;
	return 0;
}
void LIS_1()
{
	int i, m, t;
	dh[0] = 1;
	ll[1] = data[0];
	m = 1;
	for(i=1; i<n; ++i) {
		if (data[i]<=ll[1]) t = 0;               //比最小值还小，不必进行比较了
		else {
			t = Binary_search(1, m, data[i]);
			if (t+1>m) m = t+1;
		}
		dh[i] = t+1;
		ll[t+1] = data[i];
	}
}
void LIS_2()
{
	int i, m, t;
	dl[n-1] = 1;
	ll[1] = data[n-1];
	m = 1;
	for(i=n-2; i>=0; --i) {
		if (data[i]<=ll[1]) t = 0; 
		else {
			t = Binary_search(1, m, data[i]);
			if (t+1>m) m = t+1;
		}
		dl[i] = t+1;
		ll[t+1] = data[i];
	}
}
int main()
{
	int i, re;
	while(scanf("%d", &n)>0) {
		for(i=0; i<n; ++i) scanf("%d", &data[i]);
		LIS_1();
		LIS_2();
		re = MIN(dh[0], dl[0]);
		for(i=1; i<n; ++i) if (re<MIN(dh[i],dl[i])) re = MIN(dh[i],dl[i]);
		printf("%d\n", 2*re-1);
	}
	return 0;
}