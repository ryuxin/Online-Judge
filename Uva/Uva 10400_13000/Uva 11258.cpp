/*基础题。动态规划。
 1、因为要分成32位的有符号整数，所以一个分割不能太长。32位有符号的最大
 值是2^31-1 = 2147483647。所以一个分割最大长度是10，且要小于2^31。
 2、分割字符串s时，考虑最后分割的位置。由（1）可知，这个位置最多有10种
 选法（保证最后一个分割符合要求）。可得状态转移方程：
 r[i] = max{r[i-l-1]+num(i-l, i) | 0<=l<=10}，其中
 num(i-l, i)表示子串s(i-l, i)组成的数字，r[i]位子串s(0, i)的最大和。
 3、注意边界条件，不是所有长度为10的分割都符合题意。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 205
#define LEN 9
char digit[NUM];
int dp[NUM][LEN+1];
long long int re[NUM];
static inline void __str2num(int s, int l)
{
	long long int t;
	t = (long long int)dp[s][l-1]*10+(digit[s+l]-'0');
	if (t < (1LL<<31)) dp[s][l] = t;
}
static inline long long int __dp(int s, int e)
{
	int i;
	long long int j, m = dp[s][s]+dp[s+1][e];
	for(i=s+1; i<e; i++) {
		j = dp[s][i]+dp[i+1][e];
		if (m<j) m = j;
	}
	return m;
}
int main()
{
	int c, l, i, len;
	long long int t, m;
	scanf("%d", &c);
	while(c--) {
		memset(dp, -1, sizeof(dp));
		scanf("%s", digit);
		l = strlen(digit);
		for(i=0; i<l; i++) dp[i][0] = digit[i]-'0';
		for(i=0; i<l; i++) {
			for(len=1; i+len<l && len<LEN; len++) {
				dp[i][len] = dp[i][len-1]*10 + (digit[i+len]-'0');
			}
		}
		for(i=0; i+LEN<l; i++) __str2num(i, LEN);
		//不必分割，最大和一定是整个字符串构成的一个数字
		for(i=0; i<l && i<LEN; i++) re[i] = (long long int)dp[0][i];
		if (i == LEN && dp[0][i] != -1) re[i++] = (long long int)dp[0][LEN];
		for(; i<l; i++) {
			m = 0;
			for(len=0; len<LEN && i-len>0; len++) {
				t = re[i-len-1]+(long long int)dp[i-len][len];
				if (t > m) m = t;
			}
			if (i-len>0 && dp[i-len][len] != -1) {
				t = re[i-len-1]+(long long int)dp[i-len][len];
				if (t > m) m = t;
			}
			re[i] = m;
		}
		printf("%lld\n", re[l-1]);
	}
	return 0;
}