/*基础题。DFS。对于图中每个连通分量，只需通知其代价
 *最小的节点。找到所有连通分量的最小值并相加，即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define NUM 100005
#define LEN 4005
vector<int> graph[NUM];
int num[NUM];
static int DFS(int k)
{
	int t, i, r = num[k];
	num[k] = -1;
	for(i=0; i<graph[k].size(); i++) {
		t = graph[k][i];
		if (num[t] != -1) r = min(r, DFS(t));
	}
	return r;
}
int main()
{
	int i, n, m, a, b;
	long long r = 0;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++) scanf("%d", num+i);
	for(i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(i=1; i<=n; i++) {
		if (num[i] != -1) r += DFS(i);
	}
	printf("%lld\n", r);
	return 0;
}
