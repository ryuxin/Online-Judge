/*基础题。数学。对于第k个灯，第i次他被按的充要条件
  是i|n，i从1到n。所以一个被按的次数就是他所有因子
  的个数。完全平方数有奇数个因子，其他的数有偶数个
  因子。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 1005
#define LEN 100
int main()
{
	unsigned int n, t;
	while(scanf("%d", &n)>0) {
		if (n == 0) break;
		t = sqrt((double)n);
		if (t*t == n) printf("yes\n");
		else		  printf("no\n");
	}
	return 0;
}