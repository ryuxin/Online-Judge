/*基础题。回溯搜索。记录每站的车的容量和当前的盈利。枚举每个订单
  接受或拒绝。当且仅当一个订单途径的所有站都不超载时，可以接受。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 10
#define LEN 25
struct Order {
	int l, r, c;
};
Order orders[LEN];
int n, m, num, cap[NUM], cur, best;
void Backtrace(int k)
{
	if (k == num) {
		if (cur > best) best = cur;
		return ;
	}
	bool can = true;
	int i;
	for(i=orders[k].l; i<orders[k].r; i++) {
		cap[i] += orders[k].c;
		if (cap[i] > n) {
			for(; i>=orders[k].l; i--) cap[i] -= orders[k].c;
			can = false;
			break;
		}
	}
	if (can) {
		cur += orders[k].c*(orders[k].r-orders[k].l);
		Backtrace(k+1);
		cur -= orders[k].c*(orders[k].r-orders[k].l);
		for(i=orders[k].l; i<orders[k].r; i++) cap[i] -= orders[k].c;
	}
	Backtrace(k+1);
	return ;
}
int main()
{
	int i;
	while(scanf("%d%d%d", &n, &m, &num)>0) {
		if (n == 0) break;
		for(i=0; i<num; i++) scanf("%d%d%d", &orders[i].l, &orders[i].r, &orders[i].c);
		for(i=0; i<m; i++) cap[i] = 0;
		cur = best = 0;
		Backtrace(0);
		printf("%d\n", best);
	}
	return 0;
}