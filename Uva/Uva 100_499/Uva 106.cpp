/*中等题。数学。数论。方程x^2+y^2 = z^2的解中，两两互质的解是其的
 *基础解，他的全部解可由基础解乘上一个常数得到。其基础解的形式为
 *x = k^2-l^2, y = 2*k*l, z = k^2+l^2; 其中k和l互质，且奇偶性不同。
 *详细证明可参见论文PYTHAGOREAN TRIPLES
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 1000005
#define LEN 47000
int re[NUM];
static inline int
coprime(int a, int b)
{
	int t;
	while(a%b) {
		t = b;
		b = a%b;
		a = t;
	}
	return b;
}

int main()
{
	int i, k, l, n, m1, m2, m3;
	int a, b, c, p_cnt, t_cnt;
	while (scanf("%d", &n) == 1) {
		memset(re, 0, sizeof(int)*(n+1));
		p_cnt = t_cnt = 0;
		m1 = sqrt((float)n)+1;
		for(k=2; k<=m1; k++) {
			m2 = 1+sqrt((float)(n-k*k));
			if (m2>k) m2 = k;
			for(l=k%2+1; l<m2; l=l+2) {
				if (1 != coprime(k, l)) continue;
				p_cnt++;
				a = k*k-l*l;
				b = 2*k*l;
				c = k*k+l*l;
				m3 = n/c;
				for(i=1; i<=m3; i++) {
					re[i*a] = re[i*b] = re[i*c] = 1;
				}
			}
		}
		for(i=1; i<=n; i++) t_cnt += re[i];
		printf("%d %d\n", p_cnt, n-t_cnt);
	}
}