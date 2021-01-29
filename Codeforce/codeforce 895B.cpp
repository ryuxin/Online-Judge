/*基础题。排序，二分。思路和题解一样。
 *实现细节和边界条件：
 *1.第38行和第39行的第一个条件，处理k=0的情况；
 *2.第39行的第二个条件防止32位int溢出，
 *  当然也可以全部使用64位long long
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
#define LEN 4
int dat[NUM];
int main()
{
	long long r=0;
	int i, n, x, k, t;
	int left, right, *lp, *rp;
	scanf("%d%d%d", &n, &x, &k);
	for(i=0; i<n; i++) scanf("%d", &dat[i]);
	sort(dat, dat+n);
	for(i=0; i<n; i++) {
		t     = ((dat[i] - 1)/x)*x;
		right = t + k*x + x -1;
		left  = max(dat[i], t+k*x);
		if (right >= left && (dat[n-1]-t)/x >= k) {
			lp = lower_bound(dat, dat+n, left);
			rp = upper_bound(dat, dat+n, right);
			r += (long long)(rp-lp);
		}
	}
	printf("%lld\n", r);
	return 0;
}