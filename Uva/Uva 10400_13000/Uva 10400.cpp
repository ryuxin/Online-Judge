/*入门题。动规。本题时限15s，够暴力。所以直接采用动规，dp(i, j)代表只用前i个数，
  是否可以得到j。前i个数的所有结果与第i+1个数进行运算，即可递推出前i+1个数能得
  到的所有结果。题目要求保存路径，所以用path数组保存得到当前结果的操作，而且可
  以省去dp的数组。处理负数的办法就是所有数都加一个偏移。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 32000
#define LEN 105
#define CHECK(x) ((x)>-1*NUM&&(x)<NUM)
int target, n, data[LEN], path[LEN][2*NUM];
void Printpath(int k, int v)
{
	if (k == 0) {
		printf("%d", data[0]);
		return ;
	}
	switch(path[k][v+NUM]) {
	case 1:
		Printpath(k-1, v-data[k]);
		printf("+%d", data[k]);
		return ;
	case 2:
		Printpath(k-1, v+data[k]);
		printf("-%d", data[k]);
		return;
	case 3:
		Printpath(k-1, v/data[k]);
		printf("*%d", data[k]);
		return;
	case 4:
		Printpath(k-1, v*data[k]);
		printf("/%d", data[k]);
	}
}
int main()
{
	int c, i, j, t;
	scanf("%d", &c);
	while((--c)>=0) {
		scanf("%d", &n);
		for(i=0; i<n; ++i) scanf("%d", &data[i]);
		scanf("%d", &target);
		memset(path, 0, sizeof(path));
		path[0][data[0]+NUM] = 1;
		for(i=1; i<n; ++i) {
			for(j=0; j<2*NUM; ++j) {
				if (path[i-1][j] == 0) continue;
				t = j-NUM;
				if (CHECK(t+data[i])) path[i][j+data[i]] = 1;
				if (CHECK(t-data[i])) path[i][j-data[i]] = 2;
				if (CHECK(t*data[i])) path[i][t*data[i]+NUM] = 3;
				if (t%data[i] == 0 && CHECK(t/data[i])) path[i][t/data[i]+NUM] = 4;
			}
		}
		if (path[n-1][target+NUM] == 0) printf("NO EXPRESSION\n");
		else {
			Printpath(n-1, target);
			printf("=%d\n", target);
		}
	}
	return 0;
}