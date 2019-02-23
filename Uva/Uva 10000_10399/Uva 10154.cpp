/*
 *中等题。贪心，动规。
 *设乌龟从下到上为t0，t1，...，tn，对应的自身重量为w0，w1，...，wn，载重量为s0，s1，...，sn，
 *上面所有乌龟的重量为W0，W1，...，Wn，则应有对任意i，wi + Wi <= si。
 *贪心性质：一定存在最优排列，使得s0 >= s1 >= ... >= sn。
 *证明：只需考虑相邻的乌龟。若在最优排列中有 si < si+1，交换它们后仍得到一个最优排列，因为
 *Wi + wi <= si < si+1， 且Wi+1 + wi < Wi + wi <= si
 *先将输入按载重量排序，然后动规。
 *dp(i, j)表示从i到n的乌龟中选出j个组成排列，它们重量之和的最小值。则状态转移方程：
 *如果wi + dp(i+1, j-1) <= si dp(i, j) = min{wi + dp(i+1, j-1), dp[(i+1, j)}；
 *否则： dp(i, j) = dp(i+1, j)。
 *若不存在满足条件的排列，则dp(i, j) = MAX。最终答案为最大的j，使得dp(i, j) != MAX。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>   
#include <vector>
using namespace std;

#define NUM 6000
#define LEN 10000
struct Tutel {
	int w, c;
};
int dp[2][NUM];
struct Tutel data[NUM];
static int
comp(const void *a1, const void *a2)
{
	struct Tutel *p1 , *p2;
	p1 = (struct Tutel *)a1;
	p2 = (struct Tutel *)a2;
	return p2->c - p1->c;
}
int main()
{
	int i, j = 0, tot = 0, a, b, c = 1, s = 0;
	while (scanf("%d %d", &a, &b) != EOF) {
		s += a;
		data[tot].w = a;
		data[tot].c = b;
		tot++;
	}
	qsort(data, tot, sizeof(struct Tutel), comp);
	dp[0][0] = dp[1][0] = 0;
	for(i=1; i<=tot; i++) dp[0][i] = dp[1][i] = s*2;
	for(i=tot-1; i>=0; i--) {
		for(j=1; j<=tot-i; j++) {
			dp[c][j] = dp[1-c][j];
			b = data[i].w + dp[1-c][j-1];
			if (b <= data[i].c) dp[c][j] = min(dp[c][j], b);
		}
		c = 1-c;
	}
	for(j=tot; j>=0; j--) {
		if (dp[1-c][j] <= s) {
			printf("%d\n", j);
			break;
		}
	}
	return 0;
}
