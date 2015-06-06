/*基础题。回溯搜索。求图的最大独立集。枚举每个节点是否在独立集中。
 *简单剪枝，保存剩余的节点数，若剩余节点数加上当前的解小于等于已找
 *到的最优解，则不用继续枚举了。当一个节点在集合中（为黑色）时，他
 *的相邻节点一定不能在集合中。用一个数组标记每个节点的状态，-1为未
 *确定，0是白或黑，正数是白色。注意回溯恢复状态时，也要恢复相邻节
 *点的状态。所以将相邻节点标记为当前的解的值，以便于确定要恢复哪些
 *节点的状态。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 10005
int graph[NUM][NUM], mid[NUM];
int color[NUM], re[NUM];
int best, left, n, cur;
void Backtrace(int k)
{
	int i, t, old_l;
	if (cur+left <= best) return ;
	left--;
	color[k] = 0;
	//染黑色
	mid[cur] = k;
	cur++;
	old_l = left;
	for(i=graph[k][0]; i>0; i--) {
		t = graph[k][i];
		if (color[t] == -1) {
			color[t] = cur;
			left--;
		}
	}
	if (!left) {
		if (cur > best) {
			best = cur;
			memcpy(re, mid, best*sizeof(int));
		}
	}
	for(i=n; i>0; i--) {
		if (color[i] == -1) {
			Backtrace(i);
			break;
		}
	}
	//恢复状态
	for(i=graph[k][0]; i>0; i--) {
		t = graph[k][i];
		if (color[t] == cur)
			color[t] = -1;
	}
	left = old_l;
	cur--;
	//染白色
	for(i=n; i>0; i--) {
		if (color[i] == -1) {
			Backtrace(i);
			break;
		}
	}
	//恢复状态
	color[k] = -1;
	left++;
	return ;
}
int main()
{
	int c, k, i, a, b;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &k);
		memset(graph, 0, sizeof(graph));
		memset(color, -1, sizeof(color));
		best = cur = 0;
		left = n;
		for(i=k; i>0; i--) {
			scanf("%d%d", &a, &b);
			graph[a][0]++;
			graph[a][graph[a][0]] = b;
			graph[b][0]++;
			graph[b][graph[b][0]] = a;
		}
		Backtrace(1);
		printf("%d\n%d", best, re[0]);
		a = best-(~best & 1);
		for(i=1; i<a; i=i+2) {
			printf(" %d %d", re[i], re[i+1]);
		}
		if (i<best)	printf(" %d\n", re[i]);
		else printf("\n");
	}
	return 0;
}