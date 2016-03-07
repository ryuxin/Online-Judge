/*提高题。动规，平行四边形不等式优化。dp[i][j]表示[i,j]这段区间的最优树，
 *枚举其中的每个节点做为根，取其中的最小值。即：
 *dp[i,j] = min{dp[i,k]+dp[k,j]+w[i,j], i<=k<=j}，root[i,j]为分割[i,j]的k。
 *若状态转移方程是以上形式，且w满足以下条件时：
 *对于i1<i2<j1<j2,有w[i2, j1] < w[i1, j2]和
 *w[i1, j1]+w[i2, j2] < w[i1, j2]+w[i2, j1]。
 *则此时有平行四边形不等式定理：
 *1.dp[i1, j1]+dp[i2, j2] < dp[i1, j2]+dp[i2, j1]
 *2.root[i,j]分别对i，j单调，即root[i,j-1]<root[i,j]<root[i+1,j]
 *详细证明参见《动态规划加速原理 之 四边形不等式》
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 255
#define LEN 47000
int f[NUM], dp[NUM][NUM], n;
int root[NUM][NUM], w[NUM];

int main()
{
	int i, j, l, m, t, r, e;
	memset(dp, 0, sizeof(dp));
	while (1 == scanf("%d", &n)) {
		if (n&1) scanf("%d", &f[0]);
		for(i=n&1; i<n; i=i+2) scanf("%d%d", &f[i], &f[i+1]);
		w[0] = f[0];
		for(i=1; i<n; i++) w[i] = w[i-1]+f[i];
		for(i=0; i<n-1; i++) {
			if (f[i]<f[i+1]) {
				dp[i][i+2] = f[i];
				root[i][i+2] = i+1;
			} else {
				dp[i][i+2] = f[i+1];
				root[i][i+2] = i;
			}
		}
		for(l=3; l<=n; l++) {
			for(i=0; i+l<=n; i++) {
				m = n*n*w[n-1];
				e = root[i+1][i+l];
				for(j=root[i][i+l-1]; j<=e; j++) {
					t = dp[i][j]+dp[j+1][i+l]-f[j];
					if (t<m) {
						m = t;
						r = j;
					}
				}
				dp[i][i+l] = m+w[i+l-1]-w[i-1];
				root[i][i+l] = r;
			}
		}
		printf("%d\n", dp[0][n]);
	}
}