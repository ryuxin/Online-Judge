/*基础题。数学。设集合S={a1，a2，……ak}，由算术基本定理，每个数
 *都可以唯一被分解为ak = p1^ak1*p2^ak2*...*pn^akn, 则它们的最小
 *公倍数M = p1^max(a11, a21...ak1)*...*pn^max(a1n, a2n...akn)。
 *因此设题目输入为N， 且N = p1^a1*...*pn^an.若N为S的最小公倍数，
 *则N的每个成分ai^pi都要在S中出现。显然当且仅当每个成分都出现
 *一次，且独立成为一个数时，S的总和最小。
 *先用筛法求出所有素数，再求出N的每个成分。输出要注意是无符号！
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 47000
#define LEN 47000
unsigned int number[NUM] = {0}, prime_cnt = 0;

static inline void Prime_filter()
{
	unsigned int i, j;
	for(i=2; i<NUM; i++) {
		if (!number[i]) {
			number[prime_cnt] = i;
			prime_cnt++;
		}
		for(j=0; j<prime_cnt; j++) {
			if (number[j]*i >= NUM) break;
			number[number[j]*i] = 1;
			if (i%number[j] == 0) break;
		}
	}
}
static inline unsigned int
Appear_time(unsigned int n, unsigned int f)
{
	unsigned int r = 1;
	while (n%f == 0){
		r *= f;
		n/= f;
	}
	return r;
}

int main()
{
	unsigned int n, i, r, t = 0, c, tn;
	Prime_filter();
	while(1) {
		scanf("%u", &n);
		if (!n) break;
		t++;
		if (n == 1) {
			printf("Case %d: 2\n", t);
			continue;
		}
		r = i = 0;
		tn = n;
		while (n!=1) {
			c = n;
			for(; i<prime_cnt; i++) {
				if (n%number[i] == 0) {
					c = number[i];
					break;
				}
			}
			c = Appear_time(n, c);
			r += c;
			n /= c;
		}
		if (r == tn) r++;
		printf("Case %d: %u\n", t, r);
	}
	return 0;
}