/*基础题。动规，最优矩阵乘法。状态转移方程
  dp[l][r] = min{dp[l][i]+dp[i+1][r]+weight(l*i*r)} l<=i<r.
  基本思路就是对一个乘法链，枚举加括号的位置。
  weight()表示两个矩阵相乘时的运算量*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define N 15
int wei[N], dp[N][N], p[N][N];
int DP(int l, int r)
{
	int i, m, t;
	if (dp[l][r] == -1) {
		m = DP(l+1, r)+wei[l]*wei[l+1]*wei[r+1];
		p[l][r] = l;
		for(i=l+1; i<r; i++) {
			t = DP(l, i)+DP(i+1, r)+wei[l]*wei[i+1]*wei[r+1];
			if (t<m) {
				m = t;
				p[l][r] = i;
			}
		}
		dp[l][r] = m;
	}
	return dp[l][r];
}
void Print(int l, int r)
{
	int t;
	if (l == r)
		printf("A%d", l+1);
	else {
		t = p[l][r];
		printf("(");
		Print(l, t);
		printf(" x ");    //注意输出的是x，不是*
		Print(t+1, r);
		printf(")");
	}
	return ;
}
int main()
{
	int i, j, n, c = 0;
	while(scanf("%d", &n)>0){
		if (n == 0)
			break;
		c++;
		for(i=0; i<n-1; i++)
			scanf("%d%d", &wei[i], &j);
		scanf("%d%d", &wei[n-1], &wei[n]);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				dp[i][j] = -1;
		for(i=0; i<n; i++)
			dp[i][i] = 0;
		DP(0, n-1);
		printf("Case %d: ", c);
		Print(0, n-1);
		printf("\n");
	}
	return 0;
}