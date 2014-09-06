/*基础题。动规。dp[i][j]表示从(i, j)能得到的最大值。则
  他等于其相邻元素最大值+1.*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 105
#define LEN 35
int data[NUM][NUM], dp[NUM][NUM];
int d1[4] = {-1, 0, 1, 0}, d2[4] = {0, 1, 0, -1};
char name[NUM];
int DP(int a, int b)
{
	int i, t = 0, re;
	if (dp[a][b] == -1) {
		for(i=0; i<4; i++) {
			if (data[a+d1[i]][b+d2[i]]>=data[a][b]) continue;
			re = DP(a+d1[i], b+d2[i]);
			if (re>t) t = re;
		}
		dp[a][b] = t+1;
	}
	return dp[a][b];
}
int main()
{
	int n, c, r, i, j, re, t;
	scanf("%d", &n);
	while(n--) {
		scanf("%s%d%d", name, &r, &c);
		for(i=1; i<=r; i++)
			for(j=1; j<=c; j++)
				scanf("%d", &data[i][j]);
		for(i=0; i<c+2; i++) data[0][i] = data[r+1][i] = NUM;
		for(i=0; i<r+2; i++) data[i][0] = data[i][c+1] = NUM;
		memset(dp, -1, sizeof(dp));
		re = 0;
		for(i=1; i<=r; i++)
			for(j=1; j<=c; j++) {
				t = DP(i, j);
				if (t>re) re = t;
			}
		printf("%s: %d\n", name, re);
	}
	return 0;
}