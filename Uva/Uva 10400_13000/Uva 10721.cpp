/*基础题。动规。对于BC(n, k, m)枚举它第一个bar的所有可能宽度，
 *这样将总宽度和bar的数目都减少了，递归处理剩余的宽度。例如，
 *第一个bar宽度是x，剩余的总宽度是n-x，bar的数目是k-1，即
 *BC(n-x, k-1, m)。一些边界条件：
 *第一个bar的宽度最多到m, 即 x <= m；
 *剩余的总宽度能支持剩余的bar的数目，即 n-x >= k-1；
 *总宽度要能被所有bar用完, 即 n <= k*m
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 52
#define LEN 45
long long int dp[NUM][NUM][NUM];
static inline void Initial(void)
{
	int i, j, k, l;
	memset(dp, 0, sizeof(dp));
	for(i=2; i<NUM; i++)        //只有一个bar
		for(k=i; k<NUM; k++)
			dp[i][1][k] = 1;
	for(k=2; k<NUM; k++) dp[3][2][k] = 2;   //总数为3，放两个bar
	for(i=NUM-1; i>0; i--)        //bar的数目和总数相等
		for(j=NUM-1; j>0; j--)
			dp[i][i][j] = 1;
	for(i=4; i<NUM; i++)
		for(j=2; j<i; j++)
			for(k=i/j; k<NUM; k++)
				for(l=i-1; l>=i-k && l>=j-1; l--)
					dp[i][j][k] += dp[l][j-1][k];
}
int main()
{
	int n, k, m;
	Initial();
	while(-1 != scanf("%d%d%d", &n, &k, &m)) {
		printf("%lld\n", dp[n][k][m]);
	}
}