/*基础题。动规，最长上升子序列。题目大意，给出每个事件在正确排序中
  的位置，并给出学生答案中每个事件出现的位置，求其最长上升子序列。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int rank[25], data[25], dp[25];
int main()
{
	int n, i, j, best;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &j);
		rank[i+1] = j;
	}
	while(scanf("%d", &j)>0) {
		data[j] = 1;
		for(i=1; i<n; i++) {
			scanf("%d", &j);
			data[j] = i+1;
		}
		dp[1] = 1;
		for(i=2; i<=n; i++) {
			best = 0;
			for(j=1; j<i; j++)
				if (rank[data[i]]>rank[data[j]] && dp[j]>best)
					best = dp[j];
			dp[i] = best+1;
		}
		best = dp[1];
		for(i=2; i<=n; i++)
			if (dp[i]>best)
				best = dp[i];
		printf("%d\n", best);
	}
	return 0;
}