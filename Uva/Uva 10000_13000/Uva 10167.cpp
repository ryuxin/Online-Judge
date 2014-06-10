/*基础题。简单几何。将所有点以原点为中心按逆时针排序。排序依据是其
  与x轴正向的夹角，利用夹角余弦值和y坐标求夹角。
  排序后，依次检验可否点Pi和Pi+1之间切一刀。要满足的条件是，使得点
  Pi+1到Pi+n在一边，即直线也在点Pi+n和Pi+n+1之间。具体的，设点Pi和
  Pi+1关于原点对称的点是Pi'和Pi+1'， 则弧Pi+1'Pi'要和弧Pi+n+1Pi+n
  相交。则在相交区间内的任意一条直线均可。
  确定相交区间后，要找到穿过该区间的一条直线，简单的方法就是区间
  两个端点的向量之和。但当两向量共线时，要求与他们垂直的向量。
  另外，本题的规模很小，也可以枚举所有A,B，然后判断其是否把cake
  平分*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define PI 3.1415926
struct Point
{
	int x, y;
};
Point points[110];
int n;
int comp2(const void *a1, const void *a2)
{
	Point *p1, *p2;
	int d1, d2;
	p1 = (Point *)a1;
	p2 = (Point *)a2;
	double c1, c2;
	d1 = p1->x*p1->x+p1->y*p1->y;
	d2 = p2->x*p2->x+p2->y*p2->y;
	c1 = acos((double)p1->x/sqrt((double)d1));
	if (p1->y<0) c1 = 2*PI-c1;
	c2 = acos((double)p2->x/sqrt((double)d2));
	if (p2->y<0) c2 = 2*PI-c2;
	if (c1<c2) return -1;
	else if (c1>c2) return 1;
	else return d1-d2;
}
inline int comp3(Point *p1, Point *p2)
{
	int d;
	d = p1->x*p2->y-p2->x*p1->y;
	return -1*d;
}
bool coline(Point *px, Point *py)
{
	int a = px->x*py->x+px->y*py->y;
	a = a*a;
	int b = px->x*px->x+px->y*px->y;
	b = b*(py->x*py->x+py->y*py->y);
	if (a == b) return true;
	return false;
}
void Print(Point *px, Point *py)
{
	int x, y, d;
	if (coline(px, py)) {
		printf("%d %d\n", px->x, px->y);
		return ;
	}
	x = px->x+py->x;
	y = py->y+px->y;
	printf("%d %d\n", -1*y, x);
}
bool Check(int k)
{
	Point temp1, temp2;
	int r;
	temp1.x = -1*points[k].x;
	temp1.y = -1*points[k].y;
	r = comp3(&points[k+n-1], &temp1);
	if (r>=0) return false;
	temp2.x = -1*points[(k-1+2*n)%(2*n)].x;
	temp2.y = -1*points[(k-1+2*n)%(2*n)].y;
	r = comp3(&temp2, &points[k+n]);
	if (r>=0) return false;
	if (comp3(&temp1, &points[k+n]) >= 0) {
		if (comp3(&temp2, &points[k+n-1]) >= 0)
			Print(&points[k+n], &temp2);
		else 
			Print(&points[k+n], &points[k+n-1]);
	}
	else {
		if (comp3(&temp2, &points[k+n-1]) >= 0)
			Print(&temp1, &temp2);
		else 
			Print(&temp1, &points[k+n-1]);
	}
	return true;
}
int main()
{
	int i, t1, t2;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=0; i<2*n; i++) {
			scanf("%d %d", &t1, &t2);
			points[i].x = t1;
			points[i].y = t2;
		}
		if (n == 1) {
			Print(&points[0], &points[1]);
			continue;
		}
		qsort(points, 2*n, sizeof(struct Point), comp2);
		for(i=0; i<n; i++)
			if (Check(i))
				break;
	}
	return 0;
}