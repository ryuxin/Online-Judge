/*基础题。数学。由于极值左右导数会变号，对数列作差分，
 *当前差分的值与上一次不同时，则当前值就是一个局部极值
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 105

int main()
{
	int i, n, r=0, a, sat=0, oa, os = 0;
	scanf("%d %d\n", &n, &oa);
	for(i=n-1; i>0; i--) {
		scanf("%d", &a);
		sat = a - oa;
		if (sat * os < 0) r++;
		os = sat;
		oa = a;
	}
	printf("%d\n", r);
	return 0;
}