/*入门题。此题最好是利用二次方程求解，但由于精度问题，太恶心了，就老老实实的模拟了。
另外，要明白题目的意思，以及特殊情况。
1.只有当高度严格大于井的高度时，才算成功。同理，当下降后的高度严格小于0时，才算失败。
2.当每天上升的高度减小到0以后，就一直是0.就是说，不会向上爬一个负数。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    double h, u, d, f, c;
	int t;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f)>0) {
        if(h == 0)
            break;
        f = u*f/100;
		t = 1;
		c = 0;
		while(1) {
			c = c+u;
			if(c>h) {
				printf("success on day %d\n", t);
				break;
			}
			c = c-d;
			if(c<0) {
				printf("failure on day %d\n", t);
				break;
			}
			u = u-f;
			if(u<0)
				u = 0;
			t++;
		}
    }
    return 0;
}

