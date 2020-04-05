/*基础题。回溯深搜。在每个加油站点，先判断是否需要停。若需要，计算加油的量和买零食的开销。
 *并且枚举下一个可能停靠的加油站。注意两点：
 *1.每个加油站维护到终点的最少油量，若当前油量大于此值，就不必继续搜索；
 *2.在每个加油站的花销都要四舍五入到美分，而不是只近似最后结果。
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

#define NUM 55
#define LEN 55
struct Gas {
	float dis, price, mina, nextd;
};
struct Gas station[NUM];
float tar, cap, mile_per, ming;
int tot;
static void
DFS(int k, float you, float cost)
{
	int i;
	float dis;
	if (k == tot || you>=station[k].mina) {  // 1点
		if (cost<ming) ming = cost;
		return;
	}
	if (you*2>cap && you*mile_per>=station[k].nextd) return;
	cost += floor(200.5+(cap-you)*station[k].price); // 2点
	you   = cap;
	if (you*mile_per >= tar-station[k].dis) {
		if (cost<ming) ming = cost;
		return ;
	}
	// 枚举下一个可能停靠的加油站
	for(i=k+1; i<=tot; i++) {
		dis = station[i].dis - station[k].dis;
		if (you*mile_per < dis) break;
		DFS(i, you-dis/mile_per, cost);
	}
	return ;
}
int main()
{
	int i, kase = 0;
	float init_c, maxt;
	while (1) {
		scanf("%f", &tar);
		if (tar < 0) break;
		scanf("%f%f%f%d", &cap, &mile_per, &init_c, &tot);
		for(maxt=0, i=0; i<tot; i++) {
			scanf("%f%f", &station[i].dis, &station[i].price);
			station[i].mina = (tar-station[i].dis)/mile_per;
			if (station[i].price > maxt) maxt = station[i].price;
		}
		ming             = maxt*(tar/mile_per) + 200*tot;
		station[tot].dis = tar;
		for(i=0; i<tot; i++) station[i].nextd = station[i+1].dis - station[i].dis;
		for(i=0; i<=tot; i++) {
			if (cap*mile_per < station[i].dis) break;
			DFS(i, cap-station[i].dis/mile_per, 0);
		}
		ming += init_c*100;
		printf("Data Set #%d\nminimum cost = $%.2f\n", ++kase, ming/100);
	}
	return 0;
}
