/*中等题。贪心。分别将田忌和齐王的马排序，设田忌最快和最慢的马分别为
 *f1和s1，齐王的是f2和s2。共有五种情况：1、f1 > f2，则有f1对阵f2，能
 *赢齐王最快的马，当然是不二选择；2、f1 < f2，则用s1和f2相比，因为肯
 *定不能赢，用最慢的马去输代价最小；3、f1=f2, s1 > s2，则s1与s2比赛，
 *既然最慢的马能赢，没有必要浪费更快的马；4、f1=f2, s1 < s2，则s1对抗
 *f2，最慢的马肯定输，输给最快的马也算输得其所；5、f1=f2，s1=s2，仍用
 *s1对阵f2，这要证明。显然，最优方案中，s1要么和f2比，要么和s2比。假设
 *最优匹配是s1与s2配，x与f2配，交换s1和x，所得结果一定不会变差。因为：
 *若x < f2, 交换后有s1 < f2，x>=s2，可见结果没有变差；若x = f2，则交换
 *后为s1=f2, x=s2或者s1 < f2, x > s2，二者结果都一样。
 *实现时，情况2,4,5可以合并。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 1000005
#define QIAN 200
int tian[NUM], king[NUM];
static inline int comp(const void *a1, const void *a2)
{
	return *(int *)a2-*(int *)a1;
}
int main()
{
	int i, n, l1, l2, r1, r2, re;
	while(scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) scanf("%d", &tian[i]);
		for(i=0; i<n; i++) scanf("%d", &king[i]);
		qsort(tian, n, sizeof(int), comp);
		qsort(king, n, sizeof(int), comp);
		l1 = l2 = re = 0;
		r1 = r2 = n-1;
		while(l1 <= r1) {
			if (tian[l1] > king[l2]) {
				re += QIAN;
				l1++;
				l2++;
			} else if (tian[r1] > king[r2]) {
				re += QIAN;
				r1--;
				r2--;
			} else {
				if (tian[r1] < king[l2]) re -= QIAN;
				r1--;
				l2++;
			}
		}
		printf("%d\n", re);
	}
	return 0;
}