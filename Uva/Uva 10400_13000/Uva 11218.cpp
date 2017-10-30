/*入门题。回溯搜索。判断当前组合是否可取，若可以，则标记这
 *个组合里的人为已选，然后尝试下一个组合。直到没有组合可选
 *或组合数目超过3，返回失败；或者所有人都已选，更新最大分数。
 *解法2：集合枚举。用位集合表示组合，记录下集合对应的分数。
 *枚举前两个组合可能的集合，然后判断是否有集合包括剩下未选
 *的人，若有，则对应更新最大分数。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 3
struct Item {
	int num[LEN], score;
};
struct Item items[NUM];
int n, best, sum, vis[12];
static inline int
compitem(int *a, int *b)
{
	int i;
	for(i=0; i<LEN; i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}
	return 0;
}
static inline int 
comp(const void *a1, const void *a2)
{
	struct Item *p1 = (struct Item *)a1;
	struct Item *p2 = (struct Item *)a2;
	return compitem(p1->num, p2->num);
}
static inline void
mark(int *p, int v)
{
	vis[p[0]] += v;
	vis[p[1]] += v;
	vis[p[2]] += v;
}
static inline int
validate(int *a)
{ return !(vis[a[0]] || vis[a[1]] || vis[a[2]]); }
static void
DFS(int cs, int zs, int rs)
{
	int i, j;
	struct Item *pi;
	if (rs == 10) {
		if (sum > best) best = sum;
	} else if (vis[rs]) {
		for(i=rs+1; i<10; i++) if (!vis[i]) break;
		DFS(cs, zs, i);
	} else if (cs >= n || zs >= 3) return ;
	else if (items[cs].num[0] > rs) return ;
	else {
		for(i=cs; i<n; i++) {
			pi = &items[i];
			if (pi->num[0] == rs && validate(pi->num)) {
				mark(pi->num, 1);
				sum += pi->score;
				DFS(i+1, zs+1, rs+1);
				sum -= pi->score;
				mark(pi->num, -1);
			} else if (pi->num[0] > rs) break;
		}
	}
}
int main()
{
	int i, j, c=0;
	struct Item *pi;
	while(1) {
		scanf("%d", &n);
		if (!n) break;
		for(i=0; i<n; i++) {
			pi = &items[i];
			scanf("%d %d %d %d", &(pi->num[0]), &(pi->num[1]), 
				&(pi->num[2]), &(pi->score));
		}
		c++;
		best = -1;
		sum = 0;
		memset(vis, 0, sizeof(vis));
		qsort(items, n, sizeof(struct Item), comp);
		DFS(0, 0, 1);
		printf("Case %d: %d\n", c, best);
	}
	return 0;
}