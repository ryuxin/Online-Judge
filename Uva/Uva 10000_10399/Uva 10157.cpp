#include "ryx_bignum.h"
/*入门题。数学，排列组合+大整数。若A=(B)，称A为一个部分，则每个串都由多个部分构成。
 *dp(n, d)为用n个括号，深度为d串的数目，sum(n, d)为用n个括号，深度小于等于d的数目
 *之和。枚举串的第一个部分所用的括号数目(2, 4, ..., n)。设其用了k个括号，则有两种
 *情况：1.第一部分的深度小于d，这时后面剩余的括号深度必须为d。第一部分的方法数为
 *sum(k-2, d-2)(去除最外面的括号，里面的深度小于d-1)，剩余括号的方法数是dp(n-k, d)；
 *2.第一部分的深度等于d，则后面括号的深度就可以小于等于d，方法数分别为dp(k, d)和
 *sum(n-k, d)。综上，最终的方法数为
 *dp(n, d) = Sum{sum(k-2, d-2)*dp(n-k, d)+dp(k, d)*sum(n-k, d) | 2<=k<=n}
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 300
#define LEN 160
BigNum dp[NUM+10][LEN], sum[NUM+10][LEN], mul;
int main()
{
	int i, j, k, n, d;
	for(i=0; i<NUM+10; i += 2) for(j=0; j<LEN; j++) LinttoBigNum(0, &dp[i][j]);
	for(i=0; i<=NUM; i += 2) LinttoBigNum(1, &dp[i][i/2]);
	for(i=2; i<=NUM; i += 2) LinttoBigNum(1, &dp[i][1]);
	for(i=2; i<=NUM; i += 2) LinttoBigNum(0, &sum[i][0]);
	LinttoBigNum(1, &sum[0][0]);
	for(i=1; i<LEN; i++) LinttoBigNum(1, &sum[0][i]);
	for(i=1; i<LEN; i++) LinttoBigNum(1, &sum[2][i]);
	for(i=4; i<=NUM; i += 2) {
		for(j=2; j<i/2; j++) {
			for(k=2; k<=i; k += 2) {
				Initial(&mul);
				Unsign_mul(&sum[k-2][j-2], &dp[i-k][j], &mul);
				Unsign_plus(&mul, &dp[i][j], &dp[i][j]);
			}
			for(k=j*2; k<=i; k += 2) {
				Initial(&mul);
				Unsign_mul(&dp[k-2][j-1], &sum[i-k][j], &mul);
				Unsign_plus(&mul, &dp[i][j], &dp[i][j]);
			}
		}
		for(j=1; j<LEN; j++) Unsign_plus(&sum[i][j-1], &dp[i][j], &sum[i][j]);
	}
	while(EOF != scanf("%d%d", &n, &d)) {
		Print_BigNum(&dp[n][d]);
		printf("\n");
	}
	return 0;
}