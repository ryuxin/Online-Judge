/*基础题。递归。题解很清楚直观。要培养对指数增长的敏感度。看到
 *f(n)是O(2^n)量级，但k最大才是10^18，即应对n的大小有合理估计
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

#define NUM 100005
#define LEN (1LL << 60)
char *s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
char *s10 = "What are you doing while sending \"";
char *s11 = "\"? Are you busy? Will you send \"";
char *s12 = "\"?";
long long len[NUM];
int l10, l11, l12;
static inline char
calc(int n, long long k)
{
	if (k>len[n]) return '.';
	while (n>0) {
		if (k<=l10) return s10[k-1];
		else if (k<=l10+len[n-1]) {
			k -= l10;
			n--;
		} else if (k<=l10+len[n-1]+l11) {
			return s11[k-l10-len[n-1]-1];
		} else if (k<=l10+len[n-1]*2+l11) {
			k -= (l10+len[n-1]+l11);
			n--;
		} else {
			return s12[k-l10-len[n-1]*2-l11-1];
		}
	}
	return s0[k-1];
}
int main()
{
	int q, i, n;
	long long k;
	l10 = strlen(s10);
	l11 = strlen(s11);
	l12 = strlen(s12);
	for(len[0]=strlen(s0), i=1; ; i++) {
		len[i] = 2*len[i-1] + l10 + l11 + l12;
		if (len[i] >= LEN) break;
	}
	for(i=i+1; i<NUM; i++) len[i] = len[i-1];
	scanf("%d", &q);
	while(q--) {
		scanf("%d%lld", &n, &k);
		char c = calc(n, k);
		printf("%c", c);
	}
	printf("\n");
	return 0;
}