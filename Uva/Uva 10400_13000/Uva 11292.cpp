/*入门题。贪心。对于每一个头，都选择能砍掉它的最小的那个骑士，
 *若那个骑士已被选择，则继续选择他的下一个，以此类推。证明：
 *1、贪心选择性质。对于最小的头x，设能砍掉它的最小骑士为y，x<=y。
 *   则一定存在一个最优解，其中x与y对应。若不然，假设x与y'对应, 
 *   则有y<=y'（y是最小的能砍掉x的）。若y没有被选择，可以用y
 *	 替换y'，这样得到一个更小的开销；若y被选择与x'对应，可以
 *   交换y和y'，这样仍是一个最优解，且开销不变。
 *2、最优子结构。选定x和y后，得到一个原问题的子问题，显然原问题
 *   的最优一定包含子问题的最优解。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 20005
#define LEN 10
int head[NUM], kill[NUM];
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return *p1-*p2;
}
int main()
{
	int n, m, i, j, c, t;
	while(1) {
		scanf("%d %d", &n, &m);
		if (m == 0) break;
		for(i=0; i<n; i++) scanf("%d", &head[i]);
		for(i=0; i<m; i++) scanf("%d", &kill[i]);
		qsort(head, n, sizeof(int), comp);
		qsort(kill, m, sizeof(int), comp);
		c = j = 0;
		for(i=0; i<n; i++) {
			t = 0;
			while(j<m) {
				if (head[i]<=kill[j++]) {
					c += kill[j-1];
					t = 1;
					break;
				}
			}
			if (!t) break;
		}
		if (i == n) printf("%d\n", c);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}