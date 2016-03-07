/*基础题。排序。设一个工作J = (t, f), t为时间，f为惩罚。
  对于j1 = (t1, f1), j2 = (t2, f2)。称j1<j2，若j1j2的
  惩罚小于j2j1的惩罚，即t1*f2<t2*f1。
  一个序列的惩罚最小的充要条件是，对任意两个相邻的工作，
  jk,jk+1，满足jk<jk+1。
  证明思路，若不满足，则交换两个相邻的工作，惩罚的变化
  为tk+1*fk-tk*<0，惩罚减小。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 1005
#define LEN 100
struct Job
{
	int t, f, id;
};
Job jobs[NUM];
int comp(const void *a1, const void *a2)
{
	Job *p1, *p2;
	p1 = (Job *)a1;
	p2 = (Job *)a2;
	if (p1->t*p2->f-p1->f*p2->t == 0)
		return p1->id-p2->id;
	return p1->t*p2->f-p1->f*p2->t;
}
int main()
{
	int c, i, n;
	scanf("%d", &c);
	while(c--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d%d", &jobs[i].t, &jobs[i].f);
			jobs[i].id = i+1;
		}
		qsort(jobs, n, sizeof(Job), comp);
		for(i=0; i<n-1; i++) printf("%d ", jobs[i].id);
		printf("%d\n", jobs[i].id);
		if (c != 0) printf("\n");
	}
	return 0;
}