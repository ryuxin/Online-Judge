/*中等题，递归分治。a，b，c若不构成等差序列，则满足2b != a+c，
 *由于2b是偶数，若a和c是一奇一偶，则一定不能构成等差数列。所以
 *大体思路就是把偶数放在一边，把奇数放在另一边。先说两个引理。
 *1. 若一个序列满足题意，对它的所有元素都加上或乘上一个常数后，
 *所得的新序列仍然满足题意。
 *2. 若一个序列满足题意，它的任意子序列都满足题意，即删除若干
 *元素后的新序列仍然满足题意。
 *具体算法，将所有偶数放在一起，将所有奇数放在一起，递归处理
 *这两个子序列，最后将两个结果拼在一起，即为所求。
 *由引理1，在求完偶数的子序列后，可以将所有元素加一得到奇数的
 *子序列，这样省去递归处理奇数的子序列，复杂度降为O(n)。
 *这样会出现一个特殊情况。当n是偶数时，偶数的子序列比奇数的子
 *序列多一个数，所以加一后会有一个奇数大于n。所以在构造奇数子
 *序列时，要判断是否大于n，如果大于n，就跳过这个偶数。有引理2
 *知道，即使跳过一个元素，得到的序列仍满足题意。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 5005
int re[NUM];
static void Calc(int k)
{
	int i, j;
	if (k<2) {
		re[0] = 0;
		re[1] = 1;
		return ;
	}
	Calc(k>>1);
	for(i=0; i<=k>>1; i++) re[i] <<= 1;
	j = i;
	if (k&1) {
		for(i=0; i<=k>>1; i++)
			re[j++] = re[i]+1;
	} else {
		for(i=0; i<=k>>1; i++) {
			if (re[i]+1 > k) continue;
			re[j++] = re[i]+1;
		}
	}
}
int main()
{
	int i, n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		Calc((n-1)>>1);
		printf("%d:", n);
		for(i=0; i<=(n-1)>>1; i++) 
			printf(" %d", re[i]<<1);
		for(i=0; i<=(n-1)>>1; i++) {
			if ((re[i]<<1)+1 >= n) continue;
			printf(" %d", (re[i]<<1)+1);
		}
		printf("\n");
	}
	return 0;
}