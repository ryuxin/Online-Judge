/*中等题。动规。这是算法导论动态规划的一个习题。整个环路可分为上下两个部分，
 *上半从左到右，下半从右向左。设所有点从左到右编号为1...n。上半路径的最后一个
 *节点（即n前一个节点）只能是1..n-1，它们中构成的路径中最小值即为所求。下面考
 *虑n的前一个节点为i，则i+1到n-1一定在下半路径，且此时可以确定的部分路径为，
 *上半，从i直接到n，下半，从i+1到n的距离和；未知部分的路径是：从1开始的上半路径
 *以i结尾，下半路径以i+1结束（这部分不是环路）。下面解释怎么确定未知部分的最小
 *路径。设f(i)表示此部分的最小值。首先此部分路径满足对称性，即上半以i+1结束，
 *下半以i结束的最短路径值也为f(i)。和前面的分析相似，若下半中i+1的前一个节点为j，
 *则j+1到i-1一定在上半，未知部分的路径f(j)。由此，可得状态转移方程：
 *f(i) = min{f(j)+dis(j, i+1)+sum(j+1, i) | 1<=j<i}, 最终答案为：
 *ans = min{f(i)+dis(i, n)+sum(i+1, n) | 1<=i<n}, dis(i, j)表示i和j之间的直接
 *距离，sum(i, j)表示从i到j的所有节点的距离和。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 10
struct MPoint {
	float x, y;
};
struct MPoint data[NUM];
float diss[NUM], dp[NUM];
static inline float
dis(int s, int e)
{
	float x, y;
	x = data[e].x - data[s].x;
	y = data[e].y - data[s].y;
	return sqrt(x*x + y*y);
}
int main()
{
	int i, j, n;
	float t, m;
	while (scanf("%d", &n) == 1) {
		for(i=0; i<n; i++) scanf("%f %f", &data[i].x, &data[i].y);
		for(diss[0]=0, i=1; i<n; i++) diss[i] = diss[i-1] + dis(i-1, i);
		dp[1] = dis(0, 1)+dis(0, 2);
		for(i=2; i<n-1; i++) {
			m = dis(0, i+1) + diss[i];
			for(j=1; j<i; j++) {
				t = dp[j] + dis(j, i+1) + (diss[i] - diss[j+1]);
				if (t < m) m = t;
			}
			dp[i] = m;
		}
		m = diss[n-1]+dis(0, n-1);
		for(i=1; i<n-1; i++) {
			t = dp[i]+dis(i, n-1)+(diss[n-1] - diss[i+1]);
			if (t < m) m = t;
		}
		printf("%.2f\n", m);
	}
    return 0;
}
