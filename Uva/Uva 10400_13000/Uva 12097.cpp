/*入门题。二分。给定n个蛋糕和m个人，每个人能得到的最大块就是
 *蛋糕总量除以m，最小就是最大的蛋糕除以m。此后二分搜索，判断
 *当前的大小是否够分。判断时，计算每个蛋糕可以分出几块，最后
 *总数大于等于m，就够分。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10002
#define LEN 25
int n, f, ra[NUM];
double PI;
static inline bool check(double a)
{
	int i, s = 0;
	for(i=0; i<n; i++) {
		s += (int)(ra[i]*PI/a);
		if (s>=f) break;
	}
	return s >= f;
}
static inline double Binary_search(double a, double b)
{
	double e = 0.0000001, m;
	while(b-a > e) {
		m = (a+b)/2;
		if (check(m)) a = m;
		else b = m;
	}
	return a;
}
int main()
{
	int c, i, m;
	long long int sum;
	PI = acos(-1.0);
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &n, &f);
		f++;
		sum = m = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &ra[i]);
			ra[i] = ra[i]*ra[i];
			sum += (long long int)ra[i];
			if (ra[i] > m) m = ra[i];
		}
		printf("%.4f\n", Binary_search((double)m*PI/f, (double)sum*PI/f));
	}
	return 0;
}