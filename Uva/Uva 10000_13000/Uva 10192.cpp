/*基础题。动归。最长公共子序列*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 105
#define LEN 28
int dp[2][NUM];
char s1[NUM], s2[NUM];
int main()
{
	int l1, l2, c, i, j, t = 0;
	while(gets(s1)) {
		if (s1[0] == '#') break;
		t++;
		gets(s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		for(i=0; i<NUM; i++) dp[0][i] = dp[1][i] = 0;
		c = 1;
		for(i=l1-1; i>=0; i--) {
			for(j=l2-1; j>=0; j--) {
				if (s1[i] == s2[j]) dp[c][j] = dp[1-c][j+1]+1;
				else dp[c][j] = dp[c][j+1]>dp[1-c][j]?dp[c][j+1]: dp[1-c][j];
			}
			c = 1-c;
		}
		printf("Case #%d: you can visit at most %d cities.\n", t, dp[1-c][0]);
	}
	return 0;
}