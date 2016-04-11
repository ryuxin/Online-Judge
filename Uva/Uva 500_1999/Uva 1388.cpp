/*入门题。贪心，数学。首选要确定加完塑像后，所有塑像的安放位置；然后
 *对于这种安放，求出最小的移动距离。先来看第二步。设调整前，两个相邻
 *塑像距离是n，调整后为m，则有n > m。移动方法就是把每个塑像都移动到
 *离它最近的新的安放点。此方法的正确性依赖于没有两个塑像对应同一个最
 *近点。证明：对于一个塑像p，它一定位于两个新安放点p1p2的中间，所以
 *p和它的最近点距离小于|p1p2|/2 = m/2。若p'也对应同一个最近点，则p和
 *p'的距离<m/2+m/2 < m。与 n > m 矛盾。
 *对于新安放点的确定，有如下结论。新的安放点至少有一个和旧的点重合。
 *证明：若最优方案中没有重合的点，则设最近点在其顺时针方向的塑像构成
 *集合A，其个数为a，在逆时针方向的为集合B，个数为b。若a大于b，将所有
 *新的安放点逆时针转动，转动距离为A中最小距离c。转动后，A中的距离都减
 *少c，而B中每个塑像的移动距离至多增加c，由于a > b，最终总的移动距离
 *还是减少了，且A中至少有一个塑像的新安放点和旧的重合。
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;

#define NUM 6
#define LEN 4
int main()
{
	int i, n, m, r, c, t;
	float len = 10000.0;
	while(EOF != scanf("%d %d", &n, &m)) {
		r  = 0;
		m += n;
		for(i=1; i<n; i++) {
			c = i*m;
			t = c/n;
			if (c-t*n < (t+1)*n-c) r += (c-t*n);
			else r += ((t+1)*n-c);
		}
		printf("%.4f\n", len*(float)r/(float)(n*m));
	}
	return 0;
}