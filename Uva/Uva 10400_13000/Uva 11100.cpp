/*基础题。贪心。确定至少需要几个包。求出每个尺寸出现的次数，最大次数就是
 *结果。证明：设最大次数为N，若比N小，则必有两个同样尺寸的包放在一起，不
 *符合题意。若比N大，则可将多出来的包插入到前N个中，这是由于其他尺寸出现
 *的次数比N小，一定可以找到一个包不包含该尺寸。
 *每个包中放的数量尽量少。将输入从小到大排序，依次向N个包中放，第N个包放
 *完后再回到第一个开始放，直到所有的都放完。因为将所有包平均分配到N个包中，
 *所以结果一定是最小的。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 160
int bags[NUM];
static inline int comp(const void *a1, const void *a2)
{
	int *p1 = (int *)a1;
	int *p2 = (int *)a2;
	return *p1-*p2;
}
int main()
{
	int i, n, l, t, pre;
	while(scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) scanf("%d", &bags[i]);
		qsort(bags, n, sizeof(int), comp);
		pre = i = l = 0;
		while(i<n) {
			for(i = pre+1; i<n; i++) if (bags[i] != bags[pre]) break;
			t = i-pre;
			if (t > l) l = t;
			pre = i;
		}
		printf("%d\n", l);
		for(i=0; i<l; i++) {
			printf("%d", bags[i]);
			for(t=i+l; t<n; t += l) printf(" %d", bags[t]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
