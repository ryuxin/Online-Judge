/*基础题。动态规划，字符串处理。如果两个字符串的编辑距离是1，则他俩可以
 *互相变换。判断两个字符串的编辑距离是否为1，首先的他们的长度至多相差1；
 *若长度相等，则只能通过改变一个字符进行变换；若相差1，则只能添加或删除
 *一个字符（二者是等价的，只需考虑一种方式）。
 *基本思路和最长上升子序列相似：dp[i]表示以i结尾的，最长编辑子序列长度。
 *求dp[i]时，查找0 - i-1中和i编辑距离为1的字符串，并取他们的最大值。
 *这里有两种思路：
 *1、遍历前面的所有的字符串，依次判断是否和i的编辑距离为1。
 *2、枚举i的所有变换（这些变换一定和i的编辑距离为1），并（二分）查找这
 *些变换是否在前面出现过。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 25005
#define LEN 18
#define THROD 1
char dict[NUM][LEN];
int dp[NUM], len[NUM];

static inline bool
edit_step(int s, int e)
{
	int l1 = len[s], l2 = len[e], i, d=0, j;
	char *c1 = dict[s], *c2 = dict[e];
	if (l1-l2>1 || l2-l1>1) return false;
	if (l2>l1) {
		l1 = l2;
		l2 = len[s];
		c1 = c2;
		c2 = dict[s];
	}
	if (l1 == l2) {
		for(i=0; i<l1; i++) {
			if (c1[i] != c2[i]) {
				d++;
				if (d>1) return false;
			}
		}
		return true;
	}
	for(i=0; i<l2; i++) {
		if (c1[i] != c2[i]) {
			for(j=i+1; i<l2; i++, j++) {
				if (c1[j] != c2[i]) return false;
			}
		}
	}
	return true;
}
static inline void
DP_linear(int idx)
{
	int i, m=0;
	for(i=0; i<idx; i++) {
		if (edit_step(i, idx)) {
			if (dp[i] > m) m = dp[i];
		}
	}
	dp[idx] = m+1;
}
static inline int
binary_search(int e, char *s)
{
	int m, l=0, r=e, d;
	if (strcmp(dict[e], s) < 0) return -1;
	if (strcmp(dict[0], s) > 0) return -2;
	while (l<=r) {
		m = l+(r-l)/2;
		d = strcmp(dict[m], s);
		if (d == 0) return m;
		else if (d>0) r = m-1;
		else l = m+1;
	}
	return -2;
}
static inline void
DP_binary(int idx)
{
	char vary[LEN], *p = dict[idx], ci, ti;
	int i, j, m=0, l=len[idx], r;
	//添加
	memcpy(&vary[1], p, l+1);
	for(i=0; i<=l; i++) {
		for(ci='a'; ci<='z'; ci++) {
			vary[i] = ci;
			r = binary_search(idx-1, vary);
			if (r>=0) {
				if (dp[r] > m) m = dp[r];
			} else if (r == -1) break;
		}
		vary[i] = vary[i+1];
	}
	//删除
	for(i=l-1; i>=0; i--) {
		memcpy(&vary[i], &p[i+1], l-i);
		r = binary_search(idx-1, vary);
		if (r>=0) if (dp[r] > m) m = dp[r];
	}
	//替换
	for(i=0; i<l; i++) {
		for(ci='a'; ci<='z'; ci++) {
			ti = p[i];
			p[i] = ci;
			r = binary_search(idx-1, p);
			p[i] = ti;
			if (r>=0) {
				if (dp[r] > m) m = dp[r];
			} else if (r == -1) break;
		}
	}
	dp[idx] = m+1;
}
static inline void
DP(int idx)
{
	if (idx < THROD) DP_linear(idx);
	else DP_binary(idx);
}
int main()
{
	int i=0, m=0;
	while (scanf("%s", dict[i]) != EOF) {
		len[i] = strlen(dict[i]);
		DP(i);
		if (dp[i] > m) m = dp[i];
		i++;
	}
	printf("%d\n", m);
	return 0;
}