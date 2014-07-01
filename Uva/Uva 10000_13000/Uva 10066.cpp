/*基础题。基础动规。题目有歧义。最长公共子序列。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 105
#define LEN 105
int d1[NUM], d2[NUM], high[2][NUM];
int main()
{
	int n1, n2, i, j, c = 1, t;
	while(scanf("%d %d", &n1, &n2) > 0) {
		if (n1 == 0 && n2 == 0) break;
		for(i=0; i<n1; i++) scanf("%d", &d1[i]);
		for(i=0; i<n2; i++) scanf("%d", &d2[i]);
		for(i=0; i<=n2; i++) 
			high[0][i] = high[1][i]= 0;
		t = 1;
		for(i=n1-1; i>=0; i--) {
			for(j=n2-1; j>=0; j--) {
				if (d1[i] == d2[j]) {
					high[t][j] = 1+high[1-t][j+1];
					continue;
				}
				if (high[1-t][j] > high[t][j+1]) 
					high[t][j] = high[1-t][j];
				else high[t][j] = high[t][j+1];
			}
			t = 1-t;
		}
		printf("Twin Towers #%d\n", c);
		printf("Number of Tiles : %d\n\n", high[1-t][0]);
		c++;
	}
	return 0;
}