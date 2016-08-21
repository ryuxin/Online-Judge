/*基础题。动规。求一个字符串中，所有构成回文的子序列的个数。dp[i][j]表示字串s(i, j)中回文子序列的个数。考虑
 *字符s[j]，若其没有被使用，则个数为dp[i][j-1]；若被使用，则其前面一定要有一个字符与其配对，枚举s(i, j)中
 *所有与s[j]相同的字符，假设s[k] = s[j]， 则由k，j配对构成的回文数目是dp[k+1][j-1]+1*，加1是因为k，j本身。
 *综上，动规方程dp[i][j] = dp[i][j-1]+sum{1+dp[k+1][j-1] | s[k] = s[j]}*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 65
#define LEN 110
long long int dp[NUM][NUM];
char str[NUM];
int main()
{
	int t, i, j, l, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", str);
		l = strlen(str);
		memset(dp, 0, sizeof(dp));
		for(i=0; i<l; i++) dp[i][i] = 1;
		for(j=1; j<l; j++) {
			for(i=0; i+j<l; i++) {
				dp[i][i+j] = dp[i][i+j-1];
				for(k=i; k<=i+j; k++) {
					if (str[k] == str[i+j]) dp[i][i+j] += (1+dp[k+1][i+j-1]);
				}
			}
		}
		printf("%lld\n", dp[0][l-1]);
	}
	return 0;
}