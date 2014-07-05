/*提高题。动态规划。优化的最长下降子序列。主要思想，对于同样长度的子序列，只需
  保存最后一个元素最大的子序列。re[i]表示以第i个元素结尾的最长子序列的长度。
  len[i]表示所有长度为i的下降子序列中，最后一个元素最大的序列，其最后一个元素的下标。
  满足性质data[len[1]]>data[len[2]]>……>data[len[n]]。
  计算re[i]时，用二分搜索在len数组中查找最后一个比data[i]大的元素，设为len[k]，则
  re[i] = k+1，且更新len[k+1] = i*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10005
struct Elepant {
	int id, w, s;
};
Elepant ele[NUM];
int n = 0, len[NUM], re[NUM], pa[NUM];
int comp(const void *a1, const void *a2)
{
	Elepant *p1, *p2;
	p1 = (Elepant *)a1;
	p2 = (Elepant *)a2;
	if(p1->w != p2->w) return p1->w-p2->w;
	return p1->s-p2->s;
}
int Binary(int left, int right, int v)  //返回最后一个比v大的值
{
	int t;
	//循环不变式。[left, right]肯定包含比v大的数
	//t为下中位数，保证t<left，使得每次循环left或right肯定有一个改变
	while(left<right) {
		t = (left+right+1)/2;
		if (ele[len[t]].s>v) left = t;
		else right = t-1;
	}
	return left;
}
void Print(int k)
{
	if (k == n) return ;
	Print(pa[k]);
	printf("%d\n", ele[k].id);
	return ;
}
int main()
{
	int i, cur, t, r;
	while (scanf("%d %d", &ele[n].w, &ele[n].s)>0) {
		ele[n].id = n+1;
		n++;
	}
	qsort(ele, n, sizeof(Elepant), comp);
	len[0] = n;
	ele[n].s= 1000000;
	len[1] = 0;
	cur    = re[0] = 1;
	for(i=1; i<n; i++) {
		t = Binary(0, cur, ele[i].s);
		pa[i] = len[t];
		re[i] = t+1;
		len[t+1] = i;
		if (t+1>cur) {
			cur = t+1;
			r = i;
		}
	}
	printf("%d\n", cur);
	Print(r);
	return 0;
}