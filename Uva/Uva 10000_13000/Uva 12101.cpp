/*基础题，宽搜。先用筛法求出四位数中的素数。
 *从第一个数开始，每次改变一位，进行宽搜。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 10000
#define LEN 105
bool is_prime[NUM];
int q[NUM/2], re[NUM];
int a, b, c, h, t;
void mark_prime(void)
{
	int i=2, j;
	is_prime[2] = true;
	for(i=1; i<NUM; i+=2) is_prime[i] = true;
	for(i=3; i<NUM; i+=2) {
		if (is_prime[i]) {
			for(j=2; ; j++) {
				if (j*i >= NUM) break;
				is_prime[j*i] = false;
			}
		}
	}
}
bool BFS(int s)
{
	int digit[4], sum[4], i, j, cur;
	int base = re[s], l = 1;
	h = (h+1)%NUM;
	for(i=0; i<4; i++) {
		digit[i] = s%10;
		s = s/10;
	}
	sum[0] = 1000*digit[3]+100*digit[2]+10*digit[1];
	sum[1] = 1000*digit[3]+100*digit[2]+digit[0];
	sum[2] = 1000*digit[3]+10*digit[1]+digit[0];
	sum[3] = 100*digit[2]+10*digit[1]+digit[0];
	for(i=0; i<4; i++) {
		for(j=0; j<=9; j++) {
			if (i == 3 && j == 0) continue;
			cur = j*l+sum[i];
			if (!is_prime[cur]) continue;
			if (re[cur]>=0) continue;
			q[t] = cur;
			t = (t+1)%NUM;
			re[cur] = 1+base;
			if (cur == b) return true;
		}
		l *= 10;
	}
	return false;
}
int main()
{
	mark_prime();
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &a, &b);
		if (a == b) {
			printf("0\n");
			continue;
		}
		memset(re, -1, sizeof(re));
		h = t = 0;
		q[t++] = a;
		re[a] = 0;
		while(h != t) {
			if (BFS(q[h])) break;
		}
		if (re[b] == -1) printf("Impossible\n");
		else printf("%d\n", re[b]);
	}
	return 0;
}