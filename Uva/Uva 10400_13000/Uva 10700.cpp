/*基础题。贪心。求最大值时，先计算所有加法，再计算乘法。最小值，先计算乘法，再计算加法。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define NUM 15
#define LEN 5
long long int s1[NUM], s2[NUM], t1, t2;
char temp[LEN];
int main()
{
	long long int i, n, ma, mi;
	char sign;
	scanf("%d", &n);
	while(n--) {
		ma = 1;
		mi = 0;
		scanf("%llu", &i);
		s1[0] = s2[0] = i;
		t1 = t2 = 1;
		scanf("%c", &sign);
		while(sign != '\n') {
			scanf("%llu", &i);
			if (sign == '+') {
				s1[t1-1] += i;
				s2[t2++] = i;
			}
			else if(sign == '*') {
				s1[t1++] = i;
				s2[t2-1] *= i;
			}
			scanf("%c", &sign);
		}
		for(i=0; i<t1; i++) ma *= s1[i];
		for(i=0; i<t2; i++) mi += s2[i];
		printf("The maximum and minimum are %llu and %llu.\n", ma, mi);
	}
	return 0;
}