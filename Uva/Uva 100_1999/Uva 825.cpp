/*入门题。动规。dp(i,j)表示从点（i,j）到终点的路径数。若(i, j)有障碍，
  则dp(i, j) = 0。否则，dp(i, j) = dp(i+1, j)+dp(i, j+1)。用滚动数
  组将空间压缩至一维。
  注意输入的数字中可能有多个空格，行尾也可能有空格！！！*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 200
#define LEN 15
bool data[NUM][NUM];
long long int dp[NUM];
char number[3*NUM];
int main()
{
	int i, j, n, w, r, cur, t;
	scanf("%d", &n);
	while(n) {
		scanf("%d %d", &w, &r);
		memset(data, 0, sizeof(data));
		gets(number);
		for(i=0; i<w; ++i) {
			gets(number);
			sscanf(number, "%d", &cur);
			--cur;
			for(j=0; number[j]!='\0'; ++j) {
				if (number[j] != ' ') continue;
				while(number[j] == ' ') {++j;}
				if (number[j] == '\0') break;
				sscanf(number+j, "%d", &t);
				data[cur][--t] = true;
			}
		}
		if (data[w-1][r-1]) dp[r-1] = 0;
		else dp[r-1] = 1;
		cur = w-1;
		for(i=r-2; i>=0; --i) {
			if (data[cur][i]) dp[i] = 0;
			else dp[i] = dp[i+1];
		}
		for(cur=w-2; cur>=0; --cur) {
			if (data[cur][r-1]) dp[r-1] = 0;
			for(i=r-2; i>=0; --i) {
				if (data[cur][i]) dp[i] = 0;
				else dp[i] += dp[i+1];
			}
		}
		printf("%lld\n", dp[0]);
		if (--n) printf("\n");
	}
	return 0;
}