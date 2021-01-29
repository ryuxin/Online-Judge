/*入门题。算术。设每人的总票数为x，根据题意有x*n-sum > sum，
 * 其中sum是反对票的总和。边界条件x大于等于反对票的最大值。
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>   
#include <vector>
using namespace std;

#define NUM 105
#define LEN 505
static inline int
mmax(int a, int b)
{ return a > b? a: b; }
int main()
{
	int i, n, s=0, k, m=0, a;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &a);
		m = mmax(m, a);
		s += a;
	}
	k = 2*s/n + 1;
	printf("%d\n", mmax(m, k));
	return 0;
}