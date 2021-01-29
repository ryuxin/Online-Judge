/*基础题。构造。数学。有以下两点推断：
 *1.集合中最小值M一定是gcd(a1, a2,……,an)
 *2.M一定是其他值（gcd(ai,……,aj)）的因子
 *若上述条件不满足，答案为-1，
 *否则按题解构造即可。
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
#define LEN 3
int num[NUM];
int main()
{
	int i, m;
	scanf("%d", &m);
	for(i=0; i<m; i++) scanf("%d", num+i);
	for(i=0; i<m; i++) {
		if (num[i] % num[0] != 0) break;
	}
	if (i == m) {
		printf("%d\n", m+m);
		for(i=0; i<m; i++) printf("%d %d ", num[0], num[i]);
		printf("\n");
	} else printf("-1\n");
	return 0;
}