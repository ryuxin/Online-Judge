/*入门题。数学。对于多项式(x1+...+xk)^n，其展开后每一项可表示
 *为E*(x1^a1)*...*(xk^ak)，其满足a1+...+ak = n，E为系数，
 *E = C(n, a1)*C(n-a1, a2)*...C(n-a1-...-a(k-1), ak)，
 *C(m,n)为组合数，化简后有E = n!/(a1!*...*ak!)。有地推公式
 *C(m,n) = C(m-1, n)+C(m-1, n-1)求出所有组合数，并存在表中。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 14
#define LEN 5
int zuhe[NUM][NUM+1];
static inline void 
Init(void)
{
	int i, j;
	for(i=0; i<=NUM; i++) zuhe[i][0] = zuhe[i][i] = 1;
	for(i=2; i<=NUM; i++) {
		for(j=1; j<=i/2; j++) {
			zuhe[i][j] = zuhe[i][i-j] = zuhe[i-1][j-1]+zuhe[i-1][j];
		}
	}
}
int main()
{
	int i, n, k, r, t;
	Init();
	while(scanf("%d %d", &n, &k) != EOF) {
		r = 1;
		for(i=0; i<k; i++) {
			scanf("%d", &t);
			r *= zuhe[n][t];
			n -= t;
		}
		printf("%d\n", r);
	}
	return 0;
}