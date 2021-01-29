/*基础题。递归。下面给出一个与题解不尽相同的解法。
 *给定长度为k的所有数字，可以得到长度k+2的所有数字，
 *即在每个长度为k的数字前后依次填充0，1，2……
 *但是计算最终结果时，要忽略掉所有以0开头的数字
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
#define LEN 26
static inline int
proc(int k, int p)
{
	int i, j, tot=0, n, r = 0;
	long long b = 10, t;
	vector<int> dp[2];
	dp[0].push_back(0);
	for(n=1; ; n++) {
		dp[n%2].clear();
		for(i=0; i<dp[(n-1)%2].size(); i++) {
			t = dp[(n-1)%2][i];
			dp[n%2].push_back((t*10) % p);
		}
		for(j=1; j<=9; j++) {
			for(i=0; i<dp[(n-1)%2].size(); i++) {
				t = dp[(n-1)%2][i];
				t = (b*j+t*10+j) % p;
				dp[n%2].push_back(t);
				r = (r+t) % p;
				tot++;
				if (tot == k) return r;
			}
		}
		b = (b*100) % p;
	}
	return 0;
}
int main()
{
	int k, p, r = 0;
	scanf("%d%d", &k, &p);
	r = proc(k, p);
	printf("%d\n", r);
	return 0;
}