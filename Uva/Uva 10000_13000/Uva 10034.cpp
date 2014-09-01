/*基础题。最小生成树。由于给出的是n个顶点的完全图，
  Prime算法比较适合。？？？
  Kruskal算法：对E个边排序要ElgE，并查集操作简单算为O(1)，
  则需要ElgE+E。
  Prime算法一定要使用邻接表，否则查找边就要V^2的时间。
  相对简单的实现是向堆中插入重复顶点，最坏情况插入的
  次数等于边的数目，所以插入和弹出的总时间为2ElgE。
  如果自己实现最小堆，可以避免插入重复顶点，弹出时间
  减小为VlgV，插入(修改)时间变为ElgV，此时才优于Kruskal。
  似乎看来Kruskal比较适合。。。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 105
#define LEN 100
struct Ver {
	int id;
	double dis;
	Ver(int i = 0, double d = 0)
	{
		id = i;
		dis = d;
	}
};
bool operator<(const Ver a, const Ver b)
{
	return a.dis>b.dis;
}
priority_queue<Ver> q;
struct Point {
	double x, y;
};
Point points[NUM];
int used[NUM], n;
double re;
inline double Dis(int a, int b)
{
	double t;
	t = (points[a].x-points[b].x)*(points[a].x-points[b].x);
	t+= (points[a].y-points[b].y)*(points[a].y-points[b].y);
	return sqrt(t);
}
void Prime(void)
{
	Ver v;
	int i;
	while(!q.empty()) {
		v = q.top();
		q.pop();
		if (used[v.id] == 1) continue;
		used[v.id] = 1;
		re += v.dis;
		for(i=0; i<n; i++) {
			if (used[i] == 1) continue;
			q.push(Ver(i, Dis(i, v.id)));
		}
	}
	return;
}
int main()
{
	int i, c;
	scanf("%d", &c);
	while(c--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%lf %lf", &points[i].x, &points[i].y);
			used[i] = 0;
		}
		re = 0;
		q.push(Ver(0, 0));
		Prime();
		printf("%.2lf\n", re);
		if (c != 0) printf("\n");
	}
	return 0;
}