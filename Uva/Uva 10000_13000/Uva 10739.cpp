/*基础题。动规。添加和删除操作是等效的，所以可以只用其中的一种。
 *证明：考虑一个添加操作，在位置p添加一个字符，设它在最终回文串
 *中对称的位置sp，sp上的字符肯定不是添加的，否则去掉p和sp的添加
 *操作，所得仍是回文串，但总操作数减少。这样，将p的添加操作改为
 *sp上的删除操作，总操作数不变。同理，可将删除操作转换为添加操作。
 *下面只考虑删除操作，将一个串s变为回文串，可以删除两端的字符，
 *若两端字符不一样，可将其中一个替换为另一个，若一样，可以不处理
 *它们，然后递给处理剩下的子串。可得状态转移方程，dp(i,j)表示把
 *s[i,j]转换为回文串的操作数，若si=sj，
 *dp(i,j) = min{dp(i+1,j-1), 1+dp(i,j-1), 1+dp(i+1,j)}，否则
 *dp(i,j) = 1+min{dp(i+1,j-1), dp(i,j-1), dp(i+1,j)}*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 45
int dp[NUM][NUM], l;
char str[NUM];
static inline void DP(void)
{
	int i, j, t;
	for(j=1; j<3 && j<l; j++) {
		for(i=0; i+j<l; i++) {
			if (str[i] == str[i+j]) dp[i][i+j] = 0;
			else dp[i][i+j] = 1;
		}
	}
	for(j=3; j<l; j++) {
		for(i=0; i+j<l; i++) {
			t = dp[i+1][i+j-1];
			if (str[i] != str[i+j]) t++;
			if (1+dp[i][i+j-1] < t) t = 1+dp[i][i+j-1];
			if (1+dp[i+1][i+j] < t) t = 1+dp[i+1][i+j];
			dp[i][i+j] = t;
		}
	}
}
int main()
{
	int i, t;
	scanf("%d", &t);
	for(i=0; i<NUM; i++) dp[i][i] = 0;
	for(i=1; i<=t; i++) {
		scanf("%s", str);
		l = strlen(str);
		DP();
		printf("Case %d: %d\n", i, dp[0][l-1]);
	}
	return 0;
}