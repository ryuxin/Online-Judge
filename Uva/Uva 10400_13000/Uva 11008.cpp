/*中等题。动规。因为最多有16棵树，可以用位数组来枚举树木的所有状态。对于
 *状态s，若第i位是1，表示第i棵树仍在，否则其已被砍掉。dp[s][m]表示在状态
 *s下，要砍掉m棵树，需要几条直线。由于两点确定一条直线，所以状态s下至少通
 *过两点的直线是确定的，且最终答案中的直线一定选自这些直线（只通过一个点
 *的直线是没有意义的）。求解dp[s][m]时，枚举状态s中的每条直线。若一条直线
 *通过了a个点，去处直线上的点后得到新状态ss，则有dp[s][m] = 1+min{dp[ss][m-a]}。
 *如何求出状态s所确定的直线并找到直线上的点。简单的枚举法可以枚举状态s下的
 *所有点对，每一对点确定一条直线，然后遍历所有的点，判断其是否在直线上。但
 *对所有状态都这样计算，显然开销太大。注意到若状态ss是状态s子集，则状态ss所
 *确定的直线也是状态s直线的子集。所以所有状态的直线都是初始状态的子集。这样
 *可以对初始状态进行预处理，求出所有可能的直线和每条直线上的所通过的点。
 *优化：
 *1、预处理时，可以去除重复的直线。
 *2、若任意三点不共线，则每条直线只能砍掉两棵树，所以直线数目是m/2。
 *3、降低维度。设状态s包含a棵树，初始时一共有n棵树，需要砍掉m棵树，当求解
 *   dp[s][b]时，有b = m - (n-a)。可见第二维是冗余的，可以省略掉。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 17
#define BIN 10
struct Point {
	int x, y;
};
int dp[1<<NUM], line[NUM*NUM/2], nline, n;
Point trees[NUM];
//计算直线ab通过的所有点，返回所包含点的bitmap
static inline int
Line_points(int a, int b)
{
	int i, r=0, x, y;
	x = trees[a].x-trees[b].x;
	y = trees[a].y-trees[b].y;
	for(i=0; i<n; i++) {
		if (x*(trees[a].y-trees[i].y) == y*(trees[a].x-trees[i].x))
			r |= (1<<i);
	}
	return r;
}
static inline void
Process_line(void)
{
	int i, j, k, t;
	nline = 0;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			t = (1<<i) | (1<<j);
			//若该两点已被其它直线包含，则该直线是重复的
			for(k=0; k<nline; k++)
				if ((t&line[k]) == t) break;
			if (k==nline) line[nline++] = Line_points(i, j);
		}
	}
}
static inline int
Num_one(int a)
{
	a = (a & 0x55555555)+((a>>1)&0x55555555);
	a = (a & 0x33333333)+((a>>2)&0x33333333);
	a = (a & 0x0f0f0f0f)+((a>>4)&0x0f0f0f0f);
	a = (a & 0x00ff00ff)+((a>>8)&0x00ff00ff);
	a = (a & 0xffff)+((a>>16)&0xffff);
	return a;
}
static int DP(int state, int num)
{
	int i, t, m = num, r;
	if (num <= 0) return 0;
	if (num <= 2) return 1;
	if (dp[state] == -1) {
		for(i=0; i<nline; i++) {
			t = state & line[i];
			r = Num_one(t);
			if (r >= 2) {
				r = 1+DP(state^t, num-r);
				if (r<m) m = r;
			}
		}
		dp[state] = m;
	}
	return dp[state];
}
int main()
{
	int c, cases, m, i, r;
	scanf("%d", &cases);
	for(c=1; c<=cases; c++) {
		scanf("%d%d", &n, &m);
		memset(dp, -1, (1<<n)*sizeof(dp[0]));
		for(i=0; i<n; i++) scanf("%d%d", &trees[i].x, &trees[i].y);
		Process_line();
		if (nline*2 == n*(n-1)) r = (m+1)/2;
		else r = DP((1<<n)-1, m);
		if (c!=cases) printf("Case #%d:\n%d\n\n", c, r);
		else printf("Case #%d:\n%d\n", c, r);
	}
	return 0;
}