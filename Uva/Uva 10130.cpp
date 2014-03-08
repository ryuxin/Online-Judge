/*入门题。动规。背包问题。此题中，虽然同一个人不能拿多件同样的商品，
但不同的人之间可以那相同的商品。因此每个人能拿到的最大值是独立的，
最后总和的最大值就是每个人的最大值之和。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
struct Good {
	int p, w;
};
Good goods[1003];
int dp[1003][33], n;
int DP(int k, int w)
{
	int a, b = 0;
	if (k>=n || w == 0)
		return 0;
	if (dp[k][w] == -1) {
		a = DP(k+1, w);
		if (goods[k].w<=w)
			b = DP(k+1, w-goods[k].w)+goods[k].p;
		if (b>a)
			dp[k][w] = b;
		else
			dp[k][w] = a;
	}
	return dp[k][w];
}
int main()
{
	int t, i, g, s, j, w;
	scanf("%d", &t);
	while(t--) {
		s = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
			for(j=0; j<33; j++)
				dp[i][j] = -1;
		for(i=0; i<n; i++)
			scanf("%d%d", &goods[i].p, &goods[i].w);
		scanf("%d", &g);
		for(i=0; i<g; i++) {
			scanf("%d", &w);
			s = s+DP(0, w);
		}
		printf("%d\n", s);
	}
	return 0;
}