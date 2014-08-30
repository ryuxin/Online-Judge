/*基础题。最短路。求每对顶点间的最短路径。由于所有边都是单位边，
  可以直接用BFS求解。运行n次BFS，复杂度n^2。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 22
#define LEN 35
int grap[NUM][NUM], re[NUM][NUM];
int q[NUM], h, t, used[NUM];
void BFS(int k)
{
	int d = 0, c, i, a;
	h = 0;
	q[0] = k;
	q[1] = -1;
	t = 2;
	for(i=0; i<NUM; i++) used[i] = 0;
	used[k] = 1;
	while(1) {
		c = q[h];
		h = (h+1)%NUM;
		if (c == -1 ) {
			if(h == t) break;
			d++;
			q[t] = -1;
			t = (t+1)%NUM;
		}
		else {
			re[k][c] = d;
			for(i=0; i<grap[c][0]; i++) {
				a = grap[c][1+i];
				if (used[a] == 1) continue;
				used[a] = 1;
				q[t] = a;
				t = (t+1)%NUM;
			}
		}
	}
	return ;
}
int main()
{
	int n, i, j, c = 0, k;
	while(scanf("%d", &n)>0) {
		c++;
		for(i=0; i<NUM; i++) grap[i][0] = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &k);
			grap[0][++grap[0][0]] = k-1;
			grap[k-1][++grap[k-1][0]] = 0;
		}
		for(i=1; i<19; i++) {
			scanf("%d", &n);
			for(j=0; j<n; j++) {
				scanf("%d", &k);
				grap[i][++grap[i][0]] = k-1;
				grap[k-1][++grap[k-1][0]] = i;
			}
		}
		for(i=0; i<20; i++) BFS(i);
		printf("Test Set #%d\n", c);
		scanf("%d", &n);
		for(k=0; k<n; k++) {
			scanf("%d %d", &i, &j);
			printf("%2d to %2d: %d\n", i, j, re[i-1][j-1]);
		}
		printf("\n");
	}
	return 0;
}