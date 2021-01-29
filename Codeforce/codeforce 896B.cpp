/*基础题。排序。对题解进行一些补充。基本策略是，对给定的
 *数，从头扫描数组，发现空的或比其大的，就放在该位置；否
 *则继续扫描，直至放在最后。这种策略有两个性质：
 *1.数组一直是有序的
 *2.填充的数的个数只会增加或不变。因此，对于m个操作序列，
 *最后留在数组里的数至少是操作序列的最长非降子序列的长度。
 *若该长度大于n，则此策略一定会生成所需数组。
 *但由题中约束，所有操作的最长非降子序列可能至少n/2，不
 *符合条件。由此，可将输入序列分为两部，小于等于c/2和大于
 *c/2的。前一部分在数组开始处填充，而后一部分从数组末尾
 *处填充。这样，数组前后两部分都是排序的，且前半都小于
 *后半，因此整个数组也就是排序的。
 *剩下唯一问题是，如果说明两部分长度之和大于n。证明：
 *设每个操作数出现的次数为ni。最长非降子序列的长度一定不
 *小于每个数的次数。所以两部分的长度分别有
 *L1 >= Max{ni | 1 <= i <= c/2}
 *L2 >= Max{ni | 2/c < i <= c}
 *m = n1 + n2 + …… + nc
 * <= L1 + L1 + …… + L2 + L2
 *  = (c/2) * (L1 + L2)
 *再由nc/2 <= m => nc/2 <= (c/2) * (L1 + L2)，
 *推出n <= L1 + L2。证毕。
 *最后说明一点，题中约束条件非常特殊，既是解题的一个关键提示
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

#define NUM 1005
#define LEN (1LL << 60)
int dat[NUM];
static inline bool
issort(int n)
{
	for(int i=1; i<=n; i++) {
		if (dat[i] == -1) return false;
		if (dat[i]<dat[i-1]) return false;
	}
	return true;
}
static inline int
proc_low(int n, int k)
{
	for(int i=1; i<=n; i++) {
		if (dat[i] == -1) return i;
		if (k < dat[i]) return i;
	}
	return n;
}
static inline int
proc_high(int n, int k)
{
	for(int i=n; i>0; i--) {
		if (dat[i] == -1) return i;
		if (k > dat[i]) return i;
	}
	return 1;
}
int main()
{
	int n, m, c, i, p;
	memset(dat, -1, sizeof(dat));
	scanf("%d%d%d", &n, &m, &c);
	while (1) {
		if (issort(n)) break;
		scanf("%d", &m);
		if (m <= c/2) p = proc_low(n, m);
		else p = proc_high(n, m);
		dat[p] = m;
		printf("%d\n", p);
		fflush(stdout);
	}
	return 0;
}