/*入门题。贪心+排序。排序后，求正负交错的最长子序列。
 *贪心策略：第一个肯定选。证明：反正，若不选。若最后
 *序列以正数开始，可以用第一个数替换；若负数开始，可
 *以添加第一个数，得到更长的序列。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 500005
#define LEN 160
int floors[NUM];
static inline int comp(const void *a1, const void *a2)
{
	int p1, p2;
	p1 = *(int *)a1;
	p2 = *(int *)a2;
	if (p1 < 0) p1 *= -1;
	if (p2 < 0) p2 *= -1;
	return p2-p1;
}
int main()
{
	int p, i, t, n, r;
	scanf("%d", &p);
	while(p--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d", &floors[i]);
		qsort(floors, n, sizeof(int), comp);
		if (n) r = 1;
		else r = 0;
		if (floors[0] > 0) t = -1;
		else t = 1;
		for(i=1; i<n; i++) {
			if (floors[i]*t > 0) {
				r++;
				t *= -1;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}