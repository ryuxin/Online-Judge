/* 基础题。动规。典型的编辑距离。设f(i, j)为把x[1..i]转换为y[1..j]的最小
 *值。若x[i] = y[j]，则不需变动这一位，有f(i, j) = f(i-1, j-1)。否则，这
 *一位肯定要花费1的代价，并且三种操作都是可行的，得
 *f(i, j) = 1 + min{f(i-1, j-1), f(i-1, j), f(i, j-1)}
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 1000000007
int dp[NUM][NUM];
char x[NUM], y[NUM];
int main()
{
	int xl, yl, i, j, t;
	while(scanf("%d %s %d %s", &xl, x, &yl, y) != EOF) {
		dp[0][0] = 0;
		for(i=1; i<=xl; i++) dp[i][0] = i;
		for(i=1; i<=yl; i++) dp[0][i] = i;
		for(i=1; i<=xl; i++) {
			for(j=1; j<=yl; j++) {
				if (x[i-1] == y[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					t = dp[i-1][j-1];
					t = min(t, dp[i-1][j]);
					t = min(t, dp[i][j-1]);
					dp[i][j] = t+1;
				}
			}
		}
		printf("%d\n", dp[xl][yl]);
	}
	return 0;
}
