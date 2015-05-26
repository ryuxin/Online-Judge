#include "ryx_bignum.h"
/*基础题。大整数操作。直观的思路就是二分枚举，用大整数乘幂*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
char num[105];
int main()
{
	int n, l, r, m, t, re;
	BigNum A, B, C;
	while(scanf("%d", &n)>0) {
		cin>>num;
		StingtoBigNum(num, &A);
		l = 1;
		m = 101/n+1;
		if (m>9) m = 9; 
		r = pow(10.0, m);
		re = 0;
		while (l<=r) {
			m = (l+r)/2;
			LinttoBigNum(m, &B);
			Initial(&C);
			Unsign_exp(&B, n, &C);
			t = Unsign_comp(&A, &C);
			if (t == 0) {
				re = m;
				break;
			}
			if (t>0) {     //若题目的数据无解，则向下取整
				if (m>re) re = m;
				l = m+1;
			}
			else
				r = m-1;
		}
		printf("%d\n", re);
	}
	return 0;
}