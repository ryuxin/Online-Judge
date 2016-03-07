/*基础题，深搜。枚举所有可以产生s[1]的情况，对每一
 *种情况，可以根据前面的状态和结果，确定下一个元素。
 *如已经检验过s[1..k]，就可以根据s[k+1]确定后面的
 *状态。最后判断是否可以产生s[n-1]和s[0]。
 *输入行后可能有空格！！
 *优化：204和51对应输入不变和输入取反，一定可行。
 *0和255只输出全0和全1，也可以直接判断，而且这是必
 *要的，考虑0 32 00000000000000000000000000000001
 *另外，在DFS中采用尾递归的优化。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 35
#define LEN 105
int n, autom[8], re[NUM];
char target[NUM+10];
static inline void Decode(int c)
{
	int i;
	for(i=0; i<8; i++)
		autom[i] = (c>>i) & 1;
}
static inline bool Validate(void)
{
	int c;
	c = 4*re[n-2]+2*re[n-1]+re[0];
	if (autom[c] != target[n-1]-'0')
		return false;
	c = 4*re[n-1]+2*re[0]+re[1];
	if (autom[c] != target[0]-'0')
		return false;
	return true;
}
static bool DFS(int k)
{
	int c, t;
	while (k<n) {
		if (k == n-1) return Validate();
		t = target[k]-'0';
		c = 4*re[k-1]+2*re[k];
		if (autom[c] == t) {
			re[k+1] = 0;
			if (DFS(k+1)) return true;
		}
		if (autom[c+1] == t) {
			re[++k] = 1;
			continue;
		}
		return false;
	}
}
static inline bool Backtrace(void)
{
	int i;
	for(i=0; i<8; i++) {
		if (target[1]-'0' != autom[i]) continue;
		re[0] = i>>2;
		re[1] = (i>>1) & 1;
		re[2] = i & 1;
		if (DFS(2)) return true;
	}
	return false;
}
int main()
{
	int i, code, l;
	while (gets(target)) {
		sscanf(target, "%d %d %s", &code, &n, target);
		if (code == 204 || code == 51 ||
			!code || code == 255) {
			if (code == 204 || code == 51) {
				printf("REACHABLE\n");
			} else {	
				l = 0;
				for(i=n-1; i>=0; i--) 
					l += (target[i]-'0');
				if (code == 0 ) {
					if (!l) printf("REACHABLE\n");
					else printf("GARDEN OF EDEN\n");
				} else {
					if (l == n) printf("REACHABLE\n");
					else printf("GARDEN OF EDEN\n");
				}
			}
			continue;
		}
		Decode(code);
		if (Backtrace()) printf("REACHABLE\n");
		else printf("GARDEN OF EDEN\n");
	}
	return 0;
}