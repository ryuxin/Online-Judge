/*基础题。枚举。根据题意，先用差值计算出可能的原数
 *组。再枚举所有可能的数组长度进行判断，判断标准是，
 *对于长度l，任意i有 x[i] = s[i % l]。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>   
#include <vector>
using namespace std;

#define NUM 1005
#define LEN 505
int data[NUM], re[NUM];
static inline int
mmax(int a, int b)
{ return a > b? a: b; }
int main()
{
	int i, n, l, tot=0;
	scanf("%d", &n);
	for(data[0] = 0, i=1; i<=n; i++) scanf("%d", &data[i]);
	for(i=0; i<n; i++) data[i] = data[i+1] - data[i];
	for(l=1; l<=n; l++) {
		for(i=0; i<n; i++) {
			if (data[i] != data[i%l]) break;
		}
		if (i == n) re[tot++] = l;
	}
	printf("%d\n", tot);
	for(i=0; i<tot; i++) printf("%d ", re[i]);
	printf("\n");
	return 0;
}