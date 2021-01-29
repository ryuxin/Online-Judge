/*基础题。字符串，组合数学。题解中有多处讲得不甚清晰
 *详细。f(s, E)表示字符表E中，所有比s小的字符串的个
 *数。则答案为f(b, E(a)) - f(a, E(a)) - 1（E(x)表示
 *由字符串x构成的字符表）
 *计算f的大体思路，任意一个字符串t，若t[0] < s[0]，则
 *t后面的字符可以随便放；若t[0] = s[0]，则递归处理之
 *后的字符串。具体地：
 *f(s, E) = Sum{g(k, E-k) | k<s[0]} + f(s+1, E-s[0])
 *1. g(c, E)表示E中所有以c开始的字符串的个数，可根据
 *有重复的组合公式计算：
 *g(c, E) = (|E|-1)!/(n1!*n2!……(nc-1)!)，n1，n2..
 *为每个字符在字符表中的个数。实现时，可优化，先求出
 *T=(|E|-1)!/(n1!*n2!……)，则对任意的c，有
 *g(c, E) = T*(nc)!/(nc-1)!
 *2.第二项f(s+1, E-s[0])表示，第一个字符仍为s[0]，
 *这时递归求解后面的子串。
 *有一点需注意。f也可表示比s大的个数，但这样使得边界
 *情况的处理变得更麻烦。需额外判断b是否在E(a)中
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
#define LEN 26
#define MOD 1000000007
char src[NUM], dst[NUM];
int jichang[NUM], inv[NUM];
static inline int
n2p(int n, int p)
{
	int r=1;
	while (p) {
		long long t = n;
		if (p % 2 == 0) {
			n = (t*t) % MOD;
			p /= 2;
		} else {
			r = (r*t) % MOD;
			p -= 1;
		}
	}
	return r;
}
static inline int
calc(char *s, int l, int *c)
{
	long long t, tn;
	int i, j, r = 0;
	for(i=0; i<l; i++) {
		tn = jichang[l-i-1];
		for(j=0; j<LEN; j++) {
			tn = (tn*inv[c[j]]) % MOD;
		}
		for(j=0; j<s[i]-'a'; j++) {
			if (c[j] == 0) continue;
			t = (tn*jichang[c[j]]) % MOD;
			r = (r + t*inv[c[j]-1]) % MOD;
		}
		if (c[s[i]-'a'] == 0) break;
		c[s[i]-'a']--;
	}
	return r;
}
int main()
{
	int l, r, i, cnt1[LEN], cnt2[LEN];
	scanf("%s%s", src, dst);
	l = strlen(src);
	jichang[0] = jichang[1] = inv[0] = inv[1] = 1;
	for(i=2; i<=l; i++) {
		long long t = i;
		jichang[i] = (t*jichang[i-1]) % MOD;
		t = n2p(i, MOD-2);
		inv[i] = (t*inv[i-1]) % MOD;
	}
	memset(cnt1, 0, sizeof(cnt1));
	for(i=0; i<l; i++) cnt1[src[i]-'a']++;
	memcpy(cnt2, cnt1, sizeof(cnt1));
	r = calc(dst, l, cnt1);
	r = (r - calc(src, l, cnt2) - 1 + MOD) % MOD;
	printf("%d\n", r);
	return 0;
}