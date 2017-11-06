/*基础题。搜索。由于计算器只有n位，而我们可以无限次操作，因此一
 *定会出现以前的结果，进而开始循环。所以记录所有操作的最大值，当
 *发现循环时，当前的最大值就是最终结果。判断循环采用Brent算法。
 *但有一个问题尚未解决，这个循环的周期可以非常大（10^n），
 *可惜不知道有没有数学证明来确定这个周期的大小。！！
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 100005
#define LEN 105
long long int upper;
static inline int
mmax(int a, int b)
{ return a > b? a: b; }
static inline int
gen(int n)
{
	long long int r, a;
	a = (long long int)n;
	r = a*a;
	while (r >= upper) {
		r /= 10;
	}
	return (int)r;
}
int main()
{
	int kase, k, n, best, i, slow, fast, len, b;
	scanf("%d", &kase);
	while (kase--) {
		scanf("%d %d", &n, &k);
		for(i=0, upper=1; i<n; i++) upper *= 10;
		best = fast = k;
		len = b = 1;
		do {
			slow = fast;
			len *= 2;
			for(i=0; i<len; i++) {
				fast = gen(fast);
				best = mmax(fast, best);
				if (fast == slow || best == (int)upper -1) {
					b = 0;
					break;
				}
			}
		} while (b);
		printf("%d\n", best);
	}
	return 0;
}