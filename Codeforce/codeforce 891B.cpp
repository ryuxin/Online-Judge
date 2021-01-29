/*基础题。排序，构造。将原数组a排序后得到b。在位置i，新排列放置
 *的数为比ai大的下一个数。具体地，令ai在b中的位置为k，则新排列p
 *中有，p[i] = b[k+1]；若ai为最大值，则p[i]放置最小值。
 *下面证明由此得到的排列符合题中条件：
 *设a中最大值为ak，且由p的构造可知
 *I，p[i] > a[i]，对于i != k
 *II，a[1] + a[2] + …… +a[n] = p[1] + p[2] + …… + p[n]
 *对于任意给定的子集X = {x1，……，xi}，若k不属于X，由上面I可知
 *p[x1] + …… + p[xi] > a[x1] + …… + a[xi]，符合条件；
 *若k在X中，有p[k] + p[x1] + …… + p[xn] < a[k] + a[x1] + …… + a[xn]
 * <=> p[k] - a[k] < (a[x1] - p[x1]) + …… + (a[xn] - p[xn])
 * <=> (a[1] - p[1]) + …… + (a[n] - p[n]) < (a[x1] - p[x1]) + …… + (a[xn] - p[xn])
 * <=> Sum{(a[i] - p[i]) | i不属于X} < 0
 *由I可证。
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
#include <climits>
using namespace std;

#define NUM 25
#define LEN 105
int num[NUM], srt[NUM], pos[NUM];
static inline int 
comp(const void *a1, const void *a2)
{
	int *p1 = (int *)a1;
	int *p2 = (int *)a2;
	return num[*p1] - num[*p2];
}
int main()
{
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", num+i);
	for(i=0; i<n; i++) srt[i] = i;
	qsort(srt, n, sizeof(int), comp);
	for(i=0; i<n; i++) pos[srt[i]] = i;
	for(i=0; i<n; i++) {
		printf("%d ", num[srt[(pos[i]+1) % n]]);
	}
	printf("\n");
	return 0;
}