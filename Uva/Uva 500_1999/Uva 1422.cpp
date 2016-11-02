/*中等题。二分+贪心。二分枚举处理器最大速度，判断该速度能否完成所有任务。
 *判断时有两个贪心策略：处理器可以一直保持最大速度，优先处理结束时间早的
 *任务。准备两个队列，一个按开始时间排序，另外一个以结束时间作为优先级的
 *优先队列。维护当前时间，将已开始的任务加入到优先队列。根据下一个时间点，
 *得到处理器在这段时间内能完成的工作量。依次处理优先队列中的任务，直到下
 *一个时间点，或者优先队列为空，或者发现一个任务不能按时完成。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 160
#define prio(a) (back[heap.item[a]].d)
struct Processor {
	int r, d, w;
};
struct bin_heap {
	int n, item[NUM];
};
Processor proc[NUM], back[NUM];
bin_heap heap;
int n;
static inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
static inline void heap_swap(int a, int b)
{
	int t;
	t = heap.item[a];
	heap.item[a] = heap.item[b];
	heap.item[b] = t;
}
static inline void __fix_up(void)
{
	int c, p;
	c = heap.n-1;
	p = (c-1)/2;
	while (c && prio(c) < prio(p)) {
		heap_swap(c, p);
		c = p;
		p = (c-1)/2;
	}
}
static inline void __fix_down(void)
{
	int c, s1, s2, s, p;
	c = 0;
	while (2*c+1 < heap.n) {
		s1 = 2*c+1;
		s2 = s1+1;
		p = prio(s1);
		if (s2 < heap.n && prio(s2) < p) {
			s = s2;
			p = prio(s2);
		} else s = s1;
		if (p>=prio(c)) break;
		heap_swap(c, s);
		c = s;
	}
}
static inline void heap_add(int a)
{
	heap.item[heap.n++] = a;
	__fix_up();
}
static inline int heap_pop(void)
{
	int r = heap.item[0];
	heap.item[0] = heap.item[--heap.n];
	__fix_down();
	return r;
}
static inline int heap_top(void)
{
	if (!heap.n) return -1;
	return heap.item[0];
}
static inline int comp(const void *a1, const void *a2)
{
	Processor *p1 = (Processor *)a1;
	Processor *p2 = (Processor *)a2;
	return p1->r-p2->r;
}
static inline bool check(int k)
{
	int i, cur, top, end;
	long long int left;
	memcpy(back, proc, n*sizeof(Processor));
	heap.n = i = 0;
	while (1) {
		top = heap_top();
		if (i>=n && top == -1) break;
		//维护当前时间
		if (top == -1) cur = back[i].r;
		//将可以开始的任务加入优先队列
		for(; i<n; i++) {
			if (back[i].r <= cur) heap_add(i);
			else break;
		}
		top = heap_top();
		if (back[top].d <= cur) return false;
		//确定下一个时间点
		if (i<n && back[i].r < back[top].d) end = back[i].r;
		else end = back[top].d;
		//此处32位会溢出。它的上限是时间跨度*所有任务的工作总量
		left = (long long int)k*(end-cur);
		while(left && top != -1) {
			if (back[top].d <= cur) return false;
			if ((long long int)back[top].w > left) {
				back[top].w -= left;
				left = 0;
			} else {
				left -= (long long int)back[top].w;
				heap_pop();
				top = heap_top();
			}
		}
		cur = end;
	}
	return true;
}
static inline int binary(int l, int r)
{
	int m;
	while (l<r) {
		m = (l+r)/2;
		if (check(m)) r = m;
		else l = m+1;
	}
	return l;
}
int main()
{
	int t, i, r, l;
	scanf("%d", &t);
	while (t--) {
		l = r = heap.n = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d%d%d", &proc[i].r, &proc[i].d, &proc[i].w);
			r += proc[i].w;
			l = mymax(l, proc[i].w/(proc[i].d-proc[i].r));
		}
		qsort(proc, n, sizeof(Processor), comp);
		r = binary(l, r);
		printf("%d\n", r);
	}
}