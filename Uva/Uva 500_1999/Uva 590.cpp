/*基础题。动规。cost(i, j, k)表示城市i到j在第k天的费用，dp[i][k]表示在第k天
 *到达城市i的最小费用，则dp[i][k] = min{dp[x][k-1]+cost(x, i, k)} (0<x<=n)。
 *和Bellman-Ford算法类似，在每一次迭代中松弛所有边。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 11
#define LEN 31
#define TOT 1005
struct Schedule {
	int period;
	int cost[LEN];
};
struct Schedule flight[NUM][NUM];
int n, m, dp[NUM][TOT];
static void inline Bellman(void)
{
	int i, j, k, index, cost;
	memset(dp, 0, sizeof(dp));
	for(i=1; i<n; i++) 
		dp[i][0] = flight[0][i].cost[0];
	for(i=1; i<m; i++) {
		for(j=0; j<n; j++) {
			if (dp[j][i-1] == 0) continue;
			for(k=0; k<n; k++) {
				if (j == k) continue;
				index = i%flight[j][k].period;
				cost = flight[j][k].cost[index];
				if (!cost) continue;
				cost += dp[j][i-1];
				if (dp[k][i] == 0 || cost < dp[k][i])
						dp[k][i] = cost;
			}
		}
	}
}
int main()
{
	int c = 0, i, j, k;
	struct Schedule *t;
	while(1) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				t = &flight[i][j];
				if (i==j) continue;
				scanf("%d", &t->period);
				for(k=0; k<t->period; k++)
					scanf("%d", &t->cost[k]);
			}
		}
		Bellman();
		printf("Scenario #%d\n", ++c);
		if (dp[n-1][m-1]) printf("The best flight costs %d.\n\n", dp[n-1][m-1]);
		else printf("No flight possible.\n\n");
	}
	return 0;
}