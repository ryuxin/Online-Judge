/*基础题。深搜回溯。没有剪枝会超时。有两点剪枝。
 *一、不和终点相连的顶点不必搜索。因此，可以先
 *用一遍DFS找出所有和终点连通的顶点。
 *二、有些顶点虽然和终点连通，但其到终点的路径
 *必须经过起点，这些顶点也可以排除。例如A-1-dest，
 *子图A到终点必须经过起点。为了找出这些顶点，可以
 *先把起点删除，再判断哪些顶点和终点连通。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 22
#define LEN (1<<12)
int graph[NUM][NUM], path[NUM];
int reach[NUM], dest;
long long int total;
static inline void Remove_one()
{
	int i;
	for(i=1; i<NUM; i++) {
		graph[i][1] += 2;
		graph[1][i] += 2;
	}
}
static inline void Restor_one()
{
	int i;
	for(i=1; i<NUM; i++) {
		graph[i][1] -= 2;
		graph[1][i] -= 2;
	}
}
void Flood(int k)
{
	int i;
	reach[k] = 1;
	for(i=1; i<NUM; i++) {
		if (1 != graph[k][i] || reach[i]) continue;
		Flood(i);
	}
}
void DFS(int k)
{
	int i = 0;
	if (k == dest) {
		total++;
		while(path[i] != dest) {
			printf("%d ", path[i]);
			i = path[i];
		}
		printf("%d\n", dest);
		return ;
	}
	for(i=1; i<NUM; i++) {
		if (!graph[k][i] || path[i] || !reach[i]) continue;
		path[k] = i;
		DFS(i);
	}
	path[k] = 0;
}
int main()
{
	int a, b, t = 1;
	while(1 == scanf("%d", &dest)) {
		total = 0;
		memset(graph, 0, sizeof(graph));
		memset(path, 0, sizeof(path));
		memset(reach, 0, sizeof(reach));
		path[0] = 1;
		while(scanf("%d%d", &a, &b)) {
			if (!a && !b) break;
			graph[a][b] = graph[b][a] = 1;
		}
		printf("CASE %d:\n", t);
		Remove_one();
		Flood(dest);
		Restor_one();
		DFS(1);
		printf("There are %lld routes from the firestation to streetcorner %d.\n", total, dest);
		t++;
	}
	return 0;
}