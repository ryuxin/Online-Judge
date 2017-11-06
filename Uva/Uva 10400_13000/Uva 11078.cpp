/*入门题。max{ai - aj | 0<= i <j} = max{ai | 0<= i <j} - aj.
 *一边输入，一边维护已经输入的最大值（max{ai | 0<= i <j}）。
 *这样就知道基于aj的最大值，再从这些值取最大，即为结果。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 105
#define LEN 3
int main()
{
	int n, ret, mmax, i, a, b, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &mmax, &a);
		ret = mmax - a;
		for(i=n-2; i>0; i--) {
			if (a > mmax) mmax = a;
			scanf("%d", &a);
			b = mmax - a;
			if (b > ret) ret = b;
		}
		printf("%d\n", ret);
	}
	return 0;
}