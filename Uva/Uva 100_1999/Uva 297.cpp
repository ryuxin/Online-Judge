/*基础题。数据结构。树。前序遍历两个树，把对应的子树相加。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 70
#define LEN 35
char d1[NUM], d2[NUM];
int p1, p2;
int Travse(char *d, int h)     //遍历d的当前子树，高度为h
{
	int *p, r = 0;
	if (d == d1) p = &p1;
	else p = &p2;
	(*p) = (*p)+1;
	if (d[(*p)-1] == 'p') {
		r += Travse(d, h/2);
		r += Travse(d, h/2);
		r += Travse(d, h/2);
		r += Travse(d, h/2);
	}
	else if (d[(*p)-1] == 'f') r = h*h;
	return r;
}
int Cacl(int d)         //计算以a和b为根的两个树的和,树的高度是lg(d)
{
	int r = 0;
	if (d1[p1] != 'p') {
		r = Travse(d2, d);
		return d1[p1++] == 'e'? r:d*d;
	}
	if (d2[p2] != 'p') {
		r = Travse(d1, d);
		return d2[p2++] == 'e'? r:d*d;
	}
	p1++;
	p2++;
	r += Cacl(d/2);
	r += Cacl(d/2);
	r += Cacl(d/2);
	r += Cacl(d/2);
	return r;
}
int main()
{
	int c, r;
	scanf("%d", &c);
	while (c--) {
		scanf("%s%s", d1, d2);
		p1 = p2 = 0;
		r = Cacl(32);
		printf("There are %d black pixels.\n", r);
	}
	return 0;
}