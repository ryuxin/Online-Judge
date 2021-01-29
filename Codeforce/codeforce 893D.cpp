/*劣等题。模拟，贪心。题意甚不明确，表达混乱不堪。
 *基本想法就是维护到当前为止，可以存款数量的最大值
 *和最小值，并检查是否符合条件
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

#define NUM 100005
#define LEN 4005
int n, d, num[NUM];
static inline int
chk(void)
{
	int mi = 0, ma = 0, i, r = 0, c;
	for(c=0, i=0; i<n; i++) {
		c += num[i];
		if (c + mi > d) return -1;
		if (num[i] == 0) {
			if (c + ma < 0) {
				r++;
				ma = d - c;
			}
			mi = max(mi, -c);
		} else ma = min(ma, d-c);
	}
	return r;
}
int main()
{
	scanf("%d%d", &n, &d);
	for(int i=0; i<n; i++) scanf("%d", num+i);
	printf("%d\n", chk());
	return 0;
}
 