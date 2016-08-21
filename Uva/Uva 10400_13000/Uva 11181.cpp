/*入门题。数学，概率。设事件Ai为第i个人买了东西，事件B为n个人中有r个人买了东西。已知Ai的先验
 *概率，求B发生后Ai的后验概率。由贝叶斯公式：P(Ai|B) = P(B|Ai)*P(Ai)/P(B)，其中P(B|Ai)为除
 *第i个人外，剩余人买了r-1个东西的概率。*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NUM 25
#define LEN 26
double p[NUM], tot, re[NUM];
static inline void swap(double *a, double *b) {	double c = *a; *a = *b;	*b = c; }
static void DFS(int s, int e, int r, double v)
{
	int i;
	while(1) {
		if (e-s == r || !r) {
			if (r) for(i=s; i<e; i++) v *= p[i];
			else for(i=s; i<e; i++) v *= (1.0-p[i]);
			tot += v;
			return ;
		}
		DFS(s+1, e, r-1, v*p[s]);
		v *= (1.0-p[s++]);
	}
}
int main()
{
	int n, r, i, c=1;
	double t1, t2;
	while(scanf("%d%d", &n, &r)) {
		if (!n && !r) break;
		for(i=0; i<n; i++) scanf("%lf", &p[i]);
		if (!r) {
			for(i=0; i<n; i++) re[i] = 0;
		} else if (r == n) {
			for(i=0; i<n; i++) re[i] = 1.0;
		} else {
			tot = 0;
			DFS(0, n, r, 1);
			t1 = tot;
			for(i=0; i<n; i++) {
				swap(&p[0], &p[i]);
				tot = 0;
				DFS(1, n, r-1, 1);
				t2 = tot;
				swap(&p[0], &p[i]);
				re[i] = p[i]*t2/t1;
			}
		}
		printf("Case %d:\n", c++);
		for (i=0; i<n; i++) printf("%.6lf\n", re[i]);
	}
	return 0;
}