/*基础题。动规。令dp(i,j)表示从数组i到j中，先手能得到的最大差值。由于
 *先手有两种策略，即从左或从右开始拿，因此进一步令dp(i,j,0)和dp(i,j,1)
 *分别表示从左边和右边开始拿所对应的最大差值。则有：
 *dp(i,j) = Max{dp(i,j,0), dp(i,j,1)} ........... #1;
 *下面以从左边拿为例。从左边开始拿，也可以分为两种策略，只拿一个数和大
 *于一个数。若只拿一个数，则下次后手变为先手，就要减去后手的得分，即
 *S1 = num[i] - dp(i+1, j) ...................... #2;
 *若拿多余一个数，则拿完第一个数之后，还是先手，但继续从i+1开始拿，即
 *S2 = num[i] + dp(i+1, j, 0) ................... #3；综上既得
 *dp(i, j, 0) = Max{S1, S2} ..................... #4;
 *同理，可求得dp(i, j, 1)，一起联立以上4式，可得完整的状态转移方程。
 *时间和空间复杂度都是O(n^2)。
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

#define NUM 102
#define LEN (1<<15)
long dp[NUM][NUM][2], num[NUM];
static inline void
DP(int len)
{
	int i, j;
	for(i=0; i<len; i++) {
		dp[i][i][0] = dp[i][i][1] = num[i];
	}
	for(j=1; j<len; j++) {
		for(i=0; i+j<len; i++) {
			dp[i][i+j][0] = max(num[i]+dp[i+1][i+j][0], 
								num[i]-max(dp[i+1][i+j][0], dp[i+1][i+j][1]));
			dp[i][i+j][1] = max(num[i+j]+dp[i][i+j-1][1], 
								num[i+j]-max(dp[i][i+j-1][0], dp[i][i+j-1][1]));
		}
	}
}
int main()
{
	int n, i;
	while (scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) scanf("%ld", num+i);
		DP(n);
		printf("%ld\n", max(dp[0][n-1][0], dp[0][n-1][1]));
	}
	return 0;
}
