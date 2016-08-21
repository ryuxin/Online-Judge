/*典型题。动规+滚动数组。(i, j)表示用i个人保管j个东西, pi为第i个人的能力。错误解法：将安全和工资一起进行动规求解。枚
 *举第i个人保管的物品数，当得到更高的安全时，更新所需的工资。这样的问题是，对应更高安全性的那个工资并不一定是最便宜的
 *。正确解法是对安全和工资分别进行动规，这样的话可得到两个动规方程：
 *safe(i, j) = max(safe(i-1, j), {min(pi/k, safe(i-1, j-k)) | (0<k<=n)})
 *pay(i, j) = min(safe(i-1, j), {pi + safe(i-1, j-k) | (0<k<=L/pi)})，L是最终的安全值。
 *第一次动规求出最终的安全值，第二次动规，在保证实现最高安全的情况下，求出最少的工资。注意求工资时，贪心是不正确的。*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 35
#define LEN 110
int dp[LEN];
int p[NUM];
static inline int mymin(int a, int b) { return a < b ? a : b; }
static inline int mymax(int a, int b) { return a < b ? b : a; }
static int comp(const void *a1, const void *a2)
{
	int *p1 = (int *)a1;
	int *p2 = (int *)a2;
	return *p2-*p1;
}
int main()
{
	int i, j, n, m, k, r1, r2, l;
	while(scanf("%d%d", &n, &m)) {
		if (!n && !m) break;
		for(i=1; i<=m; i++) scanf("%d", &p[i]);
		for(i=1; i<=n; i++) dp[i] = 0;
		dp[0] = 1000000;
		qsort(&p[1], m, sizeof(int), comp);
		for(i=1; i<=m; i++) {
			for(j=n; j>0; j--) {
				for(k=1; k<=j; k++) {
					dp[j] = mymax(dp[j], mymin(p[i]/k, dp[j-k]));
				}
			}
			dp[0] = 0;
		}
		r1 = dp[n];
		for(i=m; i>0; i--) if (p[i]>=r1) break;
		l = i;
		for(i=1; i<=n; i++) dp[i] = 1000000;
		dp[0] = 0;
		if (!r1) {
			printf("%d 0\n", r1);
			continue;
		}
		for(i=1; i<=l; i++) {
			r2 = p[i]/r1;
			for(j=n; j>0; j--) {
				for(k=1; k<=r2 && k<=j; k++) {
					dp[j] = mymin(dp[j], p[i]+dp[j-k]);
				}
			}
		}
		printf("%d %d\n", r1, dp[n]);
	}
	return 0;
}