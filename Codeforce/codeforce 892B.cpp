/*基础题。数组。对任意i，他最后能活下来的条件是
 *i > Min{j-Lj | j>i}。可得，从后向前扫描数组，
 *并维护当前j-Lj的最小值c，若当前元素索引小于c，
 *则能活下来；否则，就不可以。
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

#define NUM 1000005
#define LEN 105
int len[NUM];
int main()
{
	int i, n, c, r=0;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", len+i);
	for(c=n+1, i=n-1; i>=0; i--) {
		if (i<c) r++;
		c = min(c, i-len[i]);
	}
	printf("%d\n", r);
	return 0;
}
