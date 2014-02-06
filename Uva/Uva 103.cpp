/*基础题。动规。DAG上的动规。木块之间的嵌套关系构成了一个有向无环图，最长的嵌套序列就对应图中最长
  的路径。从顶点u出发能得到的最长路径为du，状态转移方程du=max{dv+1 |(u,v)是图中的一条边}。
  另外的问题是怎么建图。A能嵌套在B中，当且仅当，A、B都排好序后，对应位置上都有Ai<Bi。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int ver[32][12], grap[32][32], dp[32], p[32];
int k, n;
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p1)-(*p2);
}
int Calc(int a, int b)
{
	int i;
	for(i=0; i<k; i++)
		if(ver[a][i]>=ver[b][i])
			return 0;
	return 1;
}
int DP(int a)
{
	int i;
	if(dp[a] == 0) {
		for(i=0; i<n; i++) {
			if(grap[a][i] == 1) {
				if(DP(i)>dp[a]) {
					dp[a] = dp[i];
					p[a]  = i;
				}
			}
		}
		dp[a]++;
	}
	return dp[a];
}
void Print(int a)
{
	while(a != -1) {
		printf("%d ", a+1);
		a = p[a];
	}
	return;
}
int main()
{
	int i, j, mv, mp;
	while(scanf("%d %d", &n, &k)>0) {
		for(i=0; i<n; i++) {
			for(j=0; j<k; j++)
				scanf("%d", &ver[i][j]);
			qsort(ver[i], k, sizeof(int), comp);
		}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				grap[i][j] = Calc(i, j);
		memset(dp, 0, n*sizeof(int));
		memset(p, -1, n*sizeof(int));
		mv = DP(0);
		mp = 0;
		for(i=1; i<n; i++)
			if(DP(i)>mv) {
				mv = dp[i];
				mp = i;
			}
		printf("%d\n", mv);
		Print(mp);
		printf("\n");
	}
	return 0;
}
