/*基础题。动规，物品数目无限制的背包问题。dp[i][j]表示前i个物品
  组成容量为j的方法数。对应第i个物品，有两种选择，放或不放。若
  放，背包容量变为j-wi，由于物品数量无限制，所以此时前i个物品仍
  然可以随便选，故得dp[i][j] = max{dp[i-1][j], dp[i][j-wi]}。
  注意，若物品数量有限制，则方程不成立。因为放一个i物品后，剩余
  的i物品的数量限制就变了（减小了），问题的状态也就变了。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 7500
#define LEN 5
int dp[NUM], coin[LEN] = {1, 5, 10, 25, 50};
int main()
{
	int i, j;
	for(i=0; i<NUM; i++)
		dp[i] = 1;
	for(i=1; i<LEN; i++) 
		for(j=coin[i]; j<NUM; j++) 
			dp[j] = dp[j]+dp[j-coin[i]];
	while(scanf("%d", &i)>0) {
		printf("%d\n", dp[i]);
	}
	return 0;
}	