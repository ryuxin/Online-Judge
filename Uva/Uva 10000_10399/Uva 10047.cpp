/*提高题。搜索，最短路。如果不考虑颜色，可以用DFS或者BFS来解决（貌似DFS不能处理本题
 *的规模）。但是有了颜色之后，我们可以在一条路径上用不同颜色经过同一个格子。这样就要
 *在状态中增加一维来维护颜色的信息。增加的一维使得状态数变得太大，以至于DFS太慢。这
 *要求把本题建模为图论问题。把每一个格子看做是图中的顶点，它和周围的格子有边相连，边
 *的长度就是到达相连顶点的时间。这样本题就是求图中两点间最短路径的问题。有三种方法：
 *1、Dijkstra算法。Dijkstra可以解决一般图中的最短路问题，所以肯定适合本题。其复杂度是
 *   O(NlgN+E)，相对较慢。我们需要一个优先队列和一个存储距离信息的数组，内存需求不高。
 *   但是有一个问题，我们可以从不同方向到达同一个状态，这会影响后续距离的计算。后面会
 *   解释怎么解决这个问题。
 *2、BFS。本题不能直接应用BFS，因为边的长度不同（由于转弯从一个点到其相邻点的时间不同）。
 *   但可以把方向信息作为一维加入状态中，把转弯和前进分为两步。这样在一个状态，我们只能
 *   转方向或前进一步。但这样变换后图中的所有边长度都是1，可以应用BFS。额外增加的一维
 *   使得状态数增加，因而内存需求增加，BFS时队列操作数也会增加。但其复杂度可将为O(N)。
 *3、多阶段的BFS。详细算法来自论文《有关“多阶段宽度优先搜索问题”的研究》。本题中每条
 *   边的长度只能是1、2和3。这正好符合应用多阶段BFS的条件。论文里说维护NK个队列，但由于
 *   一个点最多扩展K次，所以我们可以循环重用这些队列。这里我们维护四个队列，每个队列
 *   对应一种长度的边。第i次循环确定所有最短路长度为i的顶点，并将这些顶点加入到当前的队列。
 *   为此第i次循环时，把i-1队列中的所有顶点用长度为1的边扩展，i-2队列的点用长度为2的边扩
 *   展，以此类推。这样保证到当前扩展出来的顶点的距离都是i，而且所有最短距离为i的顶点都
 *   被扩展出来。虽然使用了多个队列，但需要入队的状态数量没有增加。所以时间和空间的开销
 *   都和直接的BFS相近。但它和Dijkstra算法有同样的问题。
 *方向的问题。考虑如下的格子“ASB”，起始位于S，面向北，颜色为0。经过5步后又会回到S，颜色
 *为2。但有两种路径（S->A->S，S->B->S），前者回到S时面向东，只需要1步就能到达B，而后者面
 *向西，还需两步到达B。在方法1和3中，我们会判断如果一个状态已经处理过，就不会再处理，导致
 *不能正确计算出到达B的最小距离。所以对于每一个状态不仅要存储其最短距离，还有保存此时的方
 *向信息。为了节省空间，可以将这两个信息编码到一个数字中。因为只有四种方向，对于方向d和距
 *离l，可编码为（d, l）<=> d+l*4。
 *测试结果表明优先队列最慢，要0.005秒，后两种算法时间相近，都是0.00秒
 *最后在BFS之前，先判断目标点是否可达。这里采用DFS进行判断。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 28
#define LEN 5
#define QNUM 4
#define QLEN (NUM*NUM*LEN/8)
struct Grid {
	int x, y, c, f;
};
struct Queue {
	int size;
	Grid queues[QLEN];
};
Queue myqueue[QNUM];
int visit[NUM][NUM][LEN];
char board[NUM][NUM];
int best, x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1}, tx, ty;
static void DFS(int xx, int yy)
{
	int i, nx, ny;
	if ((xx == tx && yy == ty) || best) {
		best = 1;
		return ;
	}
	visit[xx][yy][0] = 1;
	for(i=0; i<4; i++) {
		nx = xx+x[i];
		ny = yy+y[i];
		if (board[nx][ny] != '#' && !visit[nx][ny][0]) {
			DFS(nx, ny);
		}
	}
}
static inline void 
add_queue(int q, int x, int y, int c, int f, int cost)
{
	int s = myqueue[q].size, oc, of;
	Grid *temp = &myqueue[q].queues[s];
	oc = visit[x][y][c]/4;
	of = visit[x][y][c]%4;
	oc = (!oc) || (oc>=cost && of!=f);
	if (board[x][y] != '#' && oc) {
		temp->x = x;
		temp->y = y;
		temp->c = c;
		temp->f = f;
		myqueue[q].size++;
		visit[x][y][c] = cost*4+f;
		if (x == tx && y == ty && !c) best = 2;
	}
}
static inline void
clear_queue(int q)
{
	myqueue[q].size = 0;
}
static inline void
expand_node(Grid* node, int q, int n)
{
	int nx, ny, nf, nc, cost;
	nc = (node->c+1)%LEN;
	cost = visit[node->x][node->y][node->c]/4+n;
	nf = (node->f+n-1)%4;
	nx = node->x+x[nf];
	ny = node->y+y[nf];
	add_queue(q, nx, ny, nc, nf, cost);
	if (n == 2) {
		nf = (node->f+3)%4;
		nx = node->x+x[nf];
		ny = node->y+y[nf];
		add_queue(q, nx, ny, nc, nf, cost);
	}
}
//将队列s中所有元素用长度为n的边进行扩展，并扩展到队列t中
static inline void
expand_queue(int s, int t, int n)
{
	int i, size = myqueue[s].size;
	for(i=0; i<size; i++) {
		expand_node(&myqueue[s].queues[i], t, n);
	}
}
static void BFS(void)
{
	int q = 3, i;
	while ((myqueue[0].size+myqueue[1].size+myqueue[2].size+myqueue[3].size)
			&& best != 2) {
		clear_queue(q%QNUM);
		if (best != 2) expand_queue((q-1+QNUM)%QNUM, q%QNUM, 1);
		if (best != 2) expand_queue((q-2+QNUM)%QNUM, q%QNUM, 2);
		if (best != 2) expand_queue((q-3+QNUM)%QNUM, q%QNUM, 3);
		q++;
	}
}
int main()
{
	int c=0, i, j, m, n, sx, sy;
	for(i=0; i<NUM; i++) board[i][0] = board[0][i] = '#';
	while(1) {
		scanf("%d%d\n", &m, &n);
		if (m == 0) break;
		if (c) printf("\n");
		for(i=1; i<=m; i++) {
			scanf("%s", &board[i][1]);
			for(j=1; j<=n; j++) {
				visit[i][j][0] = 0;
				if (board[i][j] == 'S') {
					sx = i;
					sy = j;
				}
				if (board[i][j] == 'T') {
					tx = i;
					ty = j;
				}
			}
		}
		for(i=1; i<=n; i++) board[m+1][i] = '#';
		for(i=1; i<=m; i++) board[i][n+1] = '#';
		best = 0;
		DFS(sx, sy);
		if (best) {
			memset(visit, 0, sizeof(visit));
			clear_queue(0);
			clear_queue(1);
			clear_queue(2);
			add_queue(0, sx, sy, 0, 0, 0);
			expand_queue(0, 1, 1);
			expand_queue(0, 2, 2);
			expand_queue(1, 2, 1);
			BFS();
		}
		printf("Case #%d\n", ++c);
		if (!visit[tx][ty][0]) printf("destination not reachable\n");
		else printf("minimum time = %d sec\n", visit[tx][ty][0]/4);
	}
	return 0;
}