/*基础题。深搜+康托展开。每次交换两个逆序的相邻元素，交换的总次数就是最少的。
  由于n<5，可以直接暴搜。n大一点的话，可以保存搜索过的数组状态，用康托展开
  对数组进行编码。貌似本题的最坏情况要大于n！，康托展开还是值得的。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 6
#define LEN 35
int nf[NUM] = {0, 1, 2, 6, 24, 120};
int data[NUM], order[NUM], n, re[130];
int Encode()                      //康托展开，将n个数的排列与1-n！一一对应
{
	int t[NUM] = {0}, i, r = 0, j, s;
	for(i=0; i<n; i++) {
		s = 0;
		for(j=0; j<n; j++) if (t[j] == 0 && j<order[i]) s++;
		t[order[i]] = 1;
		r += s*nf[n-1-i];
	}
	return r;
}
int Calc()
{
	int i, t, s, r = 0, l;
	t = Encode();
	if (re[t] == -1) {
		for(i=1; i<n; i++) {
			if (data[order[i-1]]<=data[order[i]]) continue;
			s = order[i-1];
			order[i-1] = order[i];
			order[i] = s;
			l = Calc();
			if (l == 0) l++;
			r += l;
			order[i] = order[i-1];
			order[i-1] = s;
		}
		re[t] = r;
	}
	return re[t];
}
int main()
{
	int i, r, c = 1;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		for(i=0; i<n; i++) {
			scanf("%d", &data[i]);
			order[i] = i;
		}
		memset(re, -1, sizeof(re));
		r = Calc();
		printf("There are %d swap maps for input data set %d.\n", r, c++);
	}
	return 0;
}