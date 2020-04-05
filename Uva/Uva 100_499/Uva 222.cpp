/*�����⡣�������ѡ���ÿ������վ�㣬���ж��Ƿ���Ҫͣ������Ҫ��������͵���������ʳ�Ŀ�����
 *����ö����һ������ͣ���ļ���վ��ע�����㣺
 *1.ÿ������վά�����յ����������������ǰ�������ڴ�ֵ���Ͳ��ؼ���������
 *2.��ÿ������վ�Ļ�����Ҫ�������뵽���֣�������ֻ�����������
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
	if (k == tot || you>=station[k].mina) {  // 1��
		if (cost<ming) ming = cost;
		return;
	}
	if (you*2>cap && you*mile_per>=station[k].nextd) return;
	cost += floor(200.5+(cap-you)*station[k].price); // 2��
	you   = cap;
	if (you*mile_per >= tar-station[k].dis) {
		if (cost<ming) ming = cost;
		return ;
	}
	// ö����һ������ͣ���ļ���վ
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
