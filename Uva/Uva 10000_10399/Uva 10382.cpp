/*基础题。贪心。每个圆与矩形相交于左右两点。在能覆盖当前位置
 *的所有圆中，覆盖范围越大，即越靠右的越好。将所有圆按照与矩
 *形相交的左端点排序。依次扫描每个圆，在所有能覆盖当前位置，
 *即左端点小于等于当前位置的圆中，选取右端点最大的，其即为最
 *优选择，而其他能覆盖当前位置的圆以后也不可能选取，可直接滤
 *掉。若没有圆能覆盖当前位置， 则无解。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 10005
struct Circle {
	double left, right;
};
Circle points[NUM];
int comp(const void *a1, const void *a2)
{
	Circle *p1, *p2;
	p1 = (Circle *)a1;
	p2 = (Circle *)a2;
	if (p1->left < p2->left) return -1;
	else return 1;
}
int main()
{
	int n, i, re;
	double l, w, cur, t1, t2;
	while(scanf("%d%lf%lf", &n, &l, &w) == 3) {
		cur = w*w/4;
		for(i=0; i<n; i++) {
			scanf("%lf%lf", &t1, &t2);
			points[i].left = t1-sqrt(t2*t2-cur);
			points[i].right = 2*t1-points[i].left;
		}
		qsort(points, n, sizeof(struct Circle), comp);
		points[n].left = l+1;
		i = re = cur = t1 = 0;
		for(i=0; i<=n; i++) {
			if(points[i].left<=cur) {
				if (points[i].right>t1)
					t1 = points[i].right;
			} else {
				if (t1 == 0) break;
				re++;
				cur = t1;
				if (cur>=l) break;
				i--;
				t1 = 0;
			}
		}
		if (cur>=l) printf("%d\n", re);
		else printf("-1\n");
	}
	return 0;
}