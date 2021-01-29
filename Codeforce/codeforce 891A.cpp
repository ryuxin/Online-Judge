/*基础题。数学，枚举。情况1：若数组中所有数的最大公约数大于1，
 *则不可能；情况2：若数组中有1，则答案为数组长度减去1的个数。
 *情况3：这显然需要两步，先将某个数变为1，令其所需步数为A，
 *之后再需要n-1步将其余数变为1。从小到大(1 …… n-1)枚举A的
 *可能值，发现第一个可行，即为A的值。枚举时，可根据以下公式，
 *利用动规进行优化，gcd(a1……an) = gcd(gcd(a1……an-1)，an)
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

#define NUM 2005
#define LEN 105
int dat[NUM], gcd[NUM];
static inline int
GCd(int x ,int y)
{
	while (y!=0) {
		int t = x%y;
		x = y;
		y =t;
	}
	return x;
}
int main()
{
	int i, n, n1=0, pev, l;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &dat[i]);
		if (dat[i] == 1) n1++;
	}
	if (n1) printf("%d\n", n-n1);
	else {
		for(l=0; l<n; l++) {
			for(i=0; i+l<n; i++) {
				gcd[i] = GCd(gcd[i], dat[i+l]);
				if (gcd[i] == 1) {
					printf("%d\n", l+n-1);
					return 0;
				}
			}
		}
		printf("-1\n");
	}
	return 0;
}