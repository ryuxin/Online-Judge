/*入门题。动规。题目大意，基本题意： 基本串'A'是有效的。假设一个有效的串为O，
  则OAB和BOA都是有效的。给定一个串，判定其是否有效。dp[i][j]表示子串s(i,j)
  是否有效。查看子串的两端和结尾处是否符合规则，若符合则继续递归处理。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1000 
#define LEN 15
char data[NUM];
int dp[NUM][NUM];
int main()
{
	int n, i, j, l;
	scanf("%d", &n);
	while((--n)>=0) {
		scanf("%s", data);
		if (data[1] == '\0') {
			if (data[0] == 'A') printf("SIMPLE\n");
			else printf("MUTANT\n");
			continue;
		}
		l = strlen(data);
		if (l%2 == 0) {
			printf("MUTANT\n");
			continue;
		}
		i = (data[l-2] == 'A' && data[l-1] == 'B');
		i = i || (data[0] == 'B' && data[l-1] == 'A');
		if (!i) {
			printf("MUTANT\n");
			continue;
		}
		for(i=0; i<l; ++i) {
			if (data[i] == 'A') dp[i][i] = 1;
			else dp[i][i] = 0;
			dp[i][i+1] = 0;
		}
		for(j=2; j<l; j=j+2) {
			for(i=0; i+j<l; ++i) {
				if (data[i+j] == 'B' && data[i+j-1] == 'A') {
					if (dp[i][i+j-2] != 0) dp[i][i+j] = 2;
					else dp[i][i+j] = 0;
				}
				else if (data[i] == 'B' && data[i+j] == 'A') {
					if (dp[i+1][i+j-1] != 0) dp[i][i+j] = 3;
					else dp[i][i+j] = 0;
				}
				else dp[i][i+j] = 0;
			}
		}
		switch (dp[0][l-1]) {
		case 0:
			printf("MUTANT\n");
			break;
		case 2:
			printf("FULLY-GROWN\n");
			break;
		case 3:
			printf("MUTAGENIC\n");
		}
	}
	return 0;
}