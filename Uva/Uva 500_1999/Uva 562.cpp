/*基础题。动规，0-1背包。注意初始化和边界情况*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 50005
#define LEN 105
int dp[NUM], data[LEN], n;
void DP(int k)
{
	int i, j;
	dp[0] = dp[data[0]] = 1;        //dp[0] = 1 !!!
	for(i=1; i<n; i++) 
		for(j=k; j>=data[i]; j--) 
			dp[j] |= dp[j-data[i]];
	return ;
}
int main()
{
	int i, t, s;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		s = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &data[i]);
			s += data[i];
		}
		for(i=0; i<=s/2; i++) dp[i] = 0;
		DP(s/2);
		for(i=s/2; i>0; i--) if (dp[i] != 0) break;
		printf("%d\n", s-i-i);
	}
	return 0;
}