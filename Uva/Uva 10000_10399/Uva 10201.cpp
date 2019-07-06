/*基础题。动规。
 *基本的状态及其转移方程比较直观。dp(i, j)表示在第i个加油站且有j升油时，到达目的地需要的最少费用。
 *我们可以选择不加油，或加1，2，，升，直到加满，因此可得方程
 *if j < 0: dp(i, j) = MAX；
 *else if i == n: dp(i, j) = 0；
 *else dp(i, j) = Min{k*pi + dp(i+1, j+k-di) | 0 <= k <= N-j}
 *其中pi是价格，di是i到i+1的距离，N是油箱容量。复杂度O（n^3）。
 *优化：观察dp可得
 *dp(i, j)   = Min{ dp(i+1, j-di), Min{k*pi + dp(i+1, j+k-di) | 1 <= k <= N-j} }，而
 *dp(i, j+1) = Min{k*pi + dp(i+1, j+k-di+1) | 0 <= k <= N-j-1}，令k' = k+1，得
 *dp(i, j+1) = Min{k'*pi - pi + dp(i+1, j+k'-di) | 1 <= k' <= N-j}
 *           = Min{k'*pi + dp(i+1, j+k'-di) | 1 <= k' <= N-j} - pi
 *将其带入dp(i, j)，有 dp(i, j) = Min{ dp(i+1, j-di), dp(i, j+1)+pi }
 *将复杂度降为O(n^2)。
 *边界问题：题目要求到达目的地时至少有半箱油，将到目的地的距离向后延长100即可。
 *同一地点可能有多个加油站，只保留价格最低的即可。
 *目的地后面可能也有加油站，题目表述不清楚，目前看来这些节油站可直接忽略。
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

#define NUM 200
#define LEN 210
#define NL 20
struct Tutel {
	int d, p;
};
int dp[2][LEN];
struct Tutel data[LEN];
static inline int
calc(int j, int d, int c)
{
	int t = j - d;
	if (t < 0) return -1;
	return dp[c][t];
}
int main()
{
	int ti, i, j, t, c;
	int tot, kase=1, di;
	char tn[NL], *r;

	data[0].d = data[0].p = 0;
	fgets(tn, NL, stdin);
	kase = atoi(tn);
	fgets(tn, NL, stdin);
	for(tot = 1, ti=0; ti<kase; ti++) {
		fgets(tn, NL, stdin);
		t = atoi(tn);
		while (1) {
			r = fgets(tn, NL, stdin);
			if (!r || tn[0] == '\n') break;
			for(i=0; i<10; i++) {
				if (tn[i] == ' ') {
					data[tot].d = atoi(tn);
					data[tot].p = atoi(tn+i+1);
					break;
				}
			}
			if (data[tot].d <= t && data[tot].d > data[tot-1].d) tot++;
			else if (data[tot].d == data[tot-1].d) {
				if (data[tot].p < data[tot-1].p) data[tot-1].p = data[tot].p;
			}
		}
		data[tot].d = t+NUM/2;
		data[tot].p = 0;
		memset(dp[0], 0, sizeof(int)*LEN);
		for(c=1, i=tot-1; i>=1; i--) {
			di = data[i+1].d - data[i].d;
			dp[c][NUM] = calc(NUM, di, 1-c);
			for(j=NUM-1; j>=0; j--) {
				dp[c][j] = calc(j, di, 1-c);
				t = dp[c][j+1];
				if (t >= 0) {
					if (dp[c][j] == -1) dp[c][j] = t + data[i].p;
					else dp[c][j] = min(dp[c][j], t + data[i].p);
				}
			}
			c = 1 - c;
		}
		t = NUM/2-data[1].d;
		if (t < 0 || dp[1-c][t] == -1) printf("Impossible\n");
		else printf("%d\n", dp[1-c][t]);
		if (ti < kase-1) printf("\n");
	}
	return 0;
}
