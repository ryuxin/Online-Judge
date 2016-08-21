/*基础题。宽搜。re[i]表示i至少有多少能量才能到终点。从终点开始逆向搜索，进行BFS，若i
 *与j相连，则re[j] = re[i]-i的能量。当找到更小的re[i]时，就要对i及其相连的节点松弛。
 *当re[i]<=0，令re[i] = 1， 因为节点上不能出现负能量。不过这个算法非常慢！！！！*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 105
#define LEN 5000
struct node {
	int id, e;
};
node queue[LEN];
int graph[NUM][NUM], re[NUM], head, tail;
static inline void enq(int id, int e)
{
	if (re[id] <= e) return ;
	queue[tail].id = id;
	queue[tail].e  = e;
	re[id] = e;
	tail = (tail+1)%LEN;
}
static inline node *deq(void)
{
	int t = head;
	head = (head+1)%LEN;
	return &queue[t];
}
static inline void BFS(void)
{
	node *n;
	int id, e, i, t, l;
	while(head != tail) {
		if (re[1] <= 100) return ;
		n  = deq();
		id = n->id;
		e  = n->e;
		if (e<=re[id]) {
			l = graph[id][1];
			t = e-graph[id][0];
			if (t<=0) t = 1;
			for(i=2; i<l; i++) enq(graph[id][i], t);
		}
	}
}
int main()
{
	int i, n, l, j, t;
	while(scanf("%d", &n)) {
		if (n == -1) break;
		head = tail = 0;
		for(i=0; i<=n; i++) re[i] = 1000000;
		for(i=0; i<=n; i++) graph[i][1] = 2;
		for(i=1; i<=n; i++) {
			scanf("%d%d", &graph[i][0], &l);
			for(j=0; j<l; j++) {
				scanf("%d", &t);
				graph[t][graph[t][1]] = i;
				graph[t][1]++;
			}
		}
		enq(n, 1);
		BFS();
		if (re[1] <= 100) printf("winnable\n");
		else printf("hopeless\n");
	}
	return 0;
}