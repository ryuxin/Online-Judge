/*基础题。贪心。将早上的距离从大到小排序。晚上的从小到大排序。设早上
 *最长距离为L，则与L配对的一定是晚上最小的S。证明：若不是，则最优方案
 *中L与x配对，y与S配对。交换x和S，所得结果不会更差。由条件得，L>=y,x>=S
 *若y+S>=d, 则交换前后两对都超过了d，额外支出都为(L+S+x+y)-2d；
 *若L+x<=d，则交换前后两对都没有超过d，没有额外支出；
 *现在考虑y+S < d < L+x。交换后最差结果为两对都超出了d，额外支出为
 *R2 = (L+S+x+y)-2d，且交换前为R1 = L+x-d， R2-R1 = S+y-d < 0，
 *可见交换后变得更好。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 1000005
int m[NUM], e[NUM];
static inline int comp(const void *a1, const void *a2)
{
	return *(int *)a1-*(int *)a2;
}
int main()
{
	int n, d, r, i, j, t, re;
	while(scanf("%d%d%d", &n, &d, &r)) {
		if (!n) break;
		for(i=0; i<n; i++) scanf("%d", &m[i]);
		for(i=0; i<n; i++) scanf("%d", &e[i]);
		qsort(m, n, sizeof(int), comp);
		qsort(e, n, sizeof(int), comp);
		re = 0;
		for(i=0, j=n-1; i<n; i++, j--) {
			t = m[i]+e[j]-d;
			if (t > 0) re += t*r;
		}
		printf("%d\n", re);
	}
	return 0;
}