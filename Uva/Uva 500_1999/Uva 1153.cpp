#include "ryx_binary_heap.h"
/*
 *中等题。贪心。完成的订单最多，且总完成时间最短的解为最优解。下面证明
 *其满足最优解结构。所有订单按结束时间升序排序。给定前i-1个订单的最优
 *解Si-1，若加入第i个订单后，仍能按时完成，则前i个订单的最优解就为
 *Si = Si-1 + i。若不能，则查看Si-1中耗时最长的订单j，若其用时比第i个
 *订单长，则将其替换为i，即Si = Si-1 - j + i；否则，Si = Si-1。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 800005
#define LEN 1000005
struct Job {
	int q, d;
};
Job orders[NUM];
RYX_Binary_heap myheap;
static inline int comp(const void *a1, const void *a2)
{
	Job *p1, *p2;
	p1 = (Job *)a1;
	p2 = (Job *)a2;
	return p1->d-p2->d;
}
int main()
{
	int c, n, i, cur, r, m, t;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) scanf("%d%d", &orders[i].q, &orders[i].d);
		qsort(orders, n, sizeof(Job), comp);
		Binary_heap_clear(&myheap);
		for(i=0, cur=0, r=0; i<n; i++) {
			t = orders[i].q;
			if (t > orders[i].d) continue;
			if (cur+t <= orders[i].d) {
				r++;
				Binary_heap_add(&myheap, t);
				cur += t;
			} else {
				m = Binary_heap_top(&myheap);
				if (m > t) {
					Binary_heap_pop(&myheap);
					Binary_heap_add(&myheap, t);
					cur += t-m;
				}
			}
		}
		if (c) printf("%d\n\n", r);
		else printf("%d\n", r);
	}
	return 0;
}