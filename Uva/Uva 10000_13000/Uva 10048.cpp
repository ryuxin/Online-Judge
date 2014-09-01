/*基础题。一条路径中权值最大的边是该路径的关键边。
  一对顶点间所有路径的最小关键边可以称为该对顶
  点的关键边，此题要求出每对顶点的关键边。
  应用floyed算法，转移方程改为求两条路径关键边的
  较小值。复杂度V^3。
  Kruskal算法。对于一对给定的顶点，插入一条边后，
  检查该对顶点是否连通，若连通，当前插入的边就是
  其关键边。但对每一次查询，要求运行该算法，查询
  量很大时，不能忍受*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 105
#define LEN 100
int grap[NUM][NUM], n;
void Flyod()
{
	int i, j, k, t;
	for(k=1; k<=n; k++) 
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++) {
				if (grap[i][k] == -1 || grap[k][j] == -1) 
					continue;
				t = max(grap[i][k], grap[k][j]);
				if (grap[i][j] == -1 || grap[i][j]>t)
					grap[i][j] = t;
			}
	return ;
}
int main()
{
	int s, q, i, a, b, d, t = 0;
	while(scanf("%d%d%d", &n, &s, &q)>0) {
		if (n == 0 && s == 0 && q == 0) break;
		if (t != 0) printf("\n");
		t++;
		memset(grap, -1, sizeof(grap));
		for(i=0; i<=n; i++) grap[i][i] = 0;
		for(i=0; i<s; i++) {
			scanf("%d%d%d", &a, &b, &d);
			grap[a][b] = grap[b][a] = d;
		}
		Flyod();
		printf("Case #%d\n", t);
		for(i=0; i<q; i++) {
			scanf("%d%d", &a, &b);
			if (grap[a][b] == -1) printf("no path\n");
			else printf("%d\n", grap[a][b]);
		}
	}
	return 0;
}