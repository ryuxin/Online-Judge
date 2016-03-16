/*中等题。模拟。本题有两个性质：
 *1、若AB相撞，它们交换速度，则B可以看做是A仍以原速度继续行进，A也同理
 *2、若初始时A在B的右侧，最终A也一定在B的右侧，即任何两个不能交换位置
 *这样，可以利用性质1先求出所有最终停留的位置和朝向。然后对比最终和初始
 *状态的位置的顺序，以确定相应位置上是哪只蚂蚁，最后按照输入顺序输出每个
 *蚂蚁的最终状态。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 10
struct Ant {
	int num, loc, dir;
};
Ant old_ant[NUM], new_ant[NUM];
int order[NUM];
char direction[4][LEN] = {"L", "R", "Turning", "Fell off"};
int comp(const void *a1, const void *a2)
{
	Ant *p1, *p2;
	p1 = (Ant *)a1;
	p2 = (Ant *)a2;
	return p1->loc-p2->loc;
}
int main()
{
	int c, cases, l, t, n, i;
	char d;
	scanf("%d", &cases);
	for(c=1; c<=cases; c++) {
		scanf("%d%d%d", &l, &t, &n);
		new_ant[0].loc = new_ant[n+1].loc = -1;
		for(i=1; i<=n; i++) {
			scanf("%d %c", &old_ant[i].loc, &d);
			old_ant[i].num = i;
			if (d == 'L') old_ant[i].dir = 0;
			else old_ant[i].dir = 1;
		}
		for(i=1; i<=n; i++) {    //确定位置
			new_ant[i].loc = old_ant[i].loc+(2*old_ant[i].dir-1)*t;
			new_ant[i].dir = old_ant[i].dir;
		}
		qsort(&old_ant[1], n, sizeof(Ant), comp);
		qsort(&new_ant[1], n, sizeof(Ant), comp);
		for(i=1; i<=n; i++) {    //确定方向
			if (new_ant[i].loc<0 || new_ant[i].loc>l) {
				new_ant[i].dir = 3;
			} else if (new_ant[i].loc == new_ant[i+1].loc
					|| new_ant[i].loc == new_ant[i-1].loc) {
				new_ant[i].dir = 2;		
			}
		}
		for(i=1; i<=n; i++) {    //确定编号
			order[old_ant[i].num] = i;
		}
		printf("Case #%d:\n", c);
		for(i=1; i<=n; i++) {
			t = order[i];
			if (new_ant[t].dir == 3) printf("%s\n", direction[3]);
			else printf("%d %s\n", new_ant[t].loc, direction[new_ant[t].dir]);
		}
		printf("\n");
	}
	return 0;
}