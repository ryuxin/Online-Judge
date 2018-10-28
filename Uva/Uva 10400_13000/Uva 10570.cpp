/*基础题。枚举。变换后，按顺时针升序或降序即符合题意。
 *枚举所有符合条件的序列（即不同的起始位置），依次计算
 *变换到目标序列所需的交换数目。具体计算：每个目标序列
 *对应一个置换群，所求即为该置换群中，所有长度大于1的
 *循环中不相交的对换数目之和。
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

#define NUM 505
#define LEN 55
int data[2*NUM], vis[NUM], mre;
static inline int
mmin(int a, int b)
{ return a < b? a: b; }
static inline int
DFS(int *d, int k)
{
	int r=0;
loop:
	if (vis[k]) return r;
	vis[k] = 1;
	r++;
	k = d[k];
	goto loop;
	return r;
}
static inline int
calc(int *d, int n)
{
	int i, r = 0;
	memset(vis, 0, sizeof(vis));
	for(i=1; i<=n; i++) {
		if (!vis[i] && i != d[i]) {
			r += DFS(d, i)-1;
			if (r >= mre) break;
		}
	}
	return r;
}
static inline void
proc(int n)
{
	int i, t;
	for(i=0; i<n; i++) {
		t = calc(&data[i], n);
		mre = mmin(mre, t);
	}
}
int main()
{
	int i, n, j, t;
	while(scanf("%d", &n)) {
		if (n == 0) break;
		mre = n;
		for(i=1; i<=n; i++) scanf("%d", &data[i]);
		for(i=n+1; i<=2*n; i++) data[i] = data[i-n];
		proc(n);
		for(i=1; i<=n; i++) data[i] = data[2*n-i+1];
		for(i=n+1; i<=2*n; i++) data[i] = data[i-n];
		proc(n);
		printf("%d\n", mre);
	}
	return 0;
}