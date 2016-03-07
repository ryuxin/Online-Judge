#include "ryx_bignum.h"
/*基础题。大整数动规。dp[i][j]表示z[0..j]在x[0..i]中出现的
 *次数。如果z[j] == x[i], dp[i][j] = dp[i-1][j]+dp[i-1][j-1],
 *否则dp[i][j] = dp[i-1][j]。由于字符串很长，要用到大整数
 *加法。因此，空间开销比较大，用滚动数组将空间降到一维。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 10005
BigNum dp[NUM];
char total[LEN], sub[NUM];
void DP(int l1, int l2)
{
	int i, j;
	LinttoBigNum(1, &dp[0]);
	for(j=0; j<l1; j++) {
		for(i=l2; i>0; i--) {
			if (total[j] == sub[i-1])
				Unsign_plus(&dp[i-1], &dp[i], &dp[i]);
		}
	}
}
int main()
{
	int n, l1, l2, i;
	scanf("%d", &n);
	while(n--) {
		scanf("%s%s", total, sub);
		l1 = strlen(total);
		l2 = strlen(sub);
		for(i=0; i<=l2; i++) 
			Initial(&dp[i]);
		DP(l1, l2);
		Print_BigNum(&dp[l2]);
		printf("\n");
	}
	return 0;
}
