/*典型题。BFS+贪心。首先，以给定的服务器为根，将无根树转为有根树。考虑深度
 *最深的未被覆盖的节点，覆盖它的最优方案一定在的k级祖先放一个服务器。
 *证明：设该叶节点是A，其k级祖先是B，要想覆盖A，服务器一定要放在B的子树下。
 *设服务器放在C，则C能覆盖的叶子，一定能被B覆盖。否则，A就不是深度最深的
 *叶节点。所以将服务器从C移到B，可以得到更优的结果。
 *先进行一次BFS，将叶节点按深度排序。从深度最深的叶子开始，放置服务器，同时
 *去除被覆盖的叶子。直至所有叶子都覆盖完。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 1005
#define LEN 160
int n, k, s, tree[NUM][NUM];
int q[NUM], tail, head, deep, num;
int leaf[NUM], len, use[NUM], total;
static inline void enq(int node)
{
	q[tail] = node;
	tail = (tail+1)%NUM;
}
static inline int deq(void)
{
	int t = q[head];
	head = (head+1)%NUM;
	return t;
}
//根节点也可能满足叶节点的条件，注意排除
static inline void BFS(void)
{
	int node, i, *tn;
	head = tail = len = 0;
	tree[s][0] = -1;
	for(i=2; i<tree[s][1]; i++) {
		enq(tree[s][i]);
		tree[tree[s][i]][0] = s;
	}
	while(head != tail) {
		node = deq();
		tn = tree[node];
		if (tn[1] == 3) leaf[len++] = node;
		else {
			for(i=2; i<tn[1]; i++) {
				if (tn[0] == tn[i]) continue;
				tree[tn[i]][0] = node;
				enq(tn[i]);
			}
		}
	}
	num = len;
}
static inline void BFS_k(int root)
{
	int node, i, *tn;
	head = tail = 0;
	deep = 1;
	for(i=2; i<tree[root][1]; i++) {
		enq(tree[root][i]);
		tree[tree[root][i]][NUM-1] = root;
	}
	enq(0);
	while(deep<=k && num) {
		node = deq();
		tn = tree[node];
		if (!node) {
			deep++;
			enq(0);
		} else if (tn[1] == 3) {
			num -= (!use[node]);
			use[node] = 1;
		} else {
			for(i=2; i<tn[1]; i++) {
				if (tn[NUM-1] == tn[i]) continue;
				enq(tn[i]);
				tree[tn[i]][NUM-1] = node;
			}
		}
	}
}
static void greedy(void)
{
	int node, d;
	while(num>0) {
		for(len=len-1; len>=0; len--) if (!use[leaf[len]]) break;
		node = leaf[len];
		for(d=k; d>0 && tree[node][0] != -1; d--) node = tree[node][0];
		total++;
		BFS_k(node);
	}
}
int main()
{
	int tcase, i, a, b;
	scanf("%d", &tcase);
	while(tcase--) {
		total = 0;
		scanf("%d %d %d",&n, &s, &k);
		for(i=0; i<=n; i++) tree[i][1] = 2;
		for(i=0; i<n-1; i++) {
			scanf("%d%d", &a, &b);
			tree[a][tree[a][1]++] = b;
			tree[b][tree[b][1]++] = a;
		}
		BFS();
		if (!k) total = num;
		else {
			memset(use, 0, sizeof(use));
			BFS_k(s);
			greedy();
		}
		printf("%d\n", total);
	}
	return 0;
}