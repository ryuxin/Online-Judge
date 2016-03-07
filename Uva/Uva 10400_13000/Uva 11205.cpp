/*基础题。回溯搜索。此题规模很小，可以用暴力深搜。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define Max_N 105
int p, n, cur, best;
int symbol[Max_N];
void reset(int *a, int *b, int k)        //将a的第k列置0， 赋给b
{
	int i, j = 1<<k;
	j = ~j;
	for(i=0; i<n; i++)
		b[i] = a[i]&j;
	return ;
}
bool valid(int *a)
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if (a[i] == a[j])
				return false;
	return true;
}
void Backtrace(int k, int *a)
{
	int temp[Max_N];
	if (k>=p)
		return;
	if (cur+p-k<=best)     //即使剩余的列都置0，也比best少，此处不可能有最优解
		return;
	reset(a, temp, k);     //将第k列置0
	if (valid(temp)) {     //置0后，仍可以区分，搜索下一列
		cur++;             //更新
		if (cur>best)
			best = cur;
		Backtrace(k+1, temp);
		cur--;            //回溯
	}
	Backtrace(k+1, a);      //不处理第k列，直接搜索下一列
	return;
}
int main()
{
	int t, i, j, s, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &p, &n);
		for(i=0; i<n; i++) {
			r = 0;
			for(j=0; j<p; j++) {
				scanf("%d", &s);
				r = s+2*r;
			}
			symbol[i] = r;
		}
		cur = best = 0;
		Backtrace(0, symbol);
		printf("%d\n", p-best);
	}
	return 0;
}