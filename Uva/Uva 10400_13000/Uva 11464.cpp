/*入门题。状态压缩动规。当第一行的取值确定后，第二行的取值也被唯一确定，
 *因为必须要保证第一行的元素满足条件。以此类推，下面所有行的取值都被唯
 *一确定。枚举第一行的所有可行取值，判断剩余所有元素是否满足条件。若都
 *符合，则找到一个可行解。记录最小可行解即可。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 17
#define LEN 6
int grid[NUM][NUM], grid2[NUM][NUM], n, tot, m;
static inline int ones(int a, int b)
{
	return grid2[a-1][b]+grid2[a+1][b]+grid2[a][b-1]+grid2[a][b+1];
}
static inline void Process_dp(void)
{
	int i, j, t=0, p;
	memcpy(grid2, grid, sizeof(grid));
	for(i=2; i<n+1; i++) {
		for(j=1; j<n+1; j++) {
			p = ones(i-1, j);
			if (p%2 == 1) {
				if (grid2[i][j]) return;
				t++;
				grid2[i][j] = 1;
			}
		}
	}
	for(i=1; i<=n; i++) {
		p = ones(n, i);
		if (p%2 == 1) return ;
	}
	if (tot+t < m) m = t+tot;
	return ;
}
static void DFS(int k)
{
	int i;
	while(1) {
		if (k>n) {
			Process_dp();
			return ;
		}
		for(i=k; i<=n; i++) if (grid[1][i] == 0) break;
		if (i<=n) {
			tot++;
			grid[1][i] = 1;
			DFS(i+1);
			grid[1][i] = 0;
			tot--;
		}
		k = i+1;
	}
}
int main()
{
	int c, cc, i, j;
	scanf("%d", &cc);
	for(c=1; c<=cc; c++) {
		scanf("%d", &n);
		tot = 0;
		m   = 10000;
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				scanf("%d", &grid[i][j]);
			}
			grid[i][n+1] = 0;
		}
		memset(grid[n+1], 0, sizeof(grid[0]));
		DFS(1);
		if (m == 10000) printf("Case %d: -1\n", c);
		else printf("Case %d: %d\n", c, m);
	}
	return 0;
}