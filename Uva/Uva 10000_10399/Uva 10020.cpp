/*基础题。贪心。先将线段按左端点排序。考虑从第k个线段开始覆盖区间[L, R]，
  找到能覆盖点L，且右端点最大的线段x，则存在一个最优解包含线段x。另外显然
  该题具有最优子结构性质。因此可依据上面的标准进行贪心。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 100005
#define LEN 105
struct Seg {
	int l, r;
};
Seg segs[NUM];
int m, n, total, re[NUM];
int comp(const void *a1, const void *a2)
{
	Seg *p1, *p2;
	p1 = (Seg *)a1;
	p2 = (Seg *)a2;
	if (p1->l == p2->l) return p2->r-p2->r;
	return p1->l-p2->l;
}
void Greedy(int s, int l)     //从segs[s]开始，覆盖[l, m]
{
	int i, r = l, t;
	if (l>=m) return ;
	if (segs[s].l>l) {
		total = 0;
		return ;
	}
	for(i=s; i<n; i++) {
		if (segs[i].r<l) continue;
		if (segs[i].l>l) {
			re[total++] = t;
			return Greedy(i, r);
		}
		if (segs[i].r>r) {
			r = segs[i].r;
			t = i;
		}
	}
	return ;
}
int main()
{
	int i, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &m);
		n = total = 0;
		while(1) {
			scanf("%d %d", &segs[n].l, &segs[n].r);
			if (segs[n].l == 0 && segs[n].r == 0) break;
			if (segs[n].r<segs[n].l || segs[n].r<0) continue;
			n++;
		}
		qsort(segs, n, sizeof(Seg), comp);
		segs[n].l = m+1;
		segs[n++].r = m+2;
		Greedy(0, 0);
		printf("%d\n", total);
		for(i=0; i<total; i++) printf("%d %d\n", segs[re[i]].l, segs[re[i]].r);
		if (t != 0) printf("\n");
	}
	return 0;
}