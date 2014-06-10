/*基础题。基础动规。dp[i][j]表示从i个割点到第j个的最小代价。
  状态方程dp[i][j] = len(i,j)+min{dp[i][k], dp[k][j]}(i<k<j)。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 55
#define LEN 50
int dp[NUM][NUM], data[NUM];
int main()
{
	int i, j, l, n, m, k;
	data[0] = 0;
	while(scanf("%d", &l)>0) {
		if (l == 0) break;
		scanf("%d", &n);
		for(i=1; i<=n; i++) scanf("%d", &data[i]);
		data[n+1] = l;
		dp[0][n+1] = 0;
		for(i=0; i<=n; i++) dp[i][i+1] = 0;
		for(j=2; j<n+2; j++) {
			for(i=0; i+j<n+2; i++) {
				m = 10000;
				for(k=i+1; k<j+i; k++) 
					if (dp[i][k]+dp[k][i+j]<m)
						m = dp[i][k]+dp[k][i+j];
				dp[i][i+j] = m+data[i+j]-data[i];
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n+1]);
	}
	return 0;
}