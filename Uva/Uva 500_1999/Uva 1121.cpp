/*基础题。搜索，对于每个元素i，确定以他开始的最短子数组和大于
 *等于S。具体地，对于i，依次往后扫描并计算子数组的和，直到和
 *大于等于S，设当前位置为j。此外，我们还知道从i+1到j的和为
 *S-a[i]。这样下一次求解i+1时，我们可以继续从j开始往后扫描。
 *特殊情况：当没有满足条件的子数组时，返回0！！
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 100005
#define LEN 105
int num[NUM];
static inline int
mmin(int a, int b)
{ return a < b? a: b; }
static inline void
fastscanf4(int n, int *p)
{
	int i=0, j;
	j = n%4;
	for(i=0; i<j; i++) scanf("%d", &p[i]);
	for(; i<n; i += 4) {
		scanf("%d %d %d %d", &p[i], &p[i+1], &p[i+2], &p[i+3]);
	}
}

int main()
{
	int i, n, j, best;
	long long int s, r, a;
	while (scanf("%d %lld %d", &n, &s, &num[0]) != EOF) {
		fastscanf4(n-1, &num[1]);
		best = n+1;
		r = (long long int)num[0];
		for(i=0, j=1; i<n; i++) {
			while (r < s && j<n) {
				r += (long long int)num[j++];
			}
			if (r >= s) {
				best = mmin(best, j-i);
				if (best == 1) break;
			} else if (j >= n) break;
			r -= (long long int)num[i];
		}
		if (best == n+1) best = 0;
		printf("%d\n", best);
	}
	return 0;
}