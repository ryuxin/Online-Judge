/*基础题。数论，扩展的欧几里得算法。本题可建模为求解
 *不定方程ax+by=c。且其解必须为两个非负整数。
 *方程有解当且仅当c能整除a，b的最大公约数d，且其通解为
 *x = x0+b/d*t, y = y0-a/d*t, (x0,y0)为一特解，t为任意整数。
 *必要性显然。下证充分性。设u=a/d, v=b/d，可知u，v互质。对
 *任意解(x,y)，有dux+dvy = c, 即ux+vy = c/d = m。对任意
 *(x1,y1)和(x2,y2)，有u(x1-x2)+v(y1-y2)=0，因为u,v互质，所以
 *(x1-x2)|v, (y1-y2)|u，即x1=x2+vt, y1=y2-ut，充分性得证。*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define NUM 302
#define LEN 45
/*给定a,b，返回a,b的最大公约数gcd(a, b) = c，且
 *返回x,y满足ax+by=c。该算法保持下列循环不变式
 * gcd(a. b) = gcd(t0[2], t1[2])
 * a*t1[0]+b*t1[1]=t1[2]
 * a*t2[0]+b*t2[1]=t2[2]
 *所以当t1[2]整除t2[2]时，t2[2] = gcd(t0[2], t1[2]) = gcd(a. b)
 */
static inline long long int
EXP_Eulid(long long int a, long long int b, 
		  long long int *x, long long int *y)
{
	long long int a1[3] = {0, 1, 0}, *t1;
	long long int a2[3] = {1, 0, 0}, *t;
	long long int r, n, a3[3], *t2, *t3;
	a1[2] = b; a2[2] = a;
	t1 = a1; t2 = a2; t3 = a3;
	while(1) {
		t3[2] = t1[2]%t2[2];
		if (!t3[2]) {
			*x = t2[0];
			*y = t2[1];
			return t2[2];
		}
		n = t1[2]/t2[2];
		t3[0] = t1[0]-n*t2[0]; 
		t3[1] = t1[1]-n*t2[1];
		t  = t1; t1 = t2; 
		t2 = t3; t3 = t;
	}
}
int main()
{
	long long int c1, n1, c2, n2;
	long long int a, b, c, n;
	long long int k, l, h, x, y;
	while (1) {
		scanf("%lld", &n);
		if (!n) break;
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		c = EXP_Eulid(n1, n2, &a, &b);
		if (n%c) printf("failed\n");   //无解
		else {
			k = n/c;
			a = a*k;
			l = -1*a/(n2/c);
			if (a+n2/c*l < 0) l++;
			b = k*b;
			h = b/(n1/c);
			if (b-n1/c*h < 0) h--;
			if (h<l) printf("failed\n");  //无非负整数解
			else {
				x = c1*a+c2*b;
				y = n2/c*c1-n1/c*c2;
				if (y>=0) h = l;
				printf("%lld %lld\n", a+n2/c*h, b-n1/c*h);
			}
		}
	}
	return 0;
}