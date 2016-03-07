/*入门题。将每个人的出发和目标调换后，组成一个新的集合。排序比较两个集合是否一样。一样
  则满足条件，否则不满足。
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define INPUT stdin
#define OUTPUT stdout
#define NUM 500005
#define LEN 85
struct Point {
	int x, y;
};
Point org[NUM], res[NUM];
int comp(const void *a1, const void *a2)
{
	Point *p1, *p2;
	p1 = (Point *)a1;
	p2 = (Point *)a2;
	if (p1->x == p2->x) return p1->y-p2->y;
	return p1->x-p2->x;
}
int main()
{
	int i, n;
	while(1) {
		fscanf(INPUT, "%d", &n);
		if (n == 0) break;
		for(i=0; i<n; i++) {
			fscanf(INPUT, "%d %d", &org[i].x, &org[i].y);
			res[i].x = org[i].y;
			res[i].y = org[i].x;
		}
		qsort(org, n, sizeof(Point), comp);
		qsort(res, n, sizeof(Point), comp);
		for(i=0; i<n; i++) {
			if (org[i].x != res[i].x  || org[i].y != res[i].y)
				break;
		}
		if(i == n) fprintf(OUTPUT, "YES\n");
		else fprintf(OUTPUT, "NO\n");
	}
	return 0;
}