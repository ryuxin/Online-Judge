/*基础题。基础动规。dp[i][j]表示从(i，j)到最后一列的最短距离，
  dp[i][j] = data[i][j]+mix{dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]}。
  用滚动数组优化空间。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 12
#define LEN 105
struct Pos {
	int row;
	int val;
};
int data[NUM][LEN], dp[2][NUM], child[NUM][LEN];
int m, n, cur;
int comp(Pos *p1, Pos *p2)
{
	if (p1->val != p2->val) return p1->val-p2->val;
	return p1->row-p2->row;
}
int Min(int a, int b)
{
	int i;
	Pos p[3];
	for(i=0; i<3; i++) {
		p[i].row = (b+i-1+m)%m;
		p[i].val = dp[a][(b+i-1+m)%m];
	}
	if (comp(&p[0], &p[1]) < 0) {
		if (comp(&p[0], &p[2]) < 0) return p[0].row;
		else return p[2].row;
	}
	else {
		if (comp(&p[1], &p[2])<0) return p[1].row;
		else return p[2].row;
	}
}
int main()
{
	int i, j, t;
	while(scanf("%d %d", &m, &n)>0) {
		for(i=0; i<m; i++) 
			for(j=0; j<n; j++)
				scanf("%d", &data[i][j]);
		for(i=0; i<m; i++) {
			dp[0][i] = data[i][n-1];
			child[i][n-1] = -1;
		}
		cur = 1;
		for(i=n-2; i>=0; i--) {
			for(j=0; j<m; j++) {
				t = Min(1-cur, j);
				dp[cur][j] = data[j][i]+dp[1-cur][t];
				child[j][i] = t;
			}
			cur = 1-cur;
		}
		cur = 1-cur;
		j = 0;
		t = dp[cur][j];
		for(i=1; i<m; i++) {
			if (dp[cur][i]<t) {
				t = dp[cur][i];
				j = i;
			}
		}
		for(i=0; i<n; i++) {
			printf("%d", j+1);
			j = child[j][i];
			if (i != n-1) printf(" ");
			else printf("\n");
		}
		printf("%d\n", t);
	}
	return 0;
}