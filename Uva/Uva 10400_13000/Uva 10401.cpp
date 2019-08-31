/*基础题。动规，状态压缩。stat[i]表示第i列的状态，如果第k
 *位是1，则表示第k行可以放棋子。先进行预处理，求出每一列
 *的状态。dp[i][j]表示第i列的状态为j，且i+1到n列满足输入
 *条件时，摆放棋子的方法数目。则最终答案为dp[1][stat[i]]。
 *状态转移方程：对于状态j，考虑其最低位的1，有两种可能性，
 *即在该行放棋子或不放。若放棋子，对应的方法数为
 *dp[i+1][stat[i+1] & C(j)], 其中C(j)表示该棋子对下一列
 *的影响；若不放，对应的方法数为dp[i][j & j-1], j & j-1
 *为j中去掉最低位的1后剩余部分。时间复杂度最差为O(n2^n)。
 *边界条件：dp[n+1][j] = 1。
 *另外注意输入中有空行！！
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
using namespace std;

#define NUM 18
#define LEN (1<<15)
char str[NUM];
long long dp[2][LEN];
int stats[NUM], tot;
static inline int
c2i(char c)
{
	if (c>='0' && c<='9') return c-'0'-1;
	else return c-'A'+9;
}
static inline int
cover(int t)
{
	t = t | (t<<1) | (t>>1);
	return tot & (~t);
}
static inline long long
preporc(char *s, int len)
{
	int i, t, k;
	memset(stats, -1, sizeof(stats));
	for(i=1; i<=len; i++) {
		if (str[i-1] == '?') {
			stats[i] &= tot;
		} else {
			t = c2i(str[i-1]);
			stats[i] &= (1<<t);
			k = cover(1<<t);
			stats[i-1] &= k;
			stats[i+1] &= k;
		}
	}
	for(i=1; i<=len; i++) {
		if (!stats[i]) return 0;
	}
	return 1;
}

static inline long long
DP(int len)
{
	int i, j, t, k, n, ii;
	long long r;
	for(j=1; j<=stats[len]; j++) {
		t = j & stats[len];
		for(r=0, k=0; k<len; k++) {
			if (t &(1<<k)) r++;
		}
		dp[len%2][j] = r;
	}
	for(i=len-1; i>0; i--) {
		k = stats[i] & (-stats[i]);
		for(ii=i%2, j=k; j<=stats[i]; j+=k) {
			t = j & stats[i];
			if (t == j) {
				n = cover(t&(-t));
				dp[ii][j] = dp[1-ii][stats[i+1]&n] + dp[ii][t&(t-1)];
			}
		}
		if (dp[ii][stats[i]] == 0) return 0;
	}
	return dp[1][stats[1]];
}
int main()
{
	int l;
	long long r;
	dp[1][0] = dp[2][0] = 0;
	while (fgets(str, sizeof(str), stdin)) {
		l = strlen(str) - 1;
		if (l<1) continue;
		tot = (1<<l) - 1;
		r = preporc(str, l);
		if (r) r = DP(l);
		printf("%lld\n", r);
	}
	return 0;
}
