/*基础题。数学。-2为基数和其他数作为基数没有差别，
 *都是不断取余，相减，移位来确定每一位的数字。但
 *由于涉及负数取余，要了解C预言的标准：对任意a，
 *b，C保证下式成立a = (a/b)*b+a%b*/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 505
#define LEN 35
char re[LEN];
static inline void solve(int k)
{
	int m = LEN-2, r;
	while (k) {
		r = ((k%-2)+2)%2;
		k -= r;
		k /= -2;
		re[m--] = r+'0';
	}
	printf("%s", re+m+1);
}
int main()
{
	int i, n, t;
	re[LEN-1] = '\0';
	scanf("%d", &n);
	for(i=1;i<=n; i++) {
		scanf("%d", &t);
		printf("Case #%d: ", i);
		if (!t) printf("0");
		else solve(t);
		printf("\n");
	}
	return 0;
}