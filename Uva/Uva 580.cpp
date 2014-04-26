// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*基础题。递推。枚举前三个元素。当第一个是L，方法数是f(n-1);前两个是UL，
  方法数是f(n-2), 前三个是UUL，方法数是f(n-3)。前三个是UUU，方法数是
  2^n-3。所以f(n) = f(n-1)+f(n-2)+f(n-3)+2^n-3
  */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define LEN 32
int main()
{
	int f[LEN], i, t2, n = 0;
	f[0] = f[1] = f[2] = 0;
	t2 = 1;
	for(i=3; i<LEN; i++) {
		f[i] = f[i-1]+f[i-2]+f[i-3]+t2;
		t2 = t2*2;
	}
	while (scanf("%d", &n)>0) {
		if (n == 0) break;
		printf("%d\n", f[n]);
	}
	return 0;
}