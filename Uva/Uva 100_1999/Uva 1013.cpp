/*基础题。最小生成树。另外由于所有线路同时开工，一个节点的连通时间取决于
  其到根节点路径上最长的线路。具体的，一个节点的线路比其父节点的线路长，
  则他的完工时间就是他线路的长度，否则是其父亲线路的长度。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 55
#define LEN 28
struct Island {
	double x, y;
	int num;
};
Island islands[NUM];
double len[NUM], p[NUM], total;
int used[NUM], n;
inline double dis(int k, int l)
{
	double x, y;
	x = fabs(islands[k].x-islands[l].x);
	y = fabs(islands[k].y-islands[l].y);
	return sqrt(x*x+y*y);
}
int pop(void)
{
	int i, r;
	double m;
	for(i=0; i<n; i++)
		if (used[i] == -1) {
			r = i;
			m = len[i];
			break;
		}
	for(; i<n; i++) {
		if (used[i] == -1) {
			if (len[i]<m) {
				m = len[i];
				r = i;
			}
		}
	}
	return r;
}
void Kurskal(void)
{
	int i, t, j;
	double temp;
	for(i=1; i<n; i++) {
		t = pop();
		used[t] = 0;
		total += p[t]*islands[t].num;
		for(j=0; j<n; j++) {
			if (used[j] == 0) continue;
			temp = dis(t, j);
			if (temp<len[j]) {
				len[j] = temp;
				if (len[j] <p[t]) p[j] = p[t];
				else p[j] = len[j];
			}
		}
	}
	return ;
}
int main()
{
	int c = 0, i, j;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		c++;
		for(i=0; i<n; i++) {
			scanf("%lf%lf%d", &islands[i].x, &islands[i].y, &islands[i].num);
			used[i] = -1;
		}
		len[0] = used[0] = total = j = p[0] = 0;
		for(i=1; i<n; i++) len[i] = p[i] = dis(i, 0);
		Kurskal();
		for(i=0; i<n; i++) j += islands[i].num;
		printf("Island Group: %d Average %.2lf\n\n", c, total/j);
	}
	return 0;
}