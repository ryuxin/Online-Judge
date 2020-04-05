/*基础题。动规。dp(i, j, k)表示从(i, j)开始到最下面，和为k的不同路径数目。另c为(i, j)上的数值，则
 *状态转移方程为dp(i, j, k) = dp(i+1, j, k-c) + dp(i+1, j+1, k-c)。需要注意的是：
 *1. 棋盘的上下部分不一样，要分别计算；
 *2. 用滚动数组优化空间；
 *3. 另用一个数组保持路径，由于左侧的路径值小，所以先判读右侧，再判断左侧；
 *4. 处理好边界情况，详见注释里的bug；
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
#include <climits>
using namespace std;

#define NUM 50
#define LEN 505
long long int dp[2][NUM][LEN];
int num[NUM][NUM], col[NUM];
char path[NUM][NUM][LEN];
static inline void
Print(int a, int s, int n)
{
	int i;
	char t;
	for(i=0; i<n-1; i++) {
		t = path[i][a][s];
		printf("%c", t);
		s -= num[i][a];
		if (t == 'L') a--;
	}
	for(; i<2*n-2; i++) { // old bug: i<2*n-1 !!
		t = path[i][a][s];
		printf("%c", t);
		s -= num[i][a];
		if (t == 'R') a++;
	}
	printf("\n");
}
int main()
{
	int n, s, i, j, r, k, t;
	long long int re;
	int dbg = 0;
	while(1) {
		scanf("%d %d", &n, &s);
		if (!n) break;
		memset(dp, 0, sizeof(dp));
		r = 2*n-2;
		for(i=0; i<n; i++) {
			col[i] = n-i+1;
			for(j=1; j<=n-i; j++) scanf("%d", &num[i][j]);
		}
		for(; i<=r; i++) {
			col[i] = i-n+3;
			for(j=1; j<=i-n+2; j++) scanf("%d", &num[i][j]);
		}
		for(i=1; i<col[r]; i++) dp[r%2][i][num[r][i]] = 1;
		for(i=r-1; i>=n-1; i--) {
			for(j=1; j<col[i]; j++) {
				for(k=0; k<=s; k++) dp[i%2][j][k] = 0;  // **
				for(k=num[i][j]; k<=s; k++) {
					t = k-num[i][j];
					if (dp[(i+1)%2][j+1][t] > 0) {
						dp[i%2][j][k] += dp[(i+1)%2][j+1][t];
						path[i][j][k] = 'R';
					}
					if (dp[(i+1)%2][j][t] > 0) {
						dp[i%2][j][k] += dp[(i+1)%2][j][t];
						path[i][j][k] = 'L';
					}
				}
			}
		}
		for(; i>=0; i--) {
			for(j=1; j<col[i]; j++) {
				for(k=0; k<=s; k++) dp[i%2][j][k] = 0; // **
				for(k=num[i][j]; k<=s; k++) {
					t = k-num[i][j];
					// ** bug2: 滚动数组要确保没有上一轮残留下的值，和上一轮没有更新的值
					// 比如，要先将本轮的值清零，否则就是在上一轮的基础上继续累加，或者下一轮看不到本轮应该是0的值
					// 再如，本轮更新j时，可能上一轮的一行根本没有j，所以要加判断j是否在上一轮的范围内。
					if (j < col[i+1] && dp[(i+1)%2][j][t] > 0) {
						dp[i%2][j][k] += dp[(i+1)%2][j][t];
						path[i][j][k] = 'R';
					}
					if (dp[(i+1)%2][j-1][t] > 0) {
						dp[i%2][j][k] += dp[(i+1)%2][j-1][t];
						path[i][j][k] = 'L';
					}
				}
			}
		}
		for(i=1, re=0; i<=n; i++) re += dp[0][i][s];
		for(i=1; i<=n; i++) {
			if (dp[0][i][s] > 0) {
				printf("%lld\n%d ", re, i-1);
				Print(i, s, n);
				break;
			}
		}
		if (i>n) printf("0\n\n");
	}
	return 0;
}
