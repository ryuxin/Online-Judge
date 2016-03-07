/*基础题。动规。dp[i][j]表示第i个方块的第j个面为顶，能得到的
 *最大值。依次扫描所有质量小的方块的每个面。另外还要保存路径
 *信息。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 505
#define LEN 6
#define OPPOSE(n) (n+1-2*(n%2))
struct Cube {
	int color[LEN];
};
Cube cubes[NUM];
int dp[NUM][LEN], path[NUM][LEN], n;
char name[LEN][10] = {"front", "back", "left", "right", "top", "bottom"};
static inline void Calc(int a1, int a2)
{
	int r1 = 0, r2 = -1, m = 0;
	int mc = cubes[a1].color[OPPOSE(a2)];
	int *t, i, j;
	for(i=a1+1; i<n; i++) {
		t = cubes[i].color;
		for(j=LEN-1; j>=0; j--) {
			if (mc != t[j]) continue;
			if (dp[i][j]>m) {
				m  = dp[i][j];
				r1 = i;
				r2 = j;
			}
		}
	}
	dp[a1][a2]   = 1+m;
	path[a1][a2] = r1*LEN+r2;
}
static void DP()
{
	int i, j;
	for(i=LEN-1; i>=0; i--) {
		dp[n-1][i]   = 1;
		path[n-1][i] = -1;
	}
	for(i=n-2; i>=0; i--) {
		Calc(i, 0);
		Calc(i, 1);
		Calc(i, 2);
		Calc(i, 3);
		Calc(i, 4);
		Calc(i, 5);
	}
}
static void Print_path(int a1, int a2)
{
	int t;
	do {
		printf("%d %s\n", a1+1, name[a2]);
		t  = path[a1][a2];
		a2 = t%LEN;
		a1 = t/LEN;
	} while(t != -1);
}
int main()
{
	int i, j, *t, c = 1, r1, r2, m;
	while(scanf("%d", &n)) {
		if (!n) break;
		for(i=0; i<n; i++) {
			t = cubes[i].color;
			scanf("%d%d%d%d%d%d", &t[0], &t[1], 
				&t[2], &t[3], &t[4], &t[5]);
		}
		DP();
		m = dp[0][0];
		r1 = r2 = 0;
		for(i=0; i<n; i++)
			for(j=0; j<LEN; j++) {
				if (dp[i][j]>m) {
					m = dp[i][j];
					r1 = i;
					r2 = j;
				}
			}
		printf("Case #%d\n%d\n", c++, dp[r1][r2]);
		Print_path(r1, r2);
		printf("\n");
	}
	return 0;
}