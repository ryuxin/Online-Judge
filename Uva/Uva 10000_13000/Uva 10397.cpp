#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 753
#define LEN 750*380
struct Edge {
	int id;
	double w;
};
Edge edges[LEN];
struct Point {
	int x, y;
};
Point points[NUM];
int n, ufs[NUM], e;
int comp(const void *a1, const void *a2)
{
	Edge *p1, *p2;
	p1 = (Edge *)a1;
	p2 = (Edge *)a2;
	if (p1->w>p2->w) return 1;
	else if (p1->w<p2->w) return -1;
	else return 0;
}
inline double dis(int a, int b)
{
	double x, y;
	x = points[a].x-points[b].x;
	y = points[a].y-points[b].y;
	return sqrt(x*x+y*y);
}

void Decode(int c, int *a, int *b)
{
	int i, r = 0;
	c++;
	for(i=1; i<n; i++) {
		r += n-i;
		if (r>=c) break;
	}
	*a = i-1;
	r -= n-i;
	*b = *a+c-r;
}
int Find(int a)
{
	if (ufs[a] == a) return a;
	ufs[a] = Find(ufs[a]);
	return ufs[a];
}
double Kruskal()
{
	int i, a, b, pa, pb;
	double r = 0;
	for(i=0; i<e; i++) {
		Decode(edges[i].id, &a, &b);
		pa = Find(a);
		pb = Find(b);
		if (pa != pb) {
			r += edges[i].w;
			ufs[pa] = pb;
		}
	}
	return r;
}
int main()
{
	int i, m, a, b, pa, pb;
	while(scanf("%d", &n)>0) {
		for(i=0; i<n; i++) {
			scanf("%d%d", &points[i].x, &points[i].y);
			ufs[i] = i;
		}
		e = 0;
		for(a=0; a<n-1; a++)
			for(b=a+1; b<n; b++) {
				edges[e].id = e;
				edges[e++].w = dis(a, b);
			}
		scanf("%d", &m);
		for(i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			pa = Find(a-1);
			pb = Find(b-1);
			if (pa != pb) ufs[pa] = pb;
		}
		qsort(edges, e, sizeof(Edge), comp);
		printf("%.2lf\n", Kruskal());
	}
	return 0;
}