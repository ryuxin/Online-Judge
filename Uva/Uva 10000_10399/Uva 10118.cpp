/*中等题。动规。本题的难度在与状态的维数比较多（四维），而且要维护的状态也很多。要记录当前已经配，
 *对的数目，用一个位数组记录盒子里颜色的状态和不同颜色的数目。dp[a1][a2][a3][a4]表示棋盘的状态，
 *求解时，依次尝试在每一列中取出下一个，并判断是否已有相同的颜色和不同颜色的总数。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 42
#define LEN 4
int dp[NUM][NUM][NUM][NUM];
int n, cake[NUM][LEN], a[LEN];
//x: 当前已配的对数，y: 颜色的状态，k: 不同颜色的数目
int DP_process(int x, int y, int k)
{
	int i, j, r=0, t, ny;
	if (dp[a[0]][a[1]][a[2]][a[3]] != -1) goto ret;
	if (k == 5) {
		dp[a[0]][a[1]][a[2]][a[3]] = x;
		goto ret;
	}
	for(i=0; i<LEN; i++) {
		if (a[i] >= n) t = x;
		else {
			if ((1<<cake[a[i]][i]) & y) {
				ny = y & ~(1 << cake[a[i]][i]);
				a[i]++;
				t = DP_process(x+1, ny, k-1);
			} else {
				ny = y | (1 << cake[a[i]][i]);
				a[i]++;
				t = DP_process(x, ny, k+1);
			}
			a[i]--;
		}
		if (t>r) r = t;
	}
	dp[a[0]][a[1]][a[2]][a[3]] = r;
ret:
	return dp[a[0]][a[1]][a[2]][a[3]];
}
int main()
{
	int i, j;
	while(scanf("%d", &n)) {
		if (n == 0) break;
		for(i=0; i<n; i++)
			scanf("%d%d%d%d", &cake[i][0], &cake[i][1], &cake[i][2], &cake[i][3]);
		memset(dp, -1, sizeof(dp));
		memset(a, 0, sizeof(a));
		DP_process(0, 0, 0);
		printf("%d\n", dp[0][0][0][0]);
	}
	return 0;
}