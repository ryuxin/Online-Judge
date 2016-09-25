/*入门题。给定一个字符串集合，确定一个字符串，使其与集合中所有字符串的
 *汉明距离之和最小。依次扫描每一位，找到这一位上出现最多的字符，这个就
 *是所求字符串里对应的字符。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 55
#define LEN 1005
char dna[NUM][LEN], re[LEN];
int m, n, num[26];
static inline int solve_col(int col)
{
	int i, ma;
	char mac=0, t;
	num['A'-'A'] = num['C'-'A'] = num['G'-'A'] = num['T'-'A'] = 0;
	ma = 0;
	for(i=0; i<m; i++) {
		t = dna[i][col];
		num[t-'A']++;
		if ((num[t-'A'] > ma) ||
			(num[t-'A'] == ma && t < mac)) {
			ma = num[t-'A'];
			mac = t;
		}
	}
	re[col] = mac;
	return m-ma;
}
static inline int solve(void)
{
	int r=0, i;
	for(i=0; i<n; i++) r += solve_col(i);
	return r;
}
int main()
{
	int t, i, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &m, &n);
		for(i=0; i<m; i++) scanf("%s", dna[i]);
		r = solve();
		re[n] = '\0';
		printf("%s\n%d\n", re, r);
	}
	return 0;
}
