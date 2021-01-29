/*入门题。模拟。当k>=n-1时，最后取胜的一定是能力值最大的选
 *手，因为只有他才能赢了其他所有人。当k<n-1时，就按照题目
 *的要求进行模拟。 模拟时，若发现取胜的次数大于等于k，则
 *当前的选手就是答案；若模拟到最后一名选手，则当前获胜的
 *选手一定是最大值，且他会一直保持胜利，答案也是当前选手。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 505
#define LEN 3
int p[NUM];
int main()
{
	int n, i, win=0, j;
	long long int k;
	scanf("%d %lld %d %d", &n, &k, &p[0], &p[1]);
	for(i=2; i<n; i++) scanf("%d", &p[i]);
	if (k >= (long long int)(n-1) || p[0] == n) {
		printf("%d\n", n);
	} else {
		for(i=0, j=1; i<n-1 && j<n; j++) {
			if (p[i] > p[j]) {
				win++;
				if ((long long int)win >= k) break;
			} else {
				win = 1;
				i = j;
			}
		}
		printf("%d\n", p[i]);
	}
	return 0;
}