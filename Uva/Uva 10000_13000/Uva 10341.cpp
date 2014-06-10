/*基础题。二分法解方程。从系数的符号可知，该函数单调递减。
  注意精度的处理，要用fabs，不是abs。*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
#define NUM 5
#define LEN 50
#define error 0.000000001
#define E 2.718281828459 
double p, q, r, s, t, u;
double compute(double x)
{
	return p*pow(E, -1*x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	double l, n, m, re;
	while(cin>>p>>q>>r>>s>>t>>u) {
		l = p+r+u;
		n = compute(1.0);
		if (l*n>0) printf("No solution\n");
		else {
			l = 0;
			n = 1.0;
			while(1) {
				m = (l+n)/2;
				re = compute(m);
				if (fabs(re)<=error) {
					printf("%.4lf\n", m);
					break;
				}
				if (re>0) l = m;
				else n = m;
			}
		}
	}
	return 0;
}