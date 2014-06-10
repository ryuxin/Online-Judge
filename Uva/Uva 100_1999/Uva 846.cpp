/*简单题。贪心+数学。为了尽快到达，就要保证每一步都尽量的大。但是到终点时，速度必须是1，且每一
  步都只能比前一步大一或小一，所以速度不能一直增大，否则没等速度减小到1时，就已经到达终点了。
  设最大速度是n，则满足2*n*(n-1)/2+n<=d, d为距离。剩余的路程则应以最大速度完成*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
	int t, x, y, l, n, r;
	scanf("%d", &t);
	while(t--) {
		cin>>x>>y;
		if (x == y) {
			printf("0\n");
			continue;
		}
		l = y-x;
		n = sqrt((double)l);        //最大速度
		l = n*n;
		l = y-x-l;                  //剩余的距离
		r = 2*(n-1)+1+l/n;          
		l = l-n*(l/n);             //剩余的距离，可能不能被n整除
		if (l>0)                   //此时余下的距离一定可以用一
			r++;                   //个小于n的速度一步完成
		printf("%d\n", r);
	}
	return 0;
}