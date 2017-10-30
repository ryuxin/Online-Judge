/*入门题。基数排序。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 3
int ages[NUM];
static inline void
fastscanf4(int n, int *p)
{
	int i=0, j, a, b, c, d;
	j = n%4;
	for(i=0; i<j; i++) {
		scanf("%d", &a);
		p[a]++;
	}
	for(; i<n; i += 4) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		p[a]++;
		p[b]++;
		p[c]++;
		p[d]++;
	}
}
static inline void
fastprint4(int n, int p)
{
	int i = 0, j;
	j = n%4;
	for(i=0; i<j; i++) printf(" %d", p);
	for(; i<n; i += 4) printf(" %d %d %d %d", p, p, p, p);
}
int main()
{
	int i, n, a, b;
	while(scanf("%d", &n)) {
		if (!n) break;
		memset(ages, 0, sizeof(ages));
		fastscanf4(n, ages);
		i=1;
		for(a=1; a<NUM; a++) {
			if (i && ages[a]) {
				i = 0;
				printf("%d", a);
				fastprint4(ages[a]-1, a);
			} else fastprint4(ages[a], a);
		}
		printf("\n");
	}
	return 0;
}