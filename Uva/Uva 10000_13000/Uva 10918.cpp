/*基础题。数学。设在3*n的格子中摆放的方法数为f(n)，在将其
 *左下角的格子删掉后所剩余的格子中摆放的方法数为g(n)。显然
 *n为奇数时，不存在可行的摆放方法，n只能是偶数。考虑
 *在3*n的格子中第一个方块的摆放，若其竖着放，则在下面的格
 *子只能横着放，此时在剩余的格子中有g(n-1)中可能的摆放方法；
 *若第一个横着放，考虑第二行的摆放。若其也是横着放，则剩余
 *的方法数为f(n-2)，若是竖着放，则和第一种情况对称，有g(n-1)
 *中方法。因此有f(n) = f(n-2)+2*g(n-1)。同样的方法考虑g(n)，
 *有g(n) = g(n-2)+f(n-1)，将g(n)带人，有
 *f(n) = 3f(n-2)+2f(n-4)+2f(n-6)+2f(2)+2g(1)
 *得f(n) = 4f(n-2)-f(n-4),且f(0) = 1, f(2) = 3
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 16
#define LEN 47000
int dp[NUM];
int main()
{
	int i, n;
	dp[0] = 1;
	dp[1] = 3;
	for(i=2; i<NUM; i++) dp[i] = 4*dp[i-1]-dp[i-2];
	while (scanf("%d", &n)) {
		if (n == -1) break;
		if (n%2) printf("0\n");
		else printf("%d\n", dp[n/2]);
	}
	return 0;
}