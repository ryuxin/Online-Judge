/*基础题。深搜。枚举所有排列，计算出每个圆的圆心坐标。
  计算当前圆的圆心坐标时，要满足，他在前面圆的右边。
  至少与前面圆相切。给定前面圆的圆心坐标(xi, ri)，则
  当前圆的圆心坐标至少为xi+sqrt(4ri*r)。这些的最大值
  就是当前圆的圆心坐标，再加上其半径，就是长方形的右
  边界。另外注意当前圆还可能和做边界相切。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 10
#define LEN 35
int m;
double radis[NUM], xais[NUM], best, cur;
void DFS(int k)
{
	int i, j;
	double t, mm, s;
	if (k == m) {
		if (cur<best) best = cur;
		return ;
	}
	if (cur>best) return ;
	t = radis[k];
	for(i=k; i<m; i++) {
		radis[k] = radis[i];
		radis[i] = t;
		mm = radis[k];
		for(j=0; j<k; j++) {
			s = xais[j]+2*sqrt(radis[j]*radis[k]);
			if (s>mm) mm = s;
		}
		xais[k] = mm;
		s = cur;
		if (xais[k]+radis[k]>cur) cur = xais[k]+radis[k];
		DFS(k+1);
		cur = s;
		radis[i] = radis[k];
		radis[k] = t;
	}
}
int main()
{
	int n, i;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &m);
		best = 0;
		for(i=0; i<m; i++) {
			scanf("%lf", &radis[i]);
			best += radis[i];
		}
		best *= 2;
		DFS(0);
		printf("%.3lf\n", best);
	}
	return 0;
}