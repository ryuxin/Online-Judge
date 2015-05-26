/*基础题。0-1背包。求最优解的递归方程dp[k][l] = max{dp[k+1][l], dp[k+1][l-track[k]]+track[k]}, 其表示从第k
  个物品开始拿，背包容量为l的最优解。要保存最优方案，记录p[k][l], 其为0表示不拿第k个物品，为1表示拿第k个物品*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define N 1000
#define Num_t 22
int dp[Num_t][N], p[Num_t][N], track[Num_t], t;
int DP(int k, int l)
{
	/*若令b=0, 则在计算p[k][l]时， 应为a>=b, p[k][l] = 1.
	  因为，此时可能a=b=0, 且p[k][l] = 0*/
	int a, b = -1;
	if (k>=t || l == 0)
		return 0;
	if (dp[k][l] == -1) {
		a = DP(k+1, l);
		if (track[k]<=l)
			b = track[k]+DP(k+1, l-track[k]);
		dp[k][l] = a > b ? a:b;
		p[k][l]  = a > b ? 0:1;
	}
	return dp[k][l];
}
void Print(int k, int l)
{
	if (k>=t || l <= 0)
		return ;
	if (p[k][l] == 1) {
		printf("%d ", track[k]);
		Print(k+1, l-track[k]);
	}
	else
		Print(k+1, l);
	return ;
}
int main()
{
	int n, i, j, r;
	while (scanf("%d%d", &n, &t)>0) {
		for(i=0; i<t; i++)
			scanf("%d", &track[i]);
		for(i=0; i<t; i++)
			for(j=1; j<=n; j++)
				dp[i][j] = p[i][j] = -1;
		r = DP(0, n);
		Print(0, n);
		printf("sum:%d\n", r);
	}
	return 0;
}