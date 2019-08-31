/*基础题。动规。本题有一点不容易理解：对于一个区间，放置好第一个仓库后，
 *放置第二个仓库时，这两个仓库之间的饭店离谁最近是不确定的，且随第二个
 *仓库的位置变化而变化。令c(i, j)表示当i和j分别有仓库，[i, j]之间的饭店
 *到最近仓库的距离和，dp(i, j)表示当i-1的位置上面有仓库是，在[i, n]之间
 *放j个仓库，[i, n]之间的饭店到最近仓库的距离和。在0点放一个虚拟的饭店
 *和仓库，且其距离其他饭店为无穷大。则题目为求解dp(1, k)。状态转移方程：
 *dp(i, j) = Min{c(i-1, k) + dp(k+1, j-1) | i<=k<=n-j+1} (j>0), 边界条件
 *dp(i, 0) = Sum{dis(i-1, k) | i<=k<=n}, dis(a, b)位ab之间的距离。
 *上面的思路是枚举[i, n]之间第一个仓库的位置(k), 则i到k之间饭店的距离和
 *为c(i-1, k)，而k后面的饭店距离和构成一个动规的子问题dp(k+1, j-1)。
 *动规中间保存第一个仓库的位置以用于打印路径。时间复杂度O(n^3)。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define NUM 205
#define LEN 35
int dp[NUM][LEN], dis[NUM], pos[NUM][LEN], cost[NUM][NUM];
static inline int
Mid(int a, int b)
{
	int i;
	for(i=b; i>=a; i--) {
		if (dis[i]-dis[a] < dis[b] - dis[i]) break;
	}
	return i;
}
static inline void
DP(int m, int k, int n)
{
	int i, re=INT_MAX, r, p;
	for(i=m; i<=n && i<=n-k+1; i++) {
		r = cost[m-1][i] + dp[i+1][k-1];
		if (r<re) {
			p  = i;
			re = r;
		}
	}
	dp[m][k]  = re;
	pos[m][k] = p;
}
static inline void
Print(int n, int k, int tot)
{
	int p1, p2, e, r = 1, p=0, s;
	while (k) {
		p1 = pos[n][k];
		p2 = pos[p1+1][k-1];
		if (r == 1) s = 1;
		else s = Mid(p, p1)+1;
		if (k == 1) e = tot;
		else e = Mid(p1, p2);
		if (s != e) {
			printf("Depot %d at restaurant %d serves restaurants %d to %d\n", r, p1, s, e);
		} else {
			printf("Depot %d at restaurant %d serves restaurant %d\n", r, p1, s);
		}
		k--, r++;
		p = p1, n = p1+1;
	}
}
int main()
{
	int i, n, k, ii, j, c=1;
	while (1) {
		scanf("%d %d", &n, &k);
		if (n == 0) break;
		for(i=1; i<=n; i++) scanf("%d", dis+i);
		for(i=n; i>0; i--) dis[i] -= dis[1];
		dis[0] = -1-dis[n];
		memset(cost, 0, sizeof(cost));
		for(i=0; i<=n; i++) {
			for(j=i; j<=n; j++) {
				for(ii=i; ii<=j; ii++) {
					cost[i][j] += min(dis[ii]-dis[i], dis[j]-dis[ii]);
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		for(i=n; i>0; i--) {
			for(j=i; j<=n; j++) {
				dp[i][0] += (dis[j] - dis[i-1]);
			}
		}
		for(i=n; i>0; i--) {
			for(j=1; j<=k && j<=n-i+1; j++) {
				DP(i, j, n);
			}
		}
		printf("Chain %d\n", c++);
		Print(1, k, n);
		printf("Total distance sum = %d\n\n", dp[1][k]);
	}
	return 0;
}
