/*入门题。数学，最大公约数。题目大意：已知n中硬币，对于给定的高度，
 *求用这些硬币构建的桌子中，与之最接近，分别大于和小于它的两个高度。
 *枚举构建桌子的硬币的组合，对每一种组合的4类硬币，其能构建的高度
 *是它们最小公倍数的倍数。再从这些倍数中确定与目标最接近的两个数。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 55
#define LEN 12
struct Table {
	int high, small, large;
};
int thick[NUM], nthick, ntable;
bool use[NUM];
Table tables[LEN];
static inline int
GCD(int a, int b)
{
	int t;
	while(b) {
		t = a;
		a = b;
		b = t%b;
	}
	return a;
}
static inline int
GCM(int a, int b)
{
	if (a%b== 0) return a;
	else if (b%a) b = a*b/GCD(a, b%a);
	return b;
}
static void DFS(int gcm, int num, int start)
{
	int i, t;
	if (num == 5) {
		for(i=0; i<ntable; i++) {
			t = tables[i].high/gcm*gcm;
			if (t>tables[i].small) tables[i].small = t;
			t = (tables[i].high+gcm-1)/gcm*gcm;
			if (t<tables[i].large) tables[i].large = t;
		}
		return ;
	}
	for(i=start; i<nthick+num-4; i++) {
		if (use[i]) continue;
		use[i] = true;
		t = GCM(gcm, thick[i]);
		DFS(t, num+1, i+1);
		use[i] = false;
	}
}
int main()
{
	int i;
	memset(use, 0, sizeof(use));
	while(scanf("%d %d", &nthick, &ntable)) {
		if (!nthick) break;
		for(i=0; i<nthick; i++) scanf("%d", &thick[i]);
		for(i=0; i<ntable; i++) {
			scanf("%d", &tables[i].high);
			tables[i].large = (1<<30);
			tables[i].small = 0;
		}
		DFS(1, 1, 0);
		for(i=0; i<ntable; i++) printf("%d %d\n", tables[i].small, tables[i].large);
	}
	return 0;
}