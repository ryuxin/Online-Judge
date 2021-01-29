/*中等题。动规，数学。本题的第一个复杂点在于因子可以是负数。
 *为此，可先求出因子只能是正数时的方法数f(x，y)，然后再考虑
 *为这些y个因子添加正负号，使得最终的乘积为正。令添加正负号
 *的方法数为g(y)。第二个复杂点需要筛法求出所有质数，和每个数
 *的最小质因数。
 *下面计算f(x，y)。将x做质因数分解，得
 *x = (p1^n1)(p2^n2)……(pk^nk) = P1*P2*……*Pk，易知：
 *f(x，y) = f(P1，y)*f(P2，y)*……*f(Pk，y)
 *显然f(Pi，y)只与pi的幂指数有关，而与具体的pi值无关。
 *设h(k, y)为对任意质数p，f(p^k, y)的值。则有：
 *f(x, y) = h(n1, y)*h(n2, y)*……*h(nk, y)
 *有两种办法求解h。第一，运用组合数，可直接得
 *h(k, y) = C(k+y-1, y-1)，具体证明见
 *https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
 *第二使用动规。考虑第一个因子，它有包含于不包含p的两种情况。
 *若不包含p（即因子是1），则相应的方法数为h(k, y-1);
 *若包含p（即至少使用了一个p），则相应的方法数为h(k-1, y)
 *综上h(k, y) = h(k, y-1) + h(k-1, y)
 *下面求g(y)。放正负号的总方法数为2^y，他们的乘积只有1和-1，
 *且二者对应的方法数相等。可得g(y) = 2^(y-1)
 *最后得最终答案
 *F(x, y) = f(x, y)*g(y)
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

#define NUM 1000005
#define LEN 20
#define MOD 1000000007
int dp[LEN][NUM]= { 0 }, sieve[NUM] = { 0 }, p2[NUM];
vector<int> prs;
static inline void
Sieve(int n)
{
	for(int i=2; i<n; i++) {
		if (sieve[i] == 0) {
			prs.push_back(i);
			sieve[i] = i;
		}
		for(int j=0; j<prs.size(); j++) {
			if (i*prs[j]<n) sieve[i*prs[j]] = prs[j];
			else break;
			if (i % prs[j] == 0) break;
		}
	}
}
static inline int getpn(int n, int p, int *r)
{
	int ret = 0;
	while (n % p == 0) {
		ret++;
		n /= p;
	}
	*r = n;
	return ret;
}
static inline void DP(void)
{
	int i, j;
	for(i=1; i<LEN; i++) {
		for(j=1; j<NUM; j++) {
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
		}
	}
}
int main()
{
	int i, j, q, x, y;
	for(p2[0]=1, i=1; i<NUM; i++) p2[i] = (2*p2[i-1]) % MOD;
	Sieve(NUM);
	for(i=1; i<NUM; i++) dp[0][i] = 1;
	for(i=0; i<LEN; i++) dp[i][0] = 0;
	DP();
	scanf("%d", &q);
	for(i=0; i<q; i++) {
		scanf("%d%d", &x, &y);
		long long r = 1;
		while (x > 1) {
			int t = getpn(x, sieve[x], &x);
			r = (r * dp[t][y]) % MOD;
		}
		r = (r * p2[y-1]) % MOD;
		printf("%lld\n", r);
	}
	return 0;
}
