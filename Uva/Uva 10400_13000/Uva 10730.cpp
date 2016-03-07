/*基础题，枚举。记录下每个数在数组中的位置。两层循环
 *分别枚举第一个数和第二个数，判断第三个数是否出现在
 *第二个数的后面，若是则构成等差数列。这样需要枚举n*n/2
 *对。可以对它进行一些改进。变成最小的数和公差。因为
 *最大数=最小数+2倍公差，切最大数小于n，所有公差的枚
 *举范围最大是n/2，最终只用n*n/4对。还不知道nlgn的算法*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 105
int a[NUM], index[NUM];
int main()
{
	int i, j, n, t;
	char c;
	while (1) {
begin:		
		scanf("%d", &n);
		if (!n) break;
		scanf("%c", &c);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			index[a[i]] = i;
		}
		for(i=n-3; i>=0; i--)
			for(j=1; i+2*j<n; j++) {
				t = index[i+2*j]-index[i+j];
				t *= index[i+j]-index[i];
				if (t>0) {
					printf("no\n");
					goto begin;
				}
			}
		printf("yes\n");
	}
	return 0;
}