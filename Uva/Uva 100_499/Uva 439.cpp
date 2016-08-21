/*入门题。宽搜。马走日子，所以一个点周围有八个点相连。*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define NUM 12
#define LEN 40
#define DIR 8
struct gird {
	int x, y, d;
};
bool vis[NUM][NUM];
gird que[LEN];
int d1[DIR] = {-2, -1, 1, 2, 2, 1, -1, -2};
int d2[DIR] = {-1, -2, -2, -1, 1, 2, 2, 1};
int qh, qt, x1, x2, y1, y2;
static inline void enq(int x, int y, int d)
{
	que[qt].x = x;
	que[qt].y = y;
	que[qt].d = d;
	vis[x][y] = true;
	qt = (qt + 1)%LEN;
}
static inline gird *deq(void)
{
	gird *ret = &que[qh];
	qh = (qh + 1)%LEN;
	return ret;
}
static int BFS(void)
{
	gird *c;
	int i, x, y, d, tx, ty;
	while (qh != (qt+1)%LEN) {
		c = deq();
		x = c->x;
		y = c->y;
		d = c->d+1;
		if (x == x2 && y == y2) return d-1;
		for(i=0; i<DIR; i++) {
			tx = x+d1[i];
			ty = y+d2[i];
			if (!vis[tx][ty]) enq(tx, ty, d);
		}
	}
}
int main()
{
	int i;
	char s1[5], s2[5];
	while(scanf("%s%s", s1, s2) != EOF) {
		x1 = s1[0]-'a'+2;
		y1 = s1[1]-'1'+2;
		x2 = s2[0]-'a'+2;
		y2 = s2[1]-'1'+2;
		qh = qt = 0;
		memset(vis, 0, sizeof(vis));
		memset(vis, 1, 2*NUM*sizeof(bool));
		memset(vis[10], 1, 2*NUM*sizeof(bool));
		for(i=0; i<NUM; i++) vis[i][0] = vis[i][1] = vis[i][10] = vis[i][11] = 1;
		enq(x1, y1, 0);
		i = BFS();
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, i);
	}
	return 0;
}