/*入门题。贪心。给定一个数A， 将表示为另一个数X的各位数字的乘积。若A
 *包含大于9的质因数，则无解。要使X尽量小，就要使其位数尽量少，且高位数
 *字尽量小。因此，从9到2，依次用A去除，并将因子加入结果中，最后倒序输出
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 11
#define BIN 10
char re[NUM], len;
static inline unsigned int
Divide(unsigned int n, int d)
{
	while (n%d == 0) {
		re[len++] = d+'0';
		n /= d;
	}
	return n;
}
static inline int
Process(unsigned int n)
{
	int i, j;
	char t;
	len = 0;
	for(i=9; i>1; i--) {
		n = Divide(n, i);
	}
	if (n == 1) {
		if (!len) re[len++] = '1';
		re[len] = '\0';
		for(i=0, j=len-1; i<j; i++, j--) {
			t     = re[i];
			re[i] = re[j];
			re[j] = t;
		}
		return 0;
	} else return 1;
}
int main()
{
	int n, r;
	unsigned int t;
	scanf("%d", &n);
	while(n--) {
		scanf("%u", &t);
		r = Process(t);
		if (r) printf("-1\n");
		else printf("%s\n", re);
	}
}