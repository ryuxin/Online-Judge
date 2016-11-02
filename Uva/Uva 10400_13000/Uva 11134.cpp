/*中等题。贪心。棋子的摆放方法在x和y方向上独立。具体的讲，给定一种排列方法
 *（X，Y），若存在另外一种x方向的排列方法X'，使得任意两个棋子不在同一列，则
 *（X',Y）也是一个可行解。直观地看，可以将棋子在x方向上平移，得到从X到X'的
 *一个置换，由于平移不改变y方向的排列，所以平移后的状态仍满足题意。
 *由此将本题分解为两个一维的问题，可用贪心解决。以x方向为例，每个棋子对应一
 *个区间[li, ri]，按区间右端点从小到大排序。从1到n依次查看每一列，找到能覆盖
 *这一列，且右端点最小的棋子，即可将该棋子放在这一列。证明：设覆盖方式为
 *(i, rj), (j, ri)，即这一列被rj覆盖，而ri被用来覆盖后面的某一列j。由于j>i, 
 *rj>=ri，交换棋子ri和rj后仍是可行解，因为被ri覆盖的列也一定可以被rj覆盖
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 5005
#define LEN 1000005
struct Rook {
	int xr, xl, yr, yl;
	int x, y;
};
Rook rooks[NUM];
int use[NUM], pos[NUM];
int n;
static inline int compx(const void *a1, const void *a2)
{
	int p1 = *((int *)a1);
	int p2 = *((int *)a2);
	return rooks[p1].xr-rooks[p2].xr;
}
static inline int compy(const void *a1, const void *a2)
{
	int p1 = *((int *)a1);
	int p2 = *((int *)a2);
	return rooks[p1].yr-rooks[p2].yr;
}
int main()
{
	int i, j;
	while(scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) {
			scanf("%d%d%d%d", &rooks[i].xl, &rooks[i].yl, &rooks[i].xr, &rooks[i].yr);
		}
		memset(use, 0, sizeof(use));
		for(i=0; i<n; i++) pos[i] = i;
		qsort(pos, n, sizeof(int), compx);
		for(i=1; i<=n; i++) {
			for(j=0; j<n; j++) {
				if (!use[j] && i>=rooks[pos[j]].xl && i<=rooks[pos[j]].xr) {
					use[j] = 1;
					rooks[pos[j]].x = i;
					break;
				}
			}
			if (j == n) goto done;
		}
		qsort(pos, n, sizeof(int), compy);
		for(i=1; i<=n; i++) {
			for(j=0; j<n; j++) {
				if (use[j] && i>=rooks[pos[j]].yl && i<=rooks[pos[j]].yr) {
					use[j] = 0;
					rooks[pos[j]].y = i;
					break;
				}
			}
			if (j == n) break;
		}
done:
		if (i == 1+n) {
			for(i=0; i<n; i++) printf("%d %d\n", rooks[i].x, rooks[i].y);
		} else printf("IMPOSSIBLE\n");
	}
	return 0;
}