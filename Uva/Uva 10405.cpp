/*基础题。基础动规，最长公共子序列，采用空间优化。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 2
#define LEN 1010
char data[NUM][LEN];
int dp[NUM][LEN];
int main()
{
	int i, j, l1, l2;
	dp[1][0] = dp[0][0] = 0;
	while (gets(data[0]) != NULL) {
		gets(data[1]);
		l1 = strlen(data[0]);
		l2 = strlen(data[1]);
		for(i=1; i<=l2; i++)
			dp[0][i] = 0;
		for(i=1; i<=l1; i++) {
			for(j=1; j<=l2; j++) {
				if (data[0][i-1] == data[1][j-1])
					dp[i%2][j] = 1+dp[(i-1)%2][j-1];
				else 
					dp[i%2][j] = dp[i%2][j-1]>dp[(i-1)%2][j]?dp[i%2][j-1]:dp[(i-1)%2][j];
			}
		}
		printf("%d\n", dp[l1%2][l2]);
	}
	return 0;
}	