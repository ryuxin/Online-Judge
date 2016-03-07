/*典型题。贪心。第一个人尽量从离他最近的人买（卖）。假设第一个要买，
				a......B......C
  如上图，假设离a最近的卖的人是B。则一定存在一个最优解，使得a从B买。
  证明：若一个最优解中a是从C买，则另外有一个人x买了B的。考虑x的可能位置。
  			（1）	a..x....B......C..
			（2）	a......B...x...C..
			（3）	a......B......C..x
  在（1）中，|aB|+|xC| = |aB|+|xB|+|BC| = |aC|+|xB|
  在（2）中，|aB|+|xC| < |aC|<|aC|+|xB|
  在（3）中，|aB|+|xC| < |ax|<|aC|+|Cx|+|BC| = |aC|+|xB|.
  在所有情况中，都可以构造出一个最优解，且a从C买。
  具体实现要很高的技巧。买的人就是卖个负值，但需要移动的总量都是一样的。
  假设第一个卖，则不论第二个人是买是卖，第一个人的都至少要移动到第二个人处。
  但在第二个人处剩了多少，则取决于第二个是买还是卖。
  若第二个人仍然是卖，则他们的堆积在一起卖给后面的人。
  若第二个人是买，则剩余的量就是其买完后剩余的量。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 100000
#define LEN 15
//short int data[NUM];
int main()
{
	int i, n /*j, pp, pn*/;
	long long int re;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		re = 0;
		/*for(i=n-1; i>=0; --i) scanf("%hd", &data[i]);
		pp = pn = n-1;
		for(i=n-1; i>=0; --i) {
			if (data[i] == 0) continue;
			if (data[i]>0) {
				for(; pp>=0; --pp) {
					if (data[pp]>=0) continue;
					if (data[i]+data[pp]>0) {
						data[i] += data[pp];
						re += abs((pp-i)*data[pp]);
						data[pp] = 0;
					}
					else {
						data[pp] += data[i];
						re += abs((i-pp)*data[i]);
						data[i] = 0;
						break;
					}
				}
			}
			else {
				for(; pn>=0; --pn) {
					if (data[pn]<=0) continue;
					if (data[pn]+data[i]<0) {
						data[i] += data[pn];
						re += abs((i-pn)*data[pn]);
						data[pn] = 0;
					}
					else {
						data[pn] += data[i];
						re += abs((pn-i)*data[i]);
						data[i] = 0;
						break;
					}
				}
			}
		}*/
		int cur = 0, t;
		for(i=0; i<n; ++i) {
			re += abs(cur);       //前面剩余的至少要移动到此
			scanf("%d", &t);
			cur += t;             //前面剩余的和当前的进行交易，更新剩余值
		}
		printf("%lld\n", re);
	}
	return 0;
}