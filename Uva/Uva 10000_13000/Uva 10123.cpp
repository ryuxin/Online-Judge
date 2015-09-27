/*基础题。深搜动规。若用搜索，则要枚举n!种的拿走顺序，暴搜肯定超时。
 *有一种剪枝方法时，将物体分为左右两组，且按从小到大排序，交替地从
 *左右两组开始拿。这里采用动规的办法。注意到是否满足题意只和当前在
 *木板上的物品状态有关，物品在木板上共有2^n个状态，因为n<=20, 所以
 *时间和空间都可以满足。用一个二进制数表示当前木板上物品的状态，dp[i]
 *表示状态为i时，是否可以一次拿走一个，并且一直保持平衡。则状态转移
 *方程dp[i] = dp[i1]||dp[i2]||...||dp[ik]，i1...ik为从状态i中拿走一个
 *物品后所得的状态。由于状态较多，采用自顶向下的搜索式动规，这样只需
 *计算那些会用到的状态，而且还能使用剪枝进行优化。
 *实现的代码中，按照倒过来的顺序实现。即考虑从空开始，依次将物品放在
 *木板上，结果表明，在题给数据下，这比按照一个一个往下拿的顺序快。这也
 *说明不同的搜索顺序，效率上会有很大差别。
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 1048600
#define LEN 22
struct pack {
	int pos, wei;
	float torqe;
};
pack packs[LEN];
char reach[NUM];
float ltoq, rtoq, tol_weight;
int total, path[LEN];
static inline int __log2(int k)
{
	int r = 0;
	while(k>2) {
		k >>= 2;
		r += 2;
	}
	return k+r-1;
}
static bool DFS(int pos, int k, float toq, int wei)
{
	int all = k, next, sel, tem_wei;
	float tem_toq, tem;
	while(1) {
		next = (all+1)^all;
		sel  = (next+1)>>1;
		all += sel;
		next = k+sel;
		sel  = __log2(sel);
		if (sel >= total) break;
		if (reach[next] == 'u') {
			tem_wei = wei+packs[sel].wei;
			tem_toq = toq+packs[sel].torqe;
			tem = -tem_toq/3;
			if (tem>=0 && tem<=tem_wei && DFS(pos+1, next, tem_toq, tem_wei)) 
				reach[next] = 'y';
			else reach[next] = 'n';
		}
		if (reach[next] == 'y') {
			path[pos] = sel;
			return true;
		}
	}
	reach[k] = 'n';
	return false;
}
int main()
{
	int i, c = 0;
	float len, weight, tem, toq;
	while(scanf("%f%f%d", &len, &weight, &total)) {
		if (len == 0 && weight == 0) break;
		c++;
		memset(reach+1, 'u', 1<<total);
		tol_weight = weight;
		for(i=0; i<total; i++) {
			scanf("%d%d", &packs[i].pos, &packs[i].wei);
			tol_weight += packs[i].wei;
			packs[i].torqe = packs[i].wei*((float)packs[i].pos-1.5);
		}
		tem = len/2-1.5;
		ltoq = tem/len*weight*tem/2;
		tem += 3;
		rtoq = -tem/len*weight*tem/2;
		toq = ltoq+rtoq;
		for(i=0; i<total; i++) toq += packs[i].torqe;
		tem = -toq/3;
		if (tem<0 || tem>tol_weight) {
			printf("Case %d:\nImpossible\n", c);
			continue;
		}
		reach[(1<<total)-1] = 'y';
		if (DFS(0, 0, ltoq+rtoq, weight)) {
			printf("Case %d:\n", c);
			for(i=total-1; i>=0; i--)
				printf("%d %d\n", packs[path[i]].pos, packs[path[i]].wei);
		} else printf("Case %d:\nImpossible\n", c);
	}
}