/*难题。回溯搜索。本题需要较多的剪枝技巧。总体思路很简单，每个节点
 *只有选和不选两种可能，搜索所有的可能组合，找到所选节点最少的一个
 *方案。搜索顺序采用贪心的顺序，按照可以覆盖未被覆盖的点的数目对节
 *点排序。注意这个值一直在变，所以在每次搜索前，都要扫描一下剩余的
 *点并找到最好的点，作为搜索的起点。本题使用了如下剪枝技巧：
 *1. 每个连通分量至少要选一个节点。将图分解为连通子图，对每个连通
 *分量单独求解。以下优化都针对连通图。
 *2. 当有一个点和剩下的n-1或n-2个点相连，可以直接得到结果。
 *3. 若一个点只和另外一个点相连，可以直接忽略这个点。因为存在最优
 *解覆盖和它相连的那个点。
 *4. 确定至少要用几个点覆盖全图。当找到一个解等于它时，这个解即为
 *最优解，不必再搜索。
 *5. 当前已选定的点的数目大于等于当前最优解减一，不必搜索。因为不
 *可能得到更优的解。
 *6. 即使剩余的点都选，也不能覆盖全图（点的数目小于下界），停止搜索。
 *7. 按照贪心准则，决定搜索顺序。
 *8. 当剩余的点中，不能覆盖新的点，停止搜索。
 *9. 将回溯的尾递归优化为循环。
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 40
#define LEN 47000
/*cover[i]表示节点i能覆盖几个未被覆盖的节点。rank[i]表示节点i
 *被覆盖了几次。cur表示当前选中的节点的个数，best表示当前已得
 *到的最优结果，no表示还有几个节点未被覆盖，least表示至少要用
 *多少节点覆盖全图。*/
int cover[NUM], graph[NUM][NUM], vis[NUM];
int n, cur, best, no, least, node[NUM];
int num_node, rank[NUM];

int comp(const void *a1, const void *a2)
{
	int *p1 = (int *)a1;
	int *p2 = (int *)a2;
	int a = *p1, b = *p2;
	return cover[b]-cover[a];
}
static inline void Cover(int k)
{
	int i, *lst1, l1, *lst2, l2, j;
	rank[k]++;
	if (1 == rank[k]) {
		cover[k]--;
		no--;
		lst1 = graph[k];
		l1   = lst1[0];
		for(i=1; i<=l1; i++) cover[lst1[i]]--;
	}
}
static inline void Uncover(int k)
{
	int i, *lst1, l1, *lst2, l2, j;
	rank[k]--;
	if (!rank[k]) {
		cover[k]++;
		no++;
		lst1 = graph[k];
		l1   = lst1[0];
		for(i=1; i<=l1; i++) cover[lst1[i]]++;
	}
}
static void Backtrace(int k)
{
	int i, l, *lst, m, t;
	while (1) {
		if (!no || k == num_node) {
			if (!no && cur<best) best = cur;
			return ;
		}
		if (cur >= best-1) return ;           //剪枝5
		if (best == least) return ;
		if (cur+num_node-k < least) return ;  //剪枝6
		m = cover[node[k]];
		t = k;
		for(i=k+1; i<num_node; i++) {         //剪枝7
			if (cover[node[i]] > m) {
				m = cover[node[i]];
				t = i;
			}
		}
		if (m<=0) return;                     //剪枝8
		m       = node[t];
		node[t] = node[k];
		node[k] = m;
		lst     = graph[m];
		l       = lst[0];
		cur++;
		for (i=1; i<=l; i++) Cover(lst[i]);
		Cover(m);
		Backtrace(k+1);
		Uncover(m);
		for (i=1; i<=l; i++) Uncover(lst[i]);
		cur--;
		k++;
	}
}
static inline int solve_single(int *g, int num)
{
	int i, t=0;
	if (num < 4) return 1;
	qsort(g, num, sizeof(int),comp);
	//剪枝2
	if (cover[g[0]] >= num-1) return num-cover[g[0]]+1;
	no = num;
	for(i=num-1; i>=0; i--) if (cover[g[i]] != 2) break;
	num_node = num = i+1;   //剪枝3
	for(i=0; i<num; i++) {
		t += cover[g[i]];
		if (t >= num) break;
	}
	least = i+1;  //剪枝4
	best  = num;
	cur   = 0;
	Backtrace(0);
	return best;
}
static void DFS(int k)
{
	int i;
	vis[k] = 1;
	node[num_node++] = k;
	for(i=1; i<=graph[k][0]; i++) {
		if(vis[graph[k][i]]) continue;
		DFS(graph[k][i]);
	}
}
static int solve()
{
	int r = 0, i;
	for(i=1; i<=n; i++) {
		if (!vis[i]) {
			num_node = 0;
			DFS(i);  //剪枝1
			r += solve_single(node, num_node);
		}
	}
	return r;
}

int main()
{
	int i, m, a, b;
	while (scanf("%d%d", &n, &m)) {
		if (!m && !n) break;
		memset(vis, 0, sizeof(vis));
		for(i=n; i>0; i--) graph[i][0] = 0;
		for(i=0; i<m; i++) {
			scanf("%d%d", &a, &b);
			graph[a][0]++;
			graph[a][graph[a][0]] = b;
			graph[b][0]++;
			graph[b][graph[b][0]] = a;
		}
		memset(rank, 0, sizeof(int)*(n+1));
		for(i=0; i<=n; i++) cover[i] = graph[i][0]+1;
		a = solve();
		printf("%d\n", a);
	}
	return 0;
}
