/*基础题。搜索。依次枚举所有顶点作为起始顶点，然后进行一遍DFS，找出最长路径。
  因为边不能重复，搜索一个边之后，将该边删掉，然后回溯恢复该边。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 28
#define LEN 28
int grap[NUM][NUM];
int cur, best, n, m;
void DFS(int k)
{
	int i;
	for(i=0; i<n; i++) {
		if (grap[k][i] == 1) {
			grap[k][i] = grap[i][k] = 0;
			cur++;
			DFS(i);
			cur--;
			grap[k][i] = grap[i][k] = 1;
		}
	}
	if (cur>best) best = cur;
	return ;
}
int main()
{
	int i, j, a, b;
	while(scanf("%d%d", &n, &m)) {
		if (n == 0) break;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) 
				grap[i][j] = 0;
		}
		for(i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			grap[a][b] = grap[b][a] = 1;
		}
		best = 0;
		for(i=0; i<n; i++) {
			cur = 0;
			DFS(i);
		}
		printf("%d\n", best);
	}
	return 0;
}