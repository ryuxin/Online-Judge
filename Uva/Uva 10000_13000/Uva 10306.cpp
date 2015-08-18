/*基础题。动规+枚举。多维多重背包问题。dp[i][a][b]表示从第1到第i种货币
 *组成价值为(a, b)所需要的最少货币数。由于每种货币数量无限，则状态转移
 *方程为dp[i][a][b] = min(dp[i-1][a][b], dp[i][a-ai][b-bi]+1)，可以用
 *滚动数组将上面数组将为二维。因为最终价值c = sqrt(a^2+b^2)，枚举满足
 *条件的所有(a, b)，取dp[a][b]最小值即为所求。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 305
#define LEN 45
#define EPSON 1e-9
#define TOT 3000
struct Coin {
	int a, b;
};
Coin coins[LEN];
int dp[NUM][NUM];
int n, c, c2;
void DP()
{
	int i, j, k, l, a, b;
	for(i=0; i<NUM; i++)
		for(j=0; j<NUM; j++)
			dp[i][j] = TOT;
	dp[0][0] = 0;
	for(i=0; i<n; i++) {
		a = coins[i].a;
		b = coins[i].b;
		for(j=a; j<=c; j++) {
			l = sqrt((double)(c2-j*j))+1;
			for(k=b; k<=l; k++) {
				if (dp[j-a][k-b]+1 < dp[j][k])
					dp[j][k] = dp[j-a][k-b]+1;
			}
		}
	}
}
int main()
{
	int i, j, t, l, m;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &c);
		c2 = c*c;
		for(i=0; i<n; i++)
			scanf("%d%d", &coins[i].a, &coins[i].b);
		DP();
		m = TOT;
		for(i=0; i<=c; i++) {
			l = sqrt((double)(c2-i*i))+EPSON;
			if (i*i+l*l == c2)
				if (dp[i][l] < m) m = dp[i][l]; 
		}
		if (m < TOT) printf("%d\n", m);
		else printf("not possible\n");
	}
	return 0;
}