/*基础题。数学题。因为k存在两种分解方式，所以其至少有三个质因数。
 *这些质因数可能相同或不同，例如16=2^4, 12=3*2*2,且最小的质因数
 *一定小于k的1/3次方，最小的两个质因数小于k的2/3次方。先用筛法
 *求出该范围内的所有质数。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 46500
#define LEN 120
int prime[NUM], total;
static inline int filter_prime()
{
	int i, c=0, j;
	memset(prime, 0, sizeof(prime));
	for(i=2; i<NUM; i++) {
		if (!prime[i]) prime[c++] = i;
		for(j=0; j<c; j++) {
			if (prime[j]*i >= NUM) break;
			prime[prime[j]*i] = 1;
			if (i%prime[j] == 0) break;
		}
	}
	return c;
}
int main()
{
	int i, n, f1, f2, j, k, t;
	total = filter_prime();
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%d", &k);
		for(j=0; j<NUM; j++) {
			if (k%prime[j] == 0) {
				f1 = prime[j];
				break;
			}
		}
		t = k/f1;
		for(; j<NUM; j++) {
			if (t%prime[j] == 0) {
				f2 = f1*prime[j];
				break;
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n", i, k, f1, k/f1, f2, k/f2);
	}
	return 0;
}