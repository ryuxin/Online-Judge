/* 中等题。动规。这里用到了整数划分中的一个定理，将n分解成不超过k个数的划分数，
 * 等于将n分解成最大超过k的划分数。具体的证明用到了Ferrers图的性质。更多关于
 * integer partitions 的内容，可以参见Herbert S. Wilf的Lectures on Integer Partitions。
 * 令f(i, j)为将i分解为最大不超过j的划分数。考虑其划分的最大值，有两种可能：选择j或不选。
 * 若选j，其对应的划分数是f(i-j, j)；若不选，则是f(i, j-1)。因此有转移方程：
 * f(i, j) = f(i-j, j) + f(i, j-1)
 * 边界情况：1. 输入中n, l1和l2可能为0；2. l1和l2都可能大于n;
 * 3. 结果很大，需要long long
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <unistd.h>
using namespace std;

#define NUM 303
#define LEN 20
long long sum[NUM][NUM+2];
char str[LEN];
int tn[3];
static inline int
proc(char *s)
{
	int i, r = 0, c = 0;
	for(i=0; s[i] != '\n'; i++) {
		if (s[i] == ' ') {
			tn[r++] = c;
			c = 0;
		} else c = c*10 + s[i] - '0';
	}
	tn[r++] = c;
	return r;
}
int main()
{
	int i, j, k;
	long long r;

	for(i=0; i<=NUM; i++) sum[i][1] = 0;
	for(i=1; i<=NUM; i++) sum[0][i] = 1;
	for(i=1; i<NUM; i++) {
		for(j=2; j<=i+1; j++) sum[i][j] = sum[i-j+1][j] + sum[i][j-1];
		for(; j<=NUM; j++) sum[i][j] = sum[i][j-1];
	}
	while (fgets(str, sizeof(str), stdin)) {
		k = proc(str);
		switch (k) {
		case 1: 
			r = sum[tn[0]][tn[0]+1];
			break;
		case 2:
			if (tn[1] > tn[0]) tn[1] = tn[0];
			r = sum[tn[0]][tn[1]+1];
			break;
		case 3:
			if (tn[2] > tn[0]) tn[2] = tn[0];
			if (tn[1] > tn[0]) tn[1] = tn[0]+1;
			r = sum[tn[0]][tn[2]+1] - sum[tn[0]][tn[1]];
			break;
		}
		printf("%lld\n", r);
	}
	return 0;
}

