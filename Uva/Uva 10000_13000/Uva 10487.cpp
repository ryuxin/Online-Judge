/*基础题。排序+递推。先排序。考虑s = a1+an，s1 = a2+an, s2 = a1+an-1,
  用s表示两数之和与目标的差的绝对值。
  1. s1<s s2<s；不可能
  2. s1<s s2>s, 此时可以排除所有与a1的组合
  3. s1>s s2<s, 此时可以排除所有与an的组合
  4. 计算(a2, an-1)之间的最小值，与s比较，较小者即为所求。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 1005
int data[NUM], q;
int comp(const void *a1, const void *a2)
{
	int *p1, *p2;
	p1 = (int *)a1;
	p2 = (int *)a2;
	return (*p1)-(*p2);
}
int Query(int s, int t)
{
	int s1, s2, s3, ss;
	if (s>=t) return 1000000;
	while(s+1<t) {
		s1 = abs(data[s+1]+data[t]-q);
		s2 = abs(data[s]+data[t-1]-q);
		ss = abs(data[s]+data[t]-q);
		if (s1<ss) s =s+1;
		else if (s2<ss) t = t-1;
		else {
			s3 = Query(s+1, t-1);
			if (abs(q-s3)<ss) return s3;
			return data[s]+data[t];
		}
	}
	return data[s]+data[t];
}
int main()
{
	int n, m, i, a, c = 0;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		c++;
		for(i=0; i<n; i++) scanf("%d", &data[i]);
		qsort(data, n, sizeof(int), comp);
		printf("Case %d:\n", c);
		scanf("%d", &m);
		for(i=0; i<m; i++) {
			scanf("%d", &q);
			a = Query(0, n-1);
			printf("Closest sum to %d is %d.\n", q, a);
		}
	}
	return 0;
}