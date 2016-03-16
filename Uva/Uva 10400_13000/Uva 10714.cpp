/*中等题。模拟+贪心。同Uva 10881类似，若两个蚂蚁AB相遇，则它们
 *交换速度，可以看做A穿过B继续向前，所以这个虚拟的A掉下木板的
 *时间是x或者L-x，x是蚂蚁的位置，L是木板的长度。所有蚂蚁的这两个
 *值中最大的就是最晚的掉落时间，而较小者的最大值就是最早的时间
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 10005
#define LEN 10
int main()
{
	int c, l, n, i, m1, m2, a1, a2;
	scanf("%d", &c);
	while(c--) {
		scanf("%d%d", &l, &n);
		m1 = m2 = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a1);
			a2 = l-a1;
			if (a1>a2) {
				if (a2>m1) m1 = a2;
				if (a1>m2) m2 = a1;
			} else {
				if (a1>m1) m1 = a1;
				if (a2>m2) m2 = a2;
			}
		}
		printf("%d %d\n", m1, m2);
	}
	return 0;
}