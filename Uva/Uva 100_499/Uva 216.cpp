/*基础题。深搜+枚举。枚举起始点的编号，搜索该起点的所以排列。
  注意初始化和回溯。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
struct Point {
	int x, y;
};
Point points[10];
int order[10], used[10], n, re[10];
double best, cur;
void DFS(int k)
{
	int i;
	double t;
	if (k == n) {
		if (cur < best) {
			best = cur;
			for(i=0; i<n; i++) re[i] = order[i];
		}
		return ;
	}
	for(i=0; i<n; i++) {
		if (used[i] == 1) continue;
		t  = (points[i].x-points[order[k-1]].x)*(points[i].x-points[order[k-1]].x);
		t += (points[i].y-points[order[k-1]].y)*(points[i].y-points[order[k-1]].y);
		t = sqrt(t);
		if (cur+t < best) {
			cur     += t;
			order[k] = i;
			used[i]  = 1;
			DFS(k+1);
			cur    -= t;
			used[i] = 0;
		}
	}
	return ;
}
int main()
{
	int i, c = 0;
	float t, r;
	while(scanf("%d", &n) > 0) {
		if (n == 0) break;
		c++;
		for(i=0; i<n ;i++) scanf("%d %d", &points[i].x, &points[i].y);
		cur = 0;
		best = 150*150*10;
		r = 0;
		for(i=0; i<n; i++) {
			order[0] = i;
			for(int j=0; j<n; j++) used[j] = 0;
			used[i] = 1;
			cur = 0;
			DFS(1);
		}
		printf("**********************************************************\n");
		printf("Network #%d\n", c);
		for(i=0; i<n-1; i++) {
			t  = (points[re[i]].x-points[re[i+1]].x)*(points[re[i]].x-points[re[i+1]].x);
			t += (points[re[i]].y-points[re[i+1]].y)*(points[re[i]].y-points[re[i+1]].y);
			t  = sqrt(t)+16;
			r += t;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 
				points[re[i]].x, points[re[i]].y, points[re[i+1]].x, points[re[i+1]].y, t);
		}
		printf("Number of feet of cable required is %.2f.\n", r);
	}
	return 0;
}