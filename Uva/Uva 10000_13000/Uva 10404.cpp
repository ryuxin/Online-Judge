/*入门题。动规。基本的博弈题。若先手赢，则至少存在一种方式，使得
  后手输。若先手输，则先手的每一种方式都是后手赢。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1000005 
#define LEN 15
int dp[NUM], data[LEN], m;
int DP(int k)
{
	int i;
	if (dp[k] == -1) {
		for(i=0; i<m; ++i) {
			if (k>data[i] && DP(k-data[i])) {
				dp[k] = 0;
				break;
			}
		}
		if (i == m) dp[k] == 1;
	}
	return dp[k];
}
int main()
{
	int n, i, j;
	while(scanf("%d", &n)>0) {
		scanf("%d", &m);
		for(i=0; i<m; ++i) scanf("%d", &data[i]);
		for(i=0; i<m; ++i) dp[data[i]] = 0;
		dp[0] = 1;
		for(i=2; i<=n; ++i) {
			for(j=0; j<m; ++j) {
				if (data[j]<=i && dp[i-data[j]]) {
					dp[i] = 0;
					break;
				}
			}
			if (j == m) dp[i] = 1;
		}
		if (dp[n] == 0) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}