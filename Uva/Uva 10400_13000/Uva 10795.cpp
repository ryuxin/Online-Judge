/*入门题。数学，递归。和基本的汉诺塔问题思路一样。考虑目前最大的
 *盘子。若它在初始和目标状态中位置一样，则他不需要移动，继续考虑
 *后面的盘子。否则，设最大盘子p初始时在柱子a，最终移到柱子b，移到
 *分三个步骤，将所有其他盘子移到柱子c，将p移到b，最后将c上的所有
 *盘子移到目标状态。由于对称性，一三步都可以看做初始时所有盘子都
 *在一个柱子上。用同样的思路，可以递归处理这个中间问题。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 65
#define LEN 3
int disks[2][LEN][NUM];
long long int re;
static inline long long int
trans(int t1, int t2, int tot, int f)
{
	long long mre = 0;
	int i, j;
	while(1) {
		int t3 = 3-t1-t2;
		for(j=tot; j>0; j--) {
			for(i=0; i<3; i++) {
				if (disks[f][i][disks[f][i][0]] == j) break;
			}
			disks[f][i][0]--;
			if (i != t3) break;
		}
		if (!j) break;
		mre += (1UL<<(j-1));
		t1 = i;
		t2 = t3;
		tot = j-1;
	}
	return mre;
}
static inline void Calc(int tot)
{
	int i, j, t1, t2;
	re = 0;
	for(i=tot; i>0; i--) {
		for(j=0; j<LEN; j++) {
			if (i == disks[0][j][disks[0][j][0]]) break;
		}
		t1 = j;
		for(j=0; j<LEN; j++) {
			if (i == disks[1][j][disks[1][j][0]]) break;
		}
		t2 = j;
		disks[0][t1][0]--;
		disks[1][t2][0]--;
		if (t1 != t2) break;
	}
	if (!i) return;
	re = 1+trans(t1, t2, i-1, 0)+trans(t1, t2, i-1, 1);
}
int main()
{
	int n, c = 0, i, j;
	while(scanf("%d", &n)) {
		if (!n) break;
		c++;
		disks[0][0][0] = disks[0][1][0] = disks[0][2][0];
		disks[1][0][0] = disks[1][1][0] = disks[1][2][0];
		for(i=1; i<=n; i++) {
			scanf("%d", &j);
			j--;
			disks[0][j][0]++;
			disks[0][j][disks[0][j][0]] = i;
		}
		for(i=1; i<=n; i++) {
			scanf("%d", &j);
			j--;
			disks[1][j][0]++;
			disks[1][j][disks[1][j][0]] = i;
		}
		Calc(n);
		printf("Case %d: %lld\n", c, re);
	}
	return 0;
}