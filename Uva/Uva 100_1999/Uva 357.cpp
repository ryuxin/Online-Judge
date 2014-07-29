/*基础题。动规。无限制背包。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 30005 
#define LEN 25
long long int dp[NUM];
int data[5] = {1, 5, 10, 25, 50};
int main()
{
	int i, j;
	for(i=0; i<NUM; i++) dp[i] = 1;
	for(i=1; i<5; i++)
		for(j=data[i]; j<NUM; j++)
			dp[j] += dp[j-data[i]];
	while(scanf("%d", &j)>0) {
		if(dp[j] != 1) printf("There are %lld ways to produce %d cents change.\n", dp[j], j);
		else printf("There is only 1 way to produce %d cents change.\n", j);
	}
	return 0;
}