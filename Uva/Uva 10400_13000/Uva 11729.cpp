/*基础题。贪心。最后的完成时间就是所有士兵完成时间的最大值。一个士兵si可
 *表示为，si=(bi, ji)，将所有士兵按ji从大到小排序得到s1,s2,...sn。贪心选
 *择的性质：一定存在一个最优排列使得s1是第一个。否则假设最优排列是
 *sk,si1,si2...s1,sik...sin。可以交换s1和sk，得到新 *的排列
 *s1,si1,si2...sk,sik...sin。交换前后，sik到sin的完成时间都不变。交换前s1的
 *完成时间是T1=b1+...+bk+j1，交换后s1的完成时间是T1'=b1+j1<T1, sk的完成时间
 *是Tk'=b1+...+bk+jk<T1，而对s1和sk之间的sij，同样有完成时间
 *Tji'=b1+..+bji+jij<b1+...+bk+jij<T1。可见交换后，士兵完成时间的最大值一定
 *小于等于交换前，所以交换后是一个最优的排列。
 *本题显然具有最优子结构，所以贪心法正确。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 5
struct Soldier {
	int b, j;
};
Soldier soders[NUM];
int comp(const void *a1, const void *a2)
{
	Soldier *p1, *p2;
	p1 = (Soldier *)a1;
	p2 = (Soldier *)a2;
	return p2->j-p1->j;
}
int main()
{
	int n, i, m, s, c, k=1;
	while(scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) scanf("%d %d", &soders[i].b, &soders[i].j);
		qsort(soders, n, sizeof(Soldier), comp);
		s = m = 0;
		for(i=0; i<n; i++) {
			s += soders[i].b;
			c  = s+soders[i].j;
			if (c>m) m = c;
		}
		printf("Case %d: %d\n", k++, m);
	}
	return 0;
}