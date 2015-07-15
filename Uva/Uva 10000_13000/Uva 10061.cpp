/*基础题。数学。先用筛法求出素数，在对整数进行质因数分解。
 *但最后不能用Stirling公式估计位数。两个原因使Stirling公式
 *精度有问题。当n很小时，Stirling公式误差大。另外要根据不同
 *的基数取对数，也会扩大误差。因此要对n！直接取对数。
 *浮点的精度需要控制，结果都要加上一个很小的数进行校正。*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 900
#define LEN 25
#define PI 3.141592653
#define E 2.7182818284 
int not_prime[NUM], prime[400];
static void inline filter_prime(int upper)
{
	int i, j, n = 0;
	memset(not_prime, 0, sizeof(not_prime));
	for(i=2; i<upper; i++) {
		if (!not_prime[i]) prime[n++] = i;
		for(j=0; j<n; j++) {
			if (i*prime[j]<upper) not_prime[i*prime[j]] = 1;
			if (i%prime[j] == 0) break;
		}
	}
}
/*结尾0的个数，就是n！最多可以被b的多少次幂整除。
 *先将b分解b = (p1^a1)(p2^a2)...(pk^ak)，然后分解n！
 *n！= (p1^t1)(p2^t2)...(pk^tk), 对应因子幂指数的比
 *值的最小值即为所求。*/
static int inline traling(int n, int b)
{
	int rm = 1<<31-1, i, t, pn, tn;
	for(i=0; prime[i]<=b; i++) {
		t = b; 
		tn = pn = 0;
		while (t%prime[i] == 0) {
			pn++;
			t /= prime[i];
		}
		if (!pn) continue;
		t = n;
		while (t) {
			tn += t/prime[i];
			t /= prime[i];
		}
		if (tn/pn < rm) rm = tn/pn;
		if (!rm) return rm;
	}
	return rm;
}
/*Stirling公式。n！~= sqrt(2npi)*(n/e)^n*/
static int inline totalbits(int n, int b)
{
	if (!n) return 1;
	double s=0;
	int i;
	for(i=2; i<=n; i++)
		s += log10((double)i);
	s /= log10((double)b);
	return (int)(s+1e-9)+1;
}
int main()
{
	int r1, r2, N, B;
	filter_prime(NUM);
	while (2 == scanf("%d%d", &N, &B)) {
		r1 = traling(N, B);
		r2 = totalbits(N, B);
		printf("%d %d\n", r1, r2);
	}
}