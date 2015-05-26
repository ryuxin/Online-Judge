/*基础题。动规。无限制背包。dp[i][j]表示从第i个物品开始，填满容量j的背包的
  方法数。对于第i个物品，有两种情况，不放或至少放一个。若不放，方法数为
  dp[i+1][j], 若放，则为dp[i][j-vi], 故转移方程为
  dp[i][j] = dp[i+1][j]+dp[i][j-vi]。用滚动数组优化
  细节，初始化时，容量为0的背包也有一种方法填满。
  由于货币面值不变，可以先计算出所有容量对应的方法数，而不用每次都重新计算一次。
  浮点数精度。输入时，浮点数精度有损失，导致转化为整数后的数值不对，要四舍五入*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 6005
long long int dp[NUM], r;
int v[11] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
int main()
{
	float f;
	int n, i, j;
	for(i=0; i<NUM; i++) dp[i] = 1;
	for(i=9; i>=0; i--) 
		for(j=v[i]; j<NUM; j++)
			dp[j] += dp[j-v[i]];
	while(scanf("%f", &f)>0) {
		if (f == 0) break;
		n = (int)(f*100+0.5);
		if (n%5 != 0) r = 0;
		r = dp[n/5];
		printf("%6.2f%17lld\n", f, r);
	}
	return 0;
}

