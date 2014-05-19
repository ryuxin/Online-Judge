/*基础题。简单几何+枚举。大体思路，枚举所有点对，找出与该点对共线
  的所有点。优化，找到共线的点后，可将这些点记录下来，以后不再枚
  举这些点之间的点对。
  另外，可以枚举每一个点，计算其他点相对该点的斜率，斜率相同则说
  明共线，复杂度n*n*logn，但斜率实现比向量复杂*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 705
#define LEN 1010
struct Point {
	int x, y;
};
Point data[NUM];
int line[NUM], num, done[NUM][NUM], best;
char in[30];
void Line(int a, int b)
{
	int x1, y1, x2, y2, i, j;
	x1 = data[a].x-data[b].x;
	y1 = data[a].y-data[b].y;
	int cur = 0;
	for(i=0; i<num; i++) {
		x2 = data[i].x-data[b].x;
		y2 = data[i].y-data[b].y;
		if (x1*y2-x2*y1 == 0) 
			line[cur++] = i;
	}
	for(i=0; i<cur; i++)
		for(j=i+1; j<cur; j++) {
			done[line[i]][line[j]] = cur;
			done[line[j]][line[i]] = cur;
		}
	if (cur>best) best = cur;
	return ;
}
int main()
{
	int i, j, t, l;
	scanf("%d", &t);
	gets(in);
	gets(in);
	while(t--) {
		num = 0;
		while(gets(in) != NULL) {
			l = strlen(in);
			if (l == 0) break;
			sscanf(in, "%d", &data[num].x);
			for(i=0; i<l; i++) 
				if (in[i] == ' ')
					break;
			sscanf(in+i+1, "%d", &data[num].y);
			num++;
		}
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
				done[i][j] = 0;
		for(i=0; i<num; i++) done[i][i] = 1;
		best = 0;
		for(i=0; i<num; i++)
			for(j=0; j<num; j++)
				if (done[i][j] == 0)
					Line(i, j);
		printf("%d\n", best);
		if (t != 0) printf("\n");
	}
	return 0;
}	
/*
#define NUM 705
#define LEN 1010
struct Point {
    int x, y;
};
Point data[NUM];
int num, best, cur, inf, res;
double k[NUM];
char in[30];
int comp(const void *a1, const void *a2)
{
	double *p1, *p2;
	p1 = (double *)a1;
	p2 = (double *)a2;
	if ((*p1)>(*p2)) return 1;
	else if ((*p1)<(*p2)) return -1;
	return 0;
}
int main()
{
    int i, j;
	double x, y;
    while(scanf("%d", &num)>0) {
        if (num == 0) break;
        for(i=0; i<num; i++)
            scanf("%d%d", &data[i].x, &data[i].y);
        best = 0;
		for(i=0; i<num; i++) {
			cur = 2;
			inf = res = 0;
			for(j=0; j<num; j++) {
				x = data[j].x-data[i].x;
				y = data[j].y-data[i].y;
				if (x == 0) inf++;
				else k[res++] = y/x;
			}
			qsort(k, res, sizeof(double), comp);
			if (inf>best) best = inf;
			for(j=1; j<res; j++) {
				if (k[j] == k[j-1]) cur++;
				else {
					if (cur>best) best = cur;
					cur = 2;
				}
			}
			if (cur>best) best = cur;
		}
        printf("%d\n", best);
    }
    return 0;
}
*/